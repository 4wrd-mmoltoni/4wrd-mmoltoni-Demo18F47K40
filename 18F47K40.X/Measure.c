//Measurement only!
#include <string.h>
#include "Utils.h"
#include "DobleFN_Def.h"
#include "Function485.h"
#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/memory.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"
#include "485.h"
#include "Timers.h"

#include "Measure.h"

#define RELE_DELAYms    (100000)    // (is in micro seconds us)
#define MIS_DELAY       (1000)      // tra una misura e l'altra
#define NUM_MEASURE     8           // Numero misure per media


static uint16_t data;
static uint8_t  startMeasureFlag;
static uint8_t  rele;

int16_t            measureVect[6];
static int32_t     sumMeasure; 
static uint16_t    mediaMisure[NUM_MEASURE];

static void ClearRele()
{
    uint8_t status = LATB;
    status &= 0xC0;            
    LATB = status;
}

void InitMeasure(void)
{
    data = I2C1_Read2ByteRegister(0x48, 1);
    for (int n = 0; n < 1000; n++);
    //n++;
    //data = 0x8083;
    data = 0x8380;
    I2C1_Write2ByteRegister(0x48, 1, data);
    __delay_ms(300);
    
    //start continuous measure
    data = I2C1_Read2ByteRegister(0x48, 1);
    
    for(char n = 0; n < 6; n++)
    {
        measureVect[n] = 0;
    }
    rele = 0;
    ClearRele();
    startMeasureFlag = 0;
    Timers_SET(TIM_MEASURE, (RELE_DELAYms));
    Timers_SET(TIM_MEASDELAY, (MIS_DELAY));
}

void StartMeasure(void)
{
    startMeasureFlag = 1;
}

uint8_t MeasureBusy(void)
{
    return startMeasureFlag;
}

/* Macchina a stati per lesecuzione non interrompente della misura */
void ExecuteMeasure(void)
{
    if (!startMeasureFlag)
        return;
    
    static uint8_t channel;
    static uint8_t measureStatus;
    static uint8_t nmeasure;
    uint8_t r = 1;
    uint8_t status;    
    
    status = LATB & 0xC0;     //keep B6 and B7
    
    if (channel <6)
    {
        switch (measureStatus)
        {
            case 0:     //init
                //set channel
                r = 1 << channel;
                LATB = (status | r);            //set relè channel
                Timers_Start(TIM_MEASURE);
                measureStatus = 1;
                nmeasure = 0;                
                break;
            case 1:
                if (Timer_Is_Expired(TIM_MEASURE))
                    measureStatus = 2;
                nmeasure = 0;
                sumMeasure = 0;
                break;
            case 2: 
                measureStatus = 3;
                mediaMisure[nmeasure] = I2C1_Read2ByteRegister(0x48, 0);
                sumMeasure += mediaMisure[nmeasure];
                //measureVect[channel] = I2C1_Read2ByteRegister(0x48, 0);
                if (++nmeasure >= NUM_MEASURE)
                    measureStatus = 4;
                else
                    Timers_Start(TIM_MEASDELAY);                
                break;
            case 3:
                if (Timer_Is_Expired(TIM_MEASDELAY))
                    measureStatus = 2;
                break;                
                
            case 4:
                measureVect[channel] = sumMeasure/NUM_MEASURE;
                channel++;
                measureStatus = 0;                
                break;
        }
    }
    else
    {
        channel = 0;
        startMeasureFlag = 0;
    }    
}


void ExecuteMeasure_nomedia(void)
{
    if (!startMeasureFlag)
        return;
    
    static uint8_t channel;
    static uint8_t measureStatus;
    uint8_t r = 1;
    uint8_t status = LATB;
    
    status &= 0xC0;     //keep B6 and B7
    
    if (channel <6)
    {
        switch (measureStatus)
        {
            case 0:     //init
                //set channel
                r = 1 << channel;
                LATB = (status | r);
                Timers_Start(TIM_MEASURE);
                measureStatus = 1;
                break;
            case 1:
                if (Timer_Is_Expired(TIM_MEASURE))
                    measureStatus = 2;
                break;
            case 2: 
                measureVect[channel] = I2C1_Read2ByteRegister(0x48, 1);
                channel++;
                measureStatus = 0;
                break;
        }
    }
    else
    {
        channel = 0;
        startMeasureFlag = 0;
    }    
}

// Converte da misura a microvolt * 100 (decimo di mV)
int32_t    ConvertMeasure(uint16_t raw)
{
    float f = HundredMICROVOLT_STEP_f * (float)raw;
    return (int32_t)f;
}

void ConvertSingleMeasureToStr(uint16_t raw, uint8_t* str)
{
    uint32_t val = ConvertMeasure(raw);
    sprintf(str, "%+06ld", val);    
}


void ConvertMeasureToStr(uint16_t* raw, char* str)
{
    int32_t val[6];
    uint8_t n;    
    for (n = 0; n < 6; n++)
        val[n] = ConvertMeasure(raw[n]);
    sprintf(str, "%+06ld %+06ld %+06ld %+06ld %+06ld %+06ld ", val[0], val[1], val[2], val[3], val[4], val[5]);    
}

void ConvertBufToStr(const uint8_t* raw, uint8_t* str)
{
    int32_t val[6];
    uint8_t n;
    int16_t *shp;
    for (n = 0; n < 6; n++)
    {
    	shp = (uint16_t*)raw[n*2];
        val[n] = ConvertMeasure(shp);
    }
    sprintf(str, "%+06ld %+06ld %+06ld %+06ld %+06ld %+06ld ", val[0], val[1], val[2], val[3], val[4], val[5]);    
}