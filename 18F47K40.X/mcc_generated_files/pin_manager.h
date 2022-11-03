/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F47K40
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set DISP2_A aliases
#define DISP2_A_TRIS                 TRISAbits.TRISA0
#define DISP2_A_LAT                  LATAbits.LATA0
#define DISP2_A_PORT                 PORTAbits.RA0
#define DISP2_A_WPU                  WPUAbits.WPUA0
#define DISP2_A_OD                   ODCONAbits.ODCA0
#define DISP2_A_ANS                  ANSELAbits.ANSELA0
#define DISP2_A_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define DISP2_A_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define DISP2_A_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define DISP2_A_GetValue()           PORTAbits.RA0
#define DISP2_A_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define DISP2_A_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define DISP2_A_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define DISP2_A_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define DISP2_A_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define DISP2_A_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define DISP2_A_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define DISP2_A_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set DISP2_B aliases
#define DISP2_B_TRIS                 TRISAbits.TRISA1
#define DISP2_B_LAT                  LATAbits.LATA1
#define DISP2_B_PORT                 PORTAbits.RA1
#define DISP2_B_WPU                  WPUAbits.WPUA1
#define DISP2_B_OD                   ODCONAbits.ODCA1
#define DISP2_B_ANS                  ANSELAbits.ANSELA1
#define DISP2_B_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define DISP2_B_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define DISP2_B_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define DISP2_B_GetValue()           PORTAbits.RA1
#define DISP2_B_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define DISP2_B_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define DISP2_B_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define DISP2_B_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define DISP2_B_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define DISP2_B_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define DISP2_B_SetAnalogMode()      do { ANSELAbits.ANSELA1 = 1; } while(0)
#define DISP2_B_SetDigitalMode()     do { ANSELAbits.ANSELA1 = 0; } while(0)

// get/set DISP2_C aliases
#define DISP2_C_TRIS                 TRISAbits.TRISA2
#define DISP2_C_LAT                  LATAbits.LATA2
#define DISP2_C_PORT                 PORTAbits.RA2
#define DISP2_C_WPU                  WPUAbits.WPUA2
#define DISP2_C_OD                   ODCONAbits.ODCA2
#define DISP2_C_ANS                  ANSELAbits.ANSELA2
#define DISP2_C_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define DISP2_C_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define DISP2_C_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define DISP2_C_GetValue()           PORTAbits.RA2
#define DISP2_C_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define DISP2_C_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define DISP2_C_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define DISP2_C_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define DISP2_C_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define DISP2_C_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define DISP2_C_SetAnalogMode()      do { ANSELAbits.ANSELA2 = 1; } while(0)
#define DISP2_C_SetDigitalMode()     do { ANSELAbits.ANSELA2 = 0; } while(0)

// get/set DISP2_D aliases
#define DISP2_D_TRIS                 TRISAbits.TRISA3
#define DISP2_D_LAT                  LATAbits.LATA3
#define DISP2_D_PORT                 PORTAbits.RA3
#define DISP2_D_WPU                  WPUAbits.WPUA3
#define DISP2_D_OD                   ODCONAbits.ODCA3
#define DISP2_D_ANS                  ANSELAbits.ANSELA3
#define DISP2_D_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define DISP2_D_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define DISP2_D_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define DISP2_D_GetValue()           PORTAbits.RA3
#define DISP2_D_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define DISP2_D_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define DISP2_D_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define DISP2_D_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define DISP2_D_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define DISP2_D_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define DISP2_D_SetAnalogMode()      do { ANSELAbits.ANSELA3 = 1; } while(0)
#define DISP2_D_SetDigitalMode()     do { ANSELAbits.ANSELA3 = 0; } while(0)

// get/set DISP2_E aliases
#define DISP2_E_TRIS                 TRISAbits.TRISA5
#define DISP2_E_LAT                  LATAbits.LATA5
#define DISP2_E_PORT                 PORTAbits.RA5
#define DISP2_E_WPU                  WPUAbits.WPUA5
#define DISP2_E_OD                   ODCONAbits.ODCA5
#define DISP2_E_ANS                  ANSELAbits.ANSELA5
#define DISP2_E_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define DISP2_E_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define DISP2_E_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define DISP2_E_GetValue()           PORTAbits.RA5
#define DISP2_E_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define DISP2_E_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define DISP2_E_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define DISP2_E_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define DISP2_E_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define DISP2_E_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define DISP2_E_SetAnalogMode()      do { ANSELAbits.ANSELA5 = 1; } while(0)
#define DISP2_E_SetDigitalMode()     do { ANSELAbits.ANSELA5 = 0; } while(0)

