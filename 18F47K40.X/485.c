#include <string.h>
#include "485.h"
#include "Function485.h"


USART485BUF  Usart485;
extern volatile uint32_t stime;


void Init_Usart485(void)
{
    memset(&Usart485, 0, sizeof(Usart485));
}

void Write485_start(uint8_t len)
{
    Usart485.rx_lenbuf = 0; //reset! (maybe non here...)
    Usart485.tx_lenbuf = len;
    Usart485.tx_pointer = 0;

    //LATA &= ~0x04;
    TRANSMIT485();
    
    if(0 == PIE3bits.TX1IE)     //MLT: Is this necessary?
    {
        TX1REG = Usart485.buf485[Usart485.tx_pointer++];
    }
    PIE3bits.TX1IE = 1;
}

uint8_t Received485(void)
{
    uint8_t n; 
    if (stime > 27 && Usart485.rx_pointer)
    {
        Usart485.rx_lenbuf = Usart485.rx_pointer;
        Usart485.rx_pointer = 0;
        //Analizzare il pacchetto!
        n = Check485RX();
        return n;
    }
    if (Usart485.tx_pointer == Usart485.tx_lenbuf && Usart485.tx_pointer != 0 && PIE3bits.TX1IE == 0)
    {
        while (!TX1STAbits.TRMT);
        RECEIVE485();
    }
    return 0;
}


uint8_t Read485_len(void)
{
    return Usart485.rx_lenbuf;
}
