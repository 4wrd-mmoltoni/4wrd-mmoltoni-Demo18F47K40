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

static uint16_t data;
static uint8_t  startMeasureFlag;
static uint8_t  rele;

int16_t measureVect[6];
#define RELE_DELAYms    (100000)    //(is in micro seconds us)

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
}

void StartMeasure(void)
{
    startMeasureFlag = 1;
}

uint8_t MeasureBusy(void)
{
    return startMeasureFlag;
}

void ExecuteMeasure(void)
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
                measureVect[channel] = I2C1_Read2ByteRegister(0x48, 0);
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

void ExecuteMeasureOLD(void)
{
    if (!startMeasureFlag)
        return;
    
    uint8_t n;
    uint8_t r = 1;
    uint8_t status = LATB;
    
    status &= 0xC0;     //keep B6 and B7
              
    for (n = 0; n < 6; n++)
    {
        //set channel
        LATB = (status | r);
        //delay channel
        __delay_ms(30);
        //read
        measureVect[n] = I2C1_Read2ByteRegister(0x48, 1);
        //end!
        r <<= 1;
    }
    startMeasureFlag = 0;
}