// get/set DISP2_F aliases
#define DISP2_F_TRIS                 TRISAbits.TRISA6
#define DISP2_F_LAT                  LATAbits.LATA6
#define DISP2_F_PORT                 PORTAbits.RA6
#define DISP2_F_WPU                  WPUAbits.WPUA6
#define DISP2_F_OD                   ODCONAbits.ODCA6
#define DISP2_F_ANS                  ANSELAbits.ANSELA6
#define DISP2_F_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define DISP2_F_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define DISP2_F_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define DISP2_F_GetValue()           PORTAbits.RA6
#define DISP2_F_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define DISP2_F_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define DISP2_F_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define DISP2_F_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define DISP2_F_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define DISP2_F_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define DISP2_F_SetAnalogMode()      do { ANSELAbits.ANSELA6 = 1; } while(0)
#define DISP2_F_SetDigitalMode()     do { ANSELAbits.ANSELA6 = 0; } while(0)

// get/set DISP2_G aliases
#define DISP2_G_TRIS                 TRISAbits.TRISA7
#define DISP2_G_LAT                  LATAbits.LATA7
#define DISP2_G_PORT                 PORTAbits.RA7
#define DISP2_G_WPU                  WPUAbits.WPUA7
#define DISP2_G_OD                   ODCONAbits.ODCA7
#define DISP2_G_ANS                  ANSELAbits.ANSELA7
#define DISP2_G_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define DISP2_G_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define DISP2_G_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define DISP2_G_GetValue()           PORTAbits.RA7
#define DISP2_G_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define DISP2_G_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define DISP2_G_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define DISP2_G_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define DISP2_G_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define DISP2_G_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define DISP2_G_SetAnalogMode()      do { ANSELAbits.ANSELA7 = 1; } while(0)
#define DISP2_G_SetDigitalMode()     do { ANSELAbits.ANSELA7 = 0; } while(0)

