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
#ifndef UTILS_H
#define	UTILS_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include "DobleFN_Def.h"
#include "mcc_generated_files/pin_manager.h"

//#define HundredMICROVOLT_STEP_f      (160000.0/65535.0)     //16.000.000/100
#define HundredMICROVOLT_STEP_f      (20480.0/65535.0)     //16.000.000/100

#define BAPTESIM_OK     RS485_CMD_SetLow()
#define BAPTESIM_NOK    RS485_CMD_SetHigh()


extern ERRORType   ErrorVect;

void FLASH_ReadSector(uint8_t *buf, uint32_t flashAddr);
void FLASH_ReadSector64k(uint8_t *buf, uint16_t flashAddr);

void DisplayA(uint8_t val);
void DisplayB(uint8_t val);
void ShowAddr(int val);

void InitVars(void);
void WriteConfigSTR(const uint8_t *buf, uint8_t len);
void ReadConfigSTR(uint8_t *buf, uint8_t len);
void WriteEEpromMDB_Addr(uint8_t val);
uint8_t ReadEEpromMDB_Addr(void);
void Handle485Dir(void);

void ResetRequest(void);
void ResetReqExecute(void);

void ConvertSingleMeasureToStr(uint16_t raw, uint8_t* str);
void ConvertMeasureToStr(uint16_t* raw, char* str);
void ConvertBufToStr(const uint8_t* raw, uint8_t* str);

void testfnc();

// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

#ifdef	__cplusplus
extern "C" {
#endif /* __cplusplus */

    // TODO If C++ is being used, regular C code needs function names to have C 
    // linkage so the functions can be used by the c code. 

#ifdef	__cplusplus
}
#endif /* __cplusplus */

#endif	//UTILS_H

