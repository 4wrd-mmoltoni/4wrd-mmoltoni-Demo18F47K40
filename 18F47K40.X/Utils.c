#include <string.h>
#include "Utils.h"
#include "DobleFN_Def.h"
#include "Function485.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/memory.h"
#include "485.h"
#include "algorithm.h"


uint8_t     ResetReq = 0;
ERRORType   ErrorVect;


static const uint8_t Display[] = {
    0x6F,       //0 ZERO
    0x06,
    0xAB,
    0x8F,
    0xC6,       //4
    0xCD,
    0xED,       //6
    0x07,
    0xFF,       //8
    0xCF,

    0xE7,       //A (10!)
    0xE9,       //E
    0xE3,       //P
    0x6E,       //U 
    
    0x00        //OFF
};

void DisplayA(uint8_t val)
{
    val %= sizeof(Display);
    LATA = Display[val];
}

void DisplayB(uint8_t val)
{
    val %= sizeof(Display);
    LATD = Display[val];
}

void ShowAddr(int val)
{
    uint8_t i, d;
    d = val/10;
    i = val%10;
    DisplayA(d);
    DisplayB(i);
}

void InitVars(void)
{
    ResetReq = 0;
    ErrorVect.w = 0;
    Init_Usart485();
    
    //Case of MDB_addr! 
    uint8_t resetReg = PCON0;
    ERRORType temp;
    temp.w = 0;
    temp.bProcessor.b = resetReg;
    
    ErrorVect.bProcessor.b = resetReg;

    if (PCON0 == 0x34 || PCON0 == 0x3C)              //situaz. normale, ho acceso il sistema!
    {
        BAPTESIM_NOK;                   //�ncora tirata, situazione da battezzare
        MDB_addr = '0';                 //Ho acceso: l'indirizzo � NULLO (per battesimo
        return;
    }
    //else
    if (PCON0bits.NOT_BOR)          //Brown-out    
    {
        BAPTESIM_NOK;                   //�ncora tirata, situazione da battezzare
        MDB_addr = '0';                 //Ho acceso: l'indirizzo � NULLO (per battesimo
        PCON0bits.NOT_BOR = 1;          //erase bad situation
        return;
    }
    
    if (PCON0bits.NOT_POR ||        //Power-on Reset Status bit
        PCON0bits.NOT_RMCLR ||      //MCLR Reset Flag bit
        PCON0bits.NOT_WDTWV ||      //WDT Reset Flag bit
        PCON0bits.NOT_RI            //RESET Instruction Flag bit
        )
    {
        BAPTESIM_OK;                   //�ncora rilasciata, battezzato!
        uint8_t n = ReadEEpromMDB_Addr();
        if (n >= 0 && n < 20)
            MDB_addr = '0' + n;
        
        return;
    }
    return;
}

void WriteEEpromMDB_Addr(uint8_t val)
{
	DATAEE_WriteByte(MODBUSADDRES_EEPROM_ADDR, val);
    NVMCON1bits.NVMREG = 2;
}

uint8_t ReadEEpromMDB_Addr(void)
{
	return DATAEE_ReadByte(MODBUSADDRES_EEPROM_ADDR);
    NVMCON1bits.NVMREG = 2;
}


void WriteConfigSTR(const uint8_t *buf, uint8_t len)
{
    uint16_t addr = START_CONFIG_STR_ADDR;
    if (len > 64)
        len = 64;

    for(uint8_t n = 0; n < len; n++)
        DATAEE_WriteByte(addr++, buf[n]);
    
    NVMCON1bits.NVMREG = 2;
}

void ReadConfigSTR(uint8_t *buf, uint8_t len)
{
    uint16_t addr = START_CONFIG_STR_ADDR;
    if (len > 64)
        len = 64;

    for (uint8_t n = 0; n < len; n++)
        buf[n] = DATAEE_ReadByte(addr++);
    
    NVMCON1bits.NVMREG = 2;
}


void ResetRequest(void)
{
	ResetReq = 1;
}

void ResetReqExecute(void)
{
	if (ResetReq)
		if (Usart485.tx_pointer == Usart485.tx_lenbuf)
            if (EUSART1_is_tx_done())
            {
                RESET();
                NVMCON1bits.NVMREG = 2;
            }
}

uint8_t     nibbleToAsciiHex (uint8_t val)
{
    if (val >= 0 && val <= 9)
        return val + '0';
    if (val >= 10 && val <= 15)
        return (val-10) + 'A';
}


void testfnc()
{
    //test functions...
    
    //Write a 128 byte buffer*2
    uint32_t addr = 0x0000;
    uint32_t n = 0;
    uint8_t b;
    uint16_t w;
    //addr -= 256;
    
    IO_RE2_SetLow();
    
    //IO_RE2_SetHigh();
    //FLASH_EraseBlock(addr);
    //FLASH_EraseBlock(addr+128);
    IO_RE2_SetLow();
    uint8_t buf[256] = {0};
    
    __delay_ms(1);
    memset(buf, 1, sizeof(buf));
    
    addr = 0;
    IO_RE2_SetHigh();
    
    //CRC162(NULL, 0, 1);
    uint16_t crc16;
    for (n = addr; n <= 0xFFFF; n += 256)
    {
        //FLASH_ReadSector(buf, n);
        FLASH_ReadSector64k(buf, n);
        crc16 = CRC162(buf, 256, 0);
    }
    
    /*for (n = 0; n < 256; n++)
    {
        buf[n] = FLASH_ReadByte(addr+n);
        //w = FLASH_ReadWord(n);
        if (w != 0xFFFF)
            w = 0;
    } 
    */    
    IO_RE2_SetLow();
    
    for (n = 0; n< 255; n++)
        if (buf[n] == 0)
            buf[n] = 55; 
}




void FLASH_ReadSector64k(uint8_t *buf, uint16_t flashAddr)
{
    uint16_t n;
    
    NVMCON1bits.NVMREG = 2;
    //TBLPTRU = (uint8_t)((flashAddr & 0x00FF0000) >> 16);
    TBLPTRU = 0;
    TBLPTRH = (uint8_t)((flashAddr)>> 8);
    TBLPTRL = 0;

    //asm("TBLRD");
    for (n = 0; n < 256; n++)
    {
        asm("TBLRD*+");
        *(buf++) = (TABLAT);
        //TBLPTRL++;
    }
    //Restore the interrupts
    //INTCONbits.GIE = GIEBitValue;    
}


void FLASH_ReadSector(uint8_t *buf, uint32_t flashAddr)
{
    uint16_t val;
    uint16_t n;
    
    //uint8_t GIEBitValue = INTCONbits.GIE;
    //Disable all interrupt
    //INTCONbits.GIE = 0;
    
    NVMCON1bits.NVMREG = 2;
    TBLPTRU = (uint8_t)((flashAddr & 0x00FF0000) >> 16);
    TBLPTRH = (uint8_t)((flashAddr & 0x0000FF00)>> 8);
    TBLPTRL = 0;

    //asm("TBLRD");
    for (n = 0; n < 256; n++)
    {
        asm("TBLRD");
        *(buf++) = (TABLAT);
        TBLPTRL++;
    }
    //Restore the interrupts
    //INTCONbits.GIE = GIEBitValue;    
}
