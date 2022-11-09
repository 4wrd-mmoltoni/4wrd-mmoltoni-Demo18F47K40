
/**
 *  @file       EPPClient.c
 *
 *  @brief      Basic description of file contents
 *
 *
 *  @copyright  Copyright 2021.
 *              Haier Europe. All rights reserved - CONFIDENTIAL
 */
//---------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------

//-------------------------------------- Include Files ----------------------------------------------------------------
#include <string.h>
#include "Timers.h"

//-------------------------------------- PUBLIC (Variables) -----------------------------------------------------------
FREE_TIMER Timers[NUM_TIMERS];

/**
 * @brief   Initate TIMERS structure
 *
 */
void Init_Timers(void)
{
    memset(&Timers, 0, sizeof(Timers));
    TMR0_Initialize();
    TMR0_StartTimer();
}


/**
 * @brief   Set timer value in micro seconds
 *
 */
void Timers_SET(uint8_t numtimer, uint32_t val_us)
{
    if (numtimer >= NUM_TIMERS)
        return;
    
    Timers[numtimer].u32_reload = val_us;
}


/**
 * @brief   Check if timer is expired.
 * Return 1 if done, 0 if num of timer is greater than maximum OR NOT expired
 *
 */
uint8_t Timer_Is_Expired(uint8_t numtimer)
{
    if (numtimer >= NUM_TIMERS)
        return 0;
    
    return (Timers[numtimer].u32_counter_1u)? 0:1;
}

/**
 * @brief   Start timer with preassigned value
 * SeeTimers_Set above
 *
 */
void Timers_Start(uint8_t numtimer)
{
    if (numtimer >= NUM_TIMERS)
        return;
    
    Timers[numtimer].u32_counter_1u = Timers[numtimer].u32_reload;            
}


/**
 * @brief   Main function: put this in the main loop or fastest task
 *
 */
void Handle_Timers(void)
{
    uint8_t n;
    uint32_t deltaT = 0;
    static uint16_t u16_timer0_oldval;
    
#ifdef TIMER_DEBUG
    return;
#endif
    
    uint16_t u16_timer0_reg = TMR0_ReadTimer();   //16 bit register actual value
    
    if (u16_timer0_reg <= u16_timer0_oldval)
    {
        deltaT = (0xFFFF - u16_timer0_oldval) + u16_timer0_reg;        
    }
    else
    {
        deltaT = u16_timer0_reg - u16_timer0_oldval;
    }
    
    u16_timer0_oldval = u16_timer0_reg;
    
    for(n = 0; n < NUM_TIMERS; n++)
    {
        if (Timers[n].u32_counter_1u && (Timers[n].u32_counter_1u <= deltaT))
        {
            Timers[n].u32_counter_1u = 0;
        }
        else
        {
            Timers[n].u32_counter_1u -= deltaT;
        }
    }    
}
