#include <string.h>
#include "Utils.h"
#include "DobleFN_Def.h"
#include "Function485.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/memory.h"
#include "485.h"


uint8_t     ResetReq = 0;
ERRORType   ErrorVect;


uint8_t Display[] = {
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
    //if (d == 0) d = sizeof(Display)-1;  //turn off
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
        BAPTESIM_NOK;                   //àncora tirata, situazione da battezzare
        MDB_addr = '0';                 //Ho acceso: l'indirizzo è NULLO (per battesimo
        return;
    }
    //else
    if (PCON0bits.NOT_BOR)          //Brown-out    
    {
        BAPTESIM_NOK;                   //àncora tirata, situazione da battezzare
        MDB_addr = '0';                 //Ho acceso: l'indirizzo è NULLO (per battesimo
        PCON0bits.NOT_BOR = 1;          //erase bad situation
        return;
    }
    
    if (PCON0bits.NOT_POR ||        //Power-on Reset Status bit
        PCON0bits.NOT_RMCLR ||      //MCLR Reset Flag bit
        PCON0bits.NOT_WDTWV ||      //WDT Reset Flag bit
        PCON0bits.NOT_RI            //RESET Instruction Flag bit
        )
    {
        BAPTESIM_OK;                   //àncora rilasciata, battezzato!
        MDB_addr = ReadEEpromMDB_Addr();
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
                RESET();
}

void Handle485Dir(void)
{
#if 0
    if (direzione TX == 1)
        if (Usart485.tx_pointer == Usart485.tx_lenbuf)
            if (EUSART1_is_tx_done())
                
      
#endif     
}

/* 
 *  MISURE! 
 */

// COnverte da misura a microvolt * 100 (decimo di mV)
int32_t    ConvertMeasure(uint16_t raw)
{
    float f = HundredMICROVOLT_STEP_f * (float)raw;
    return (int32_t)f;
}

void ConvertSingleMeasureToStr(uint16_t raw, uint8_t* str)
{
    uint32_t val = ConvertMeasure(raw);
    sprintf(str, "%06ld", val);    
}


/*
 * Errore del C di Microchip!
 * Non funziona con la striga sprintf(str, "%06d %06d %06d %06d %06d %06d ", val[0], val[1], val[2], val[3], val[4], val[5]);
 *  (ne fa uno si ed uno no!)
 * neppure con strcat e sprintf(str, "%06u ", val[0]);
 * non sistema correttamente gli interi a 32 bit, li tratta come 16 e siccome sono unsigned sbaglia :-( 
 */

void ConvertMeasureToStr(uint16_t* raw, char* str)
{
    int32_t val[6];
    uint8_t n;    
    for (n = 0; n < 6; n++)
        val[n] = ConvertMeasure(raw[n]);
    sprintf(str, "%06ld %06ld %06ld %06ld %06ld %06ld ", val[0], val[1], val[2], val[3], val[4], val[5]);    
}




