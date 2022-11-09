/* 
 * File:   Timers.h
 * Author: User1
 *
 * Created on November 17, 2021, 2:01 PM
 */

#ifndef TIMERS_H
#define	TIMERS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "mcc_generated_files/mcc.h"

// if defined, timer never expired - debug purpose only
//#define TIMER_DEBUG
    
typedef struct
{
    uint32_t u32_counter_1u;
    uint32_t u32_reload;
}FREE_TIMER;

#define NUM_TIMERS  2

#define TIM_TIMEOUT1  0
#define TIM_BLINK     1  


void Init_Timers(void);
void Handle_Timers(void);
void Timers_SET(uint8_t numtimer, uint32_t val_10us);
void Timers_Start(uint8_t numtimer);
uint8_t Timer_Is_Expired(uint8_t numtimer);

#ifdef	__cplusplus
}
#endif

#endif	/* TIMERS_H */