// get/set REL_CMD1 aliases
#define REL_CMD1_TRIS                 TRISBbits.TRISB0
#define REL_CMD1_LAT                  LATBbits.LATB0
#define REL_CMD1_PORT                 PORTBbits.RB0
#define REL_CMD1_WPU                  WPUBbits.WPUB0
#define REL_CMD1_OD                   ODCONBbits.ODCB0
#define REL_CMD1_ANS                  ANSELBbits.ANSELB0
#define REL_CMD1_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define REL_CMD1_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define REL_CMD1_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define REL_CMD1_GetValue()           PORTBbits.RB0
#define REL_CMD1_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define REL_CMD1_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define REL_CMD1_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define REL_CMD1_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define REL_CMD1_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define REL_CMD1_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define REL_CMD1_SetAnalogMode()      do { ANSELBbits.ANSELB0 = 1; } while(0)
#define REL_CMD1_SetDigitalMode()     do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set REL_CMD2 aliases
#define REL_CMD2_TRIS                 TRISBbits.TRISB1
#define REL_CMD2_LAT                  LATBbits.LATB1
#define REL_CMD2_PORT                 PORTBbits.RB1
#define REL_CMD2_WPU                  WPUBbits.WPUB1
#define REL_CMD2_OD                   ODCONBbits.ODCB1
#define REL_CMD2_ANS                  ANSELBbits.ANSELB1
#define REL_CMD2_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define REL_CMD2_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define REL_CMD2_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define REL_CMD2_GetValue()           PORTBbits.RB1
#define REL_CMD2_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define REL_CMD2_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define REL_CMD2_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define REL_CMD2_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define REL_CMD2_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define REL_CMD2_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define REL_CMD2_SetAnalogMode()      do { ANSELBbits.ANSELB1 = 1; } while(0)
#define REL_CMD2_SetDigitalMode()     do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set REL_CMD3 aliases
#define REL_CMD3_TRIS                 TRISBbits.TRISB2
#define REL_CMD3_LAT                  LATBbits.LATB2
#define REL_CMD3_PORT                 PORTBbits.RB2
#define REL_CMD3_WPU                  WPUBbits.WPUB2
#define REL_CMD3_OD                   ODCONBbits.ODCB2
#define REL_CMD3_ANS                  ANSELBbits.ANSELB2
#define REL_CMD3_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define REL_CMD3_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define REL_CMD3_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define REL_CMD3_GetValue()           PORTBbits.RB2
#define REL_CMD3_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define REL_CMD3_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define REL_CMD3_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define REL_CMD3_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define REL_CMD3_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define REL_CMD3_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define REL_CMD3_SetAnalogMode()      do { ANSELBbits.ANSELB2 = 1; } while(0)
#define REL_CMD3_SetDigitalMode()     do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set REL_CMD4 aliases
#define REL_CMD4_TRIS                 TRISBbits.TRISB3
#define REL_CMD4_LAT                  LATBbits.LATB3
#define REL_CMD4_PORT                 PORTBbits.RB3
#define REL_CMD4_WPU                  WPUBbits.WPUB3
#define REL_CMD4_OD                   ODCONBbits.ODCB3
#define REL_CMD4_ANS                  ANSELBbits.ANSELB3
#define REL_CMD4_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define REL_CMD4_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define REL_CMD4_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define REL_CMD4_GetValue()           PORTBbits.RB3
#define REL_CMD4_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define REL_CMD4_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define REL_CMD4_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define REL_CMD4_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define REL_CMD4_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define REL_CMD4_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define REL_CMD4_SetAnalogMode()      do { ANSELBbits.ANSELB3 = 1; } while(0)
#define REL_CMD4_SetDigitalMode()     do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set REL_CMD5 aliases
#define REL_CMD5_TRIS                 TRISBbits.TRISB4
#define REL_CMD5_LAT                  LATBbits.LATB4
#define REL_CMD5_PORT                 PORTBbits.RB4
#define REL_CMD5_WPU                  WPUBbits.WPUB4
#define REL_CMD5_OD                   ODCONBbits.ODCB4
#define REL_CMD5_ANS                  ANSELBbits.ANSELB4
#define REL_CMD5_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define REL_CMD5_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define REL_CMD5_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define REL_CMD5_GetValue()           PORTBbits.RB4
#define REL_CMD5_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define REL_CMD5_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define REL_CMD5_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define REL_CMD5_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define REL_CMD5_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define REL_CMD5_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define REL_CMD5_SetAnalogMode()      do { ANSELBbits.ANSELB4 = 1; } while(0)
#define REL_CMD5_SetDigitalMode()     do { ANSELBbits.ANSELB4 = 0; } while(0)

// get/set REL_CMD6 aliases
#define REL_CMD6_TRIS                 TRISBbits.TRISB5
#define REL_CMD6_LAT                  LATBbits.LATB5
#define REL_CMD6_PORT                 PORTBbits.RB5
#define REL_CMD6_WPU                  WPUBbits.WPUB5
#define REL_CMD6_OD                   ODCONBbits.ODCB5
#define REL_CMD6_ANS                  ANSELBbits.ANSELB5
#define REL_CMD6_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define REL_CMD6_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define REL_CMD6_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define REL_CMD6_GetValue()           PORTBbits.RB5
#define REL_CMD6_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define REL_CMD6_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define REL_CMD6_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define REL_CMD6_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define REL_CMD6_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define REL_CMD6_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define REL_CMD6_SetAnalogMode()      do { ANSELBbits.ANSELB5 = 1; } while(0)
#define REL_CMD6_SetDigitalMode()     do { ANSELBbits.ANSELB5 = 0; } while(0)

// get/set RS485_CMD aliases
#define RS485_CMD_TRIS                 TRISCbits.TRISC2
#define RS485_CMD_LAT                  LATCbits.LATC2
#define RS485_CMD_PORT                 PORTCbits.RC2
#define RS485_CMD_WPU                  WPUCbits.WPUC2
#define RS485_CMD_OD                   ODCONCbits.ODCC2
#define RS485_CMD_ANS                  ANSELCbits.ANSELC2
#define RS485_CMD_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define RS485_CMD_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define RS485_CMD_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define RS485_CMD_GetValue()           PORTCbits.RC2
#define RS485_CMD_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define RS485_CMD_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define RS485_CMD_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define RS485_CMD_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define RS485_CMD_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define RS485_CMD_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define RS485_CMD_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define RS485_CMD_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set RC3 procedures
#define RC3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define RC3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define RC3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define RC3_GetValue()              PORTCbits.RC3
#define RC3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define RC3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define RC3_SetPullup()             do { WPUCbits.WPUC3 = 1; } while(0)
#define RC3_ResetPullup()           do { WPUCbits.WPUC3 = 0; } while(0)
#define RC3_SetAnalogMode()         do { ANSELCbits.ANSELC3 = 1; } while(0)
#define RC3_SetDigitalMode()        do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSELC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSELC4 = 0; } while(0)

