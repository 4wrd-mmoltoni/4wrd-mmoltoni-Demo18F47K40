#include <string.h>
#include "Function485.h"
#include "485.h"
#include "algorithm.h"
#include "mcc_generated_files/mcc.h"
#include "Utils.h"

#include "DobleFN_Def.h"

//
//	Global variable - to be exported!
//
uint8_t MDB_addr = '0';         //Deve essere 0!
//uint8_t Baptesim = 0;           //0: default, non assegnato, �ncora tirata
                                //1: assegnato, �ncora rilasciata

//
//	Local variable
//

extern char IIC_REQ;


//Torna la lunghezza di quanto inviare via COMM ?
uint8_t Check485RX()
{
    uint16_t crc = CRC161(Usart485.buf485, (uint8_t)Usart485.rx_lenbuf);
    if (crc != 0)
        return 0;
    
    uint8_t addr    = Usart485.buf485[0];
    uint8_t funct   = Usart485.buf485[1];             //funzione
    
    /*
    if ( (      !(addr == MDB_addr || addr == 0xFF))  
            &&  !(MDB_addr == '0' && funct == COMM_FNC_SET_485_BRIDGE)  )       //Note: broadcast!
        return 0;
    */
            
    if (!(    (addr == MDB_addr)        //ind diretto
          ||  (addr == 0xFF)            //broadcast
          ||  (MDB_addr == '0' && funct == COMM_FNC_SET_ADDR) 
          ) )
        return 0;
            
    uint8_t payload = Usart485.buf485[2];             //payload in ricezione  
    uint8_t *payl_answ = &Usart485.buf485[2];         //ind payload in risposta  
    uint8_t *data   = &Usart485.buf485[3];            //ind data in TX/RX  
    uint16_t t1, t2;    //temporary
    
    uint8_t answLen = 3;                              //minimi caratteri di ritorno: addr, function, payload (anche se 0!)  
    
    switch (funct)
    {
        case COMM_FNC_SET_485_BRIDGE:                 //Forza lo stato dell'ancora: 1 = battezzata, 0 = non.  
            t1 = payload;
            /*
            if (t1 == '0')
                LED_Blu_SetLow();
            else
                LED_Blu_SetHigh();
            */ 
            *payl_answ = 0;
            answLen += *payl_answ;
            break;
        
        case COMM_FNC_SET_ADDR:
            if (MDB_addr == '0')                      //Non � inizializzato: devo settarmi
            {
                t1 = *(data);
                t1 -= '0';
                t2 = *(data+1);
                t2 -= '0';
                t1 = (t1*10) + t2 + '0';              //t1 contiene il nuovo indirizzo in ASCII
                t2 = ReadEEpromMDB_Addr();
                *(data++) = (t2>>4) + '0';
                *(data++) = (t2&0x0F) + '0';          //T2 in formato 2 cifre
                *payl_answ = 2;
                answLen += *payl_answ;
                MDB_addr = t1;
                WriteEEpromMDB_Addr(MDB_addr);
                //LED_Blu_SetLow();                   //�ncora rilasciata, battezzato!
            }
            else
            {
//                *(data++) = MDB_addr + '0';          //T2 in formato 2 cifre
//                *payl_answ = 1;
//                answLen += *payl_answ;
            	//NON deve rispondere! risponderà il successivo (se esiste) etc!!!
            	return 0;
            }
            break;
            
        case COMM_FNC_GET_DIAG:
            //  *(data++) = LED_Blu_GetValue()+'0';
            *(data++) = 0 + '0';
            t2 = (uint8_t)ErrorVect.bConverter.b;
            *(data++) = (t2>>4) + '0';
            *(data++) = (t2&0x0F) + '0';
            t2 = ErrorVect.bProcessor.b;
            *(data++) = (t2>>4) + '0';
            *(data++) = (t2&0x0F) + '0';
            
            *payl_answ = 1+2+2;
            answLen += *payl_answ;
            break;
            
        case COMM_FNC_RESET_DIAG:
            //PCON0 = 0;
            *payl_answ = PCON0;
            answLen += *payl_answ;
            break;
        
        case COMM_FNC_GET_FW_VERSION:
            *payl_answ = 6;
            *(data++) = 'A';
            *(data++) = 'P';
            *(data++) = 'P';
            *(data++) = MAIOR_VERSION + '0';
            *(data++) = MINOR_VERSION/10 + '0';
            *(data++) = MINOR_VERSION%10 + '0';
            answLen += *payl_answ;
            
            IIC_REQ = 1;
            
            break;
        
        case COMM_FNC_SET_STRING:            
//            ind = START_CONFIG_STR_ADDR;
//            for (int n = 0; n < payload; n++)
//                DATAEE_WriteByte(ind++, *(data++));
            WriteConfigSTR(data, payload);
            *payl_answ = 0;
            answLen += *payl_answ;
            break;
            
        case COMM_FNC_GET_STRING:
            *payl_answ = 64;
//            ind = START_CONFIG_STR_ADDR;
//            for (int n = 0; n < 64; n++)
//                *(data++) = DATAEE_ReadByte(ind++);
            ReadConfigSTR(data, *payl_answ);
            answLen += *payl_answ;
            break;
            
        case COMM_FNC_REBOOT:
        	*payl_answ = 0;
            ResetRequest();
            answLen += *payl_answ;
            break;
            
        case COMM_FNC_GOTO_BOOTLOADER:
        	*payl_answ = 0;
            // write to EEPROM!
            DATAEE_WriteByte(BOOTLOADER_KEEPINBOOT_ADDR, KEEPBOOT_MAGICNUMBER);
            ResetRequest();
            answLen += *payl_answ;
            break;

        default:
            strcpy(data, "FUNCTION NOT IMPLEMENTED (YET)");
            *payl_answ = strlen(&Usart485.buf485[3]);
            answLen += *payl_answ;
            break;
            
    }   //end switch funct
    
    if (addr == 0xFF)       //Broadcast !
        return 0;
    
    Usart485.tx_lenbuf = answLen;
    crc = CRC161((uint8_t*)&Usart485.buf485, (uint8_t)Usart485.tx_lenbuf);
    Usart485.buf485[Usart485.tx_lenbuf++] = crc>>8;
    Usart485.buf485[Usart485.tx_lenbuf++] = crc;
    
    Usart485.tx_pointer = 0;
    return Usart485.tx_lenbuf;
}
