#include <string.h>
#include "Utils.h"
#include "DobleFN_Def.h"
#include "Function485.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/memory.h"
#include "485.h"


uint8_t     ResetReq = 0;
ERRORType   ErrorVect;


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
        //LED_Blu_SetHigh();          //àncora tirata, situazione da battezzare
        MDB_addr = '0';               //Ho acceso: l'indirizzo è NULLO (per battesimo
        return;
    }
    //else
    if (PCON0bits.NOT_BOR)          //Brown-out    
    {
        //LED_Blu_SetHigh();          //àncora tirata, situazione da battezzare
        MDB_addr = '0';               //Ho acceso: l'indirizzo è NULLO (per battesimo
        PCON0bits.NOT_BOR = 1;
        return;
    }
    
    if (PCON0bits.NOT_POR ||        //Power-on Reset Status bit
        PCON0bits.NOT_RMCLR ||      //MCLR Reset Flag bit
        PCON0bits.NOT_WDTWV ||      //WDT Reset Flag bit
        PCON0bits.NOT_RI            //RESET Instruction Flag bit
        )
    {
        //LED_Blu_SetLow();       //Già battezzato
        MDB_addr = ReadEEpromMDB_Addr();
        return;
    }
    return;
}

void WriteEEpromMDB_Addr(uint8_t val)
{
	DATAEE_WriteByte(MODBUSADDRES_EEPROM_ADDR, val);
}

uint8_t ReadEEpromMDB_Addr(void)
{
	return DATAEE_ReadByte(MODBUSADDRES_EEPROM_ADDR);
}


void WriteConfigSTR(const uint8_t *buf, uint8_t len)
{
    uint16_t addr = START_CONFIG_STR_ADDR;
    if (len > 64)
        len = 64;

    for(uint8_t n = 0; n < len; n++)
        DATAEE_WriteByte(addr++, buf[n]);
}

void ReadConfigSTR(uint8_t *buf, uint8_t len)
{
    uint16_t addr = START_CONFIG_STR_ADDR;
    if (len > 64)
        len = 64;

    for (uint8_t n = 0; n < len; n++)
        buf[n] = DATAEE_ReadByte(addr++);
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

//tests...
void MAX7219_send(uint8_t reg, uint8_t dat)
{
    uint16_t d=(reg<<8)|dat;
    for (uint8_t i=0; i<16; i++)
        {
        if (d & (0x8000>>i))
            {MAX_DAT_SetHigh();}
        else
            {MAX_DAT_SetLow();}
        MAX_CLK_SetHigh();
        MAX_CLK_SetLow();
        }
    //MAX_LAT_SetHigh();
    //MAX_LAT_SetLow();    
}