// get/set DIR_485 aliases
#define DIR_485_TRIS                 TRISCbits.TRISC5
#define DIR_485_LAT                  LATCbits.LATC5
#define DIR_485_PORT                 PORTCbits.RC5
#define DIR_485_WPU                  WPUCbits.WPUC5
#define DIR_485_OD                   ODCONCbits.ODCC5
#define DIR_485_ANS                  ANSELCbits.ANSELC5
#define DIR_485_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define DIR_485_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define DIR_485_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define DIR_485_GetValue()           PORTCbits.RC5
#define DIR_485_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define DIR_485_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define DIR_485_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define DIR_485_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define DIR_485_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define DIR_485_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define DIR_485_SetAnalogMode()      do { ANSELCbits.ANSELC5 = 1; } while(0)
#define DIR_485_SetDigitalMode()     do { ANSELCbits.ANSELC5 = 0; } while(0)

// get/set RC6 procedures
#define RC6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define RC6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define RC6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define RC6_GetValue()              PORTCbits.RC6
#define RC6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define RC6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define RC6_SetPullup()             do { WPUCbits.WPUC6 = 1; } while(0)
#define RC6_ResetPullup()           do { WPUCbits.WPUC6 = 0; } while(0)
#define RC6_SetAnalogMode()         do { ANSELCbits.ANSELC6 = 1; } while(0)
#define RC6_SetDigitalMode()        do { ANSELCbits.ANSELC6 = 0; } while(0)

// get/set RC7 procedures
#define RC7_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define RC7_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define RC7_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define RC7_GetValue()              PORTCbits.RC7
#define RC7_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define RC7_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define RC7_SetPullup()             do { WPUCbits.WPUC7 = 1; } while(0)
#define RC7_ResetPullup()           do { WPUCbits.WPUC7 = 0; } while(0)
#define RC7_SetAnalogMode()         do { ANSELCbits.ANSELC7 = 1; } while(0)
#define RC7_SetDigitalMode()        do { ANSELCbits.ANSELC7 = 0; } while(0)

// get/set DISP1_A aliases
#define DISP1_A_TRIS                 TRISDbits.TRISD0
#define DISP1_A_LAT                  LATDbits.LATD0
#define DISP1_A_PORT                 PORTDbits.RD0
#define DISP1_A_WPU                  WPUDbits.WPUD0
#define DISP1_A_OD                   ODCONDbits.ODCD0
#define DISP1_A_ANS                  ANSELDbits.ANSELD0
#define DISP1_A_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define DISP1_A_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define DISP1_A_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define DISP1_A_GetValue()           PORTDbits.RD0
#define DISP1_A_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define DISP1_A_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define DISP1_A_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define DISP1_A_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define DISP1_A_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define DISP1_A_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define DISP1_A_SetAnalogMode()      do { ANSELDbits.ANSELD0 = 1; } while(0)
#define DISP1_A_SetDigitalMode()     do { ANSELDbits.ANSELD0 = 0; } while(0)

// get/set DISP1_B aliases
#define DISP1_B_TRIS                 TRISDbits.TRISD1
#define DISP1_B_LAT                  LATDbits.LATD1
#define DISP1_B_PORT                 PORTDbits.RD1
#define DISP1_B_WPU                  WPUDbits.WPUD1
#define DISP1_B_OD                   ODCONDbits.ODCD1
#define DISP1_B_ANS                  ANSELDbits.ANSELD1
#define DISP1_B_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define DISP1_B_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define DISP1_B_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define DISP1_B_GetValue()           PORTDbits.RD1
#define DISP1_B_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define DISP1_B_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define DISP1_B_SetPullup()          do { WPUDbits.WPUD1 = 1; } while(0)
#define DISP1_B_ResetPullup()        do { WPUDbits.WPUD1 = 0; } while(0)
#define DISP1_B_SetPushPull()        do { ODCONDbits.ODCD1 = 0; } while(0)
#define DISP1_B_SetOpenDrain()       do { ODCONDbits.ODCD1 = 1; } while(0)
#define DISP1_B_SetAnalogMode()      do { ANSELDbits.ANSELD1 = 1; } while(0)
#define DISP1_B_SetDigitalMode()     do { ANSELDbits.ANSELD1 = 0; } while(0)

