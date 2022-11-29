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

#ifndef  INC_VCL
#include <xc.h> // include processor files - each processor file is guarded.
#endif  
#include <stdint.h>

#define MAJOR_VERSION       0
#define MINOR_VERSION       2       //2 caratteri!

#define KEEPBOOT_MAGICNUMBER        0x55

//EEPROM map definitions
#define BOOTLOADER_KEEPINBOOT_ADDR	0
#define MODBUSADDRES_EEPROM_ADDR	1
#define TRESHOLD_L_EEPROM_ADDR      5
#define TRESHOLD_H_EEPROM_ADDR      6
#define START_CONFIG_STR_ADDR       512


typedef enum {
    // < 'A', form 1 to '': debug function ONLY     
    COMM_FNC_SET_485_BRIDGE = 0,
	COMM_FNC_READRAW_MEASURE,
    COMM_FNC_RESET_ADDR,
    COMM_FNC_CUSTOM1,
    
    //Start standard funcition from ASCII 'A'
    COMM_FNC_SET_ADDR       = 0x41,     //= 'A' 
	COMM_FNC_RESET_DIAG,
	//COMM_FNC_GET_ADDR,                  //Non serve (con 1! seriale))
    
    //Measuring functions
    COMM_FNC_EXEC_MEASURE,
    COMM_FNC_READ_MEASURE,
    COMM_FNC_GET_DIAG		= 0x45,
    //COMM_FNC_RESET_DIAG,
	//Calibration functions
    COMM_FNC_SET_GAIN,
	COMM_FNC_GET_GAIN		= 0x47,
	COMM_FNC_SET_OFFSET_ZERO,
	COMM_FNC_RESET_OFFSET_ZERO,
	COMM_FNC_SAVE_COEFF		= 0x4A,
	COMM_FNC_GET_COEFF		= 0x4B,
	COMM_FNC_SET_TRESHOLD	= 0x4C,			//ADD
	COMM_FNC_GET_TRESHOLD	= 0x4D,
    //Setting and other functions        
	COMM_FNC_GET_FW_VERSION,
	COMM_FNC_SET_STRING,
	COMM_FNC_GET_STRING,

	COMM_FNC_REBOOT			= 0x52,
    //Bootloader only:
    COMM_FNC_GOTO_BOOTLOADER,
	COMM_FNC_WRITEFLASH,
    COMM_FNC_CALCCRC,
    
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

