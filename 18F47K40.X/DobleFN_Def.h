/* Microchip Technology Inc. and its subsidiaries.  You may use this software 
 * and any derivatives exclusively with Microchip products. 
 * 
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS".  NO WARRANTIES, WHETHER 
 * EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED 
 * WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A 
 * PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION 
 * WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION. 
 *
 * IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
 * INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
 * WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS 
 * BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE 
 * FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS 
 * IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF 
 * ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE 
 * TERMS. 
 */

/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef DOBLEFN_DEF_H
#define	DOBLEFN_DEF_H

//#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

#define MAIOR_VERSION       0
#define MINOR_VERSION       1       //2 caratteri!

#define KEEPBOOT_MAGICNUMBER        0x55

//EEPROM map definitions
#define BOOTLOADER_KEEPINBOOT_ADDR	0
#define MODBUSADDRES_EEPROM_ADDR	1
#define START_CONFIG_STR_ADDR       512


typedef enum {
    // < 'A', form 1 to '': debug function ONLY     
    COMM_FNC_SET_485_BRIDGE = 0,
    
    //STart standard funcition from ASCII 'A'
    COMM_FNC_SET_ADDR       = 0x41,     //= 'A' 
    COMM_FNC_GET_ADDR,                  //Non serve (con 1! seriale))
                
    COMM_FNC_EXEC_MEASURE,
    COMM_FNC_READ_MEASURE,
    COMM_FNC_GET_DIAG,
    COMM_FNC_RESET_DIAG,
	//Calibration functions
    COMM_FNC_SET_GAIN,
	COMM_FNC_GET_GAIN,
	COMM_FNC_SET_OFFSET_ZERO,
	COMM_FNC_RESET_OFFSET_ZERO,
	COMM_FNC_GETROW_ADC_DATA,
	COMM_FNC_SAVE_COEFF,
	COMM_FNC_GET_COEFF,
    //Setting and other functions        
	COMM_FNC_GET_FW_VERSION,
	COMM_FNC_SET_STRING,
	COMM_FNC_GET_STRING,
	COMM_FNC_GET_STATUS,				//0x50 = 80d = 'P'
	COMM_FNC_REBOOT,
    COMM_FNC_GOTO_BOOTLOADER,
    //Bootloader only:
	COMM_FNC_CLEAR_APPFLASH,
	COMM_FNC_WRITEFLASH,
    
} COMM_FNC;

typedef union
{
	struct
	{
        union
        {
            struct
            {
                uint8_t connected       :1;
                uint8_t notBatConnect   :1;
                uint8_t VoutOfRange     :1;
                uint8_t res             :5;
            };
            uint8_t b;
        } bConverter;
        union
        {
            struct
            {
                uint8_t reset_WD        :1;
                uint8_t reset_BrownOut  :1;
                uint8_t reset_req       :1;
                uint8_t res             :5;
            };
            uint8_t b;
        } bProcessor;
	} ;
	uint16_t w;
} ERRORType;


#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	//DOBLEFN_DEF_H