// get/set DISP1_C aliases
#define DISP1_C_TRIS                 TRISDbits.TRISD2
#define DISP1_C_LAT                  LATDbits.LATD2
#define DISP1_C_PORT                 PORTDbits.RD2
#define DISP1_C_WPU                  WPUDbits.WPUD2
#define DISP1_C_OD                   ODCONDbits.ODCD2
#define DISP1_C_ANS                  ANSELDbits.ANSELD2
#define DISP1_C_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define DISP1_C_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define DISP1_C_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define DISP1_C_GetValue()           PORTDbits.RD2
#define DISP1_C_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define DISP1_C_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define DISP1_C_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define DISP1_C_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define DISP1_C_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define DISP1_C_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define DISP1_C_SetAnalogMode()      do { ANSELDbits.ANSELD2 = 1; } while(0)
#define DISP1_C_SetDigitalMode()     do { ANSELDbits.ANSELD2 = 0; } while(0)

// get/set DISP1_D aliases
#define DISP1_D_TRIS                 TRISDbits.TRISD3
#define DISP1_D_LAT                  LATDbits.LATD3
#define DISP1_D_PORT                 PORTDbits.RD3
#define DISP1_D_WPU                  WPUDbits.WPUD3
#define DISP1_D_OD                   ODCONDbits.ODCD3
#define DISP1_D_ANS                  ANSELDbits.ANSELD3
#define DISP1_D_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define DISP1_D_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define DISP1_D_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define DISP1_D_GetValue()           PORTDbits.RD3
#define DISP1_D_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define DISP1_D_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define DISP1_D_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define DISP1_D_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define DISP1_D_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define DISP1_D_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define DISP1_D_SetAnalogMode()      do { ANSELDbits.ANSELD3 = 1; } while(0)
#define DISP1_D_SetDigitalMode()     do { ANSELDbits.ANSELD3 = 0; } while(0)

// get/set DISP1_DP aliases
#define DISP1_DP_TRIS                 TRISDbits.TRISD4
#define DISP1_DP_LAT                  LATDbits.LATD4
#define DISP1_DP_PORT                 PORTDbits.RD4
#define DISP1_DP_WPU                  WPUDbits.WPUD4
#define DISP1_DP_OD                   ODCONDbits.ODCD4
#define DISP1_DP_ANS                  ANSELDbits.ANSELD4
#define DISP1_DP_SetHigh()            do { LATDbits.LATD4 = 1; } while(0)
#define DISP1_DP_SetLow()             do { LATDbits.LATD4 = 0; } while(0)
#define DISP1_DP_Toggle()             do { LATDbits.LATD4 = ~LATDbits.LATD4; } while(0)
#define DISP1_DP_GetValue()           PORTDbits.RD4
#define DISP1_DP_SetDigitalInput()    do { TRISDbits.TRISD4 = 1; } while(0)
#define DISP1_DP_SetDigitalOutput()   do { TRISDbits.TRISD4 = 0; } while(0)
#define DISP1_DP_SetPullup()          do { WPUDbits.WPUD4 = 1; } while(0)
#define DISP1_DP_ResetPullup()        do { WPUDbits.WPUD4 = 0; } while(0)
#define DISP1_DP_SetPushPull()        do { ODCONDbits.ODCD4 = 0; } while(0)
#define DISP1_DP_SetOpenDrain()       do { ODCONDbits.ODCD4 = 1; } while(0)
#define DISP1_DP_SetAnalogMode()      do { ANSELDbits.ANSELD4 = 1; } while(0)
#define DISP1_DP_SetDigitalMode()     do { ANSELDbits.ANSELD4 = 0; } while(0)

