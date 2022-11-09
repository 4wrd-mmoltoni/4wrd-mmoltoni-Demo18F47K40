/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.1
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47K40
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include <stdio.h>
#include <string.h>

#include "mcc_generated_files/mcc.h"

#include "algorithm.h"
#include "Utils.h"
#include "485.h"
#include "Measure.h"

#pragma warning disable 520 // suppress annoying 'funtion not used' warnings
#pragma warning disable 2053 // suppress annoying 'funtion not used' warnings


uint32_t    n;
uint8_t c = 0x33;
volatile uint32_t stime;

extern uint8_t MDB_addr;        //temporary only!!

/*
                         Main application
 */
uint32_t    n;

void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global and Peripheral Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    volatile uint8_t reg;
    volatile uint16_t data = 0;
    
    TMR0_StartTimer();
    TMR1_StartTimer();
    TMR2_StartTimer();
    
    stime = 0;   
    InitVars();
    //  __delay_us(300);
    
//    MDB_addr = '1';     //must remove!
    
    ShowAddr(MDB_addr-'0');
    
    char buf[100];
    uint16_t val[6] = {1, 0x300, 0x55, 0x1FF, 0xAaff, 0xFFFF};
    
    ConvertMeasureToStr(val, buf);    
    //printf(buf);
    //size_t nn = strlen(buf);
    buf[50] = 0;    
    
#if 0
    LATA ^= 0x01;
    // Initialize the CRC module
    CRC_Initialize();
    // Start CRC
    CRC_Start();
    
    for (n = 0; n < 10; n++)
    {
        CRC_8BitDataWrite(buf[n]);
        //while(CRC_IsBusy());
        //crcVal = CRC_CalculatedResultGet(REVERSE,0x00);
    }
    // Read CRC check value
    crcVal = CRC_CalculatedResultGet(REVERSE,0x00);     //85 us
    LATA ^= 0x01;
    
    for (int n = 0; n< 1000; n++);                          //1 ms con 2000 cicli
#endif
    
    InitMeasure();
    

    while (1)
    {
        // Add your application code
 
#if 0        
        data = I2C1_Read2ByteRegister(0x48, 0);
        //Usart485.tx_lenbuf = 0;
        Usart485.tx_pointer = 0;        
        // 3.3/32768 = 0,0000625
        volatile float f = 0.0000625 * (float)data;
        sprintf(buf, ">>0x%04X = %2.5f.\r\n", data, f);
        n = strlen(buf);
        strncpy(Usart485.buf485, buf, n);
        Usart485.tx_lenbuf = n;
        Write485_start(Usart485.tx_lenbuf);
        __delay_ms(1000);
        n++;        
#else
        //ShowAddr(MDB_addr-'0');
        
        if (Received485())
        	Write485_start(Usart485.tx_lenbuf);        
        ResetReqExecute();
        
        ExecuteMeasure();
                
#endif
        
    }
}
/**
 End of File
*/