// get/set DISP1_E aliases
#define DISP1_E_TRIS                 TRISDbits.TRISD5
#define DISP1_E_LAT                  LATDbits.LATD5
#define DISP1_E_PORT                 PORTDbits.RD5
#define DISP1_E_WPU                  WPUDbits.WPUD5
#define DISP1_E_OD                   ODCONDbits.ODCD5
#define DISP1_E_ANS                  ANSELDbits.ANSELD5
#define DISP1_E_SetHigh()            do { LATDbits.LATD5 = 1; } while(0)
#define DISP1_E_SetLow()             do { LATDbits.LATD5 = 0; } while(0)
#define DISP1_E_Toggle()             do { LATDbits.LATD5 = ~LATDbits.LATD5; } while(0)
#define DISP1_E_GetValue()           PORTDbits.RD5
#define DISP1_E_SetDigitalInput()    do { TRISDbits.TRISD5 = 1; } while(0)
#define DISP1_E_SetDigitalOutput()   do { TRISDbits.TRISD5 = 0; } while(0)
#define DISP1_E_SetPullup()          do { WPUDbits.WPUD5 = 1; } while(0)
#define DISP1_E_ResetPullup()        do { WPUDbits.WPUD5 = 0; } while(0)
#define DISP1_E_SetPushPull()        do { ODCONDbits.ODCD5 = 0; } while(0)
#define DISP1_E_SetOpenDrain()       do { ODCONDbits.ODCD5 = 1; } while(0)
#define DISP1_E_SetAnalogMode()      do { ANSELDbits.ANSELD5 = 1; } while(0)
#define DISP1_E_SetDigitalMode()     do { ANSELDbits.ANSELD5 = 0; } while(0)

// get/set DISP1_F aliases
#define DISP1_F_TRIS                 TRISDbits.TRISD6
#define DISP1_F_LAT                  LATDbits.LATD6
#define DISP1_F_PORT                 PORTDbits.RD6
#define DISP1_F_WPU                  WPUDbits.WPUD6
#define DISP1_F_OD                   ODCONDbits.ODCD6
#define DISP1_F_ANS                  ANSELDbits.ANSELD6
#define DISP1_F_SetHigh()            do { LATDbits.LATD6 = 1; } while(0)
#define DISP1_F_SetLow()             do { LATDbits.LATD6 = 0; } while(0)
#define DISP1_F_Toggle()             do { LATDbits.LATD6 = ~LATDbits.LATD6; } while(0)
#define DISP1_F_GetValue()           PORTDbits.RD6
#define DISP1_F_SetDigitalInput()    do { TRISDbits.TRISD6 = 1; } while(0)
#define DISP1_F_SetDigitalOutput()   do { TRISDbits.TRISD6 = 0; } while(0)
#define DISP1_F_SetPullup()          do { WPUDbits.WPUD6 = 1; } while(0)
#define DISP1_F_ResetPullup()        do { WPUDbits.WPUD6 = 0; } while(0)
#define DISP1_F_SetPushPull()        do { ODCONDbits.ODCD6 = 0; } while(0)
#define DISP1_F_SetOpenDrain()       do { ODCONDbits.ODCD6 = 1; } while(0)
#define DISP1_F_SetAnalogMode()      do { ANSELDbits.ANSELD6 = 1; } while(0)
#define DISP1_F_SetDigitalMode()     do { ANSELDbits.ANSELD6 = 0; } while(0)

// get/set DISP1_G aliases
#define DISP1_G_TRIS                 TRISDbits.TRISD7
#define DISP1_G_LAT                  LATDbits.LATD7
#define DISP1_G_PORT                 PORTDbits.RD7
#define DISP1_G_WPU                  WPUDbits.WPUD7
#define DISP1_G_OD                   ODCONDbits.ODCD7
#define DISP1_G_ANS                  ANSELDbits.ANSELD7
#define DISP1_G_SetHigh()            do { LATDbits.LATD7 = 1; } while(0)
#define DISP1_G_SetLow()             do { LATDbits.LATD7 = 0; } while(0)
#define DISP1_G_Toggle()             do { LATDbits.LATD7 = ~LATDbits.LATD7; } while(0)
#define DISP1_G_GetValue()           PORTDbits.RD7
#define DISP1_G_SetDigitalInput()    do { TRISDbits.TRISD7 = 1; } while(0)
#define DISP1_G_SetDigitalOutput()   do { TRISDbits.TRISD7 = 0; } while(0)
#define DISP1_G_SetPullup()          do { WPUDbits.WPUD7 = 1; } while(0)
#define DISP1_G_ResetPullup()        do { WPUDbits.WPUD7 = 0; } while(0)
#define DISP1_G_SetPushPull()        do { ODCONDbits.ODCD7 = 0; } while(0)
#define DISP1_G_SetOpenDrain()       do { ODCONDbits.ODCD7 = 1; } while(0)
#define DISP1_G_SetAnalogMode()      do { ANSELDbits.ANSELD7 = 1; } while(0)
#define DISP1_G_SetDigitalMode()     do { ANSELDbits.ANSELD7 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/