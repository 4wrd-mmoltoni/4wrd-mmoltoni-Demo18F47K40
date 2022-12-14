#include <string.h>
#include "Function485.h"
#include "485.h"
#include "algorithm.h"
#include "mcc_generated_files/mcc.h"
#include "Utils.h"
#include "Measure.h"
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

//Torna la lunghezza di quanto inviare via COMM ?
uint8_t Check485RX()
{
    uint16_t crc = CRC161(Usart485.buf485, (uint8_t)Usart485.rx_lenbuf);
    if (crc != 0)
        return 0;
    
    uint8_t addr    = Usart485.buf485[0];
    uint8_t funct   = Usart485.buf485[1];             //funzione
    uint8_t buf[256];
    uint16_t n;    
            
    if (!(    (addr == MDB_addr)        //ind diretto
          ||  (addr == 0xFF)            //broadcast
          ||  (MDB_addr == '0' && funct == COMM_FNC_SET_ADDR) 
          ) )
        return 0;
            
    uint8_t payload = Usart485.buf485[2];             //payload in ricezione  
    uint8_t *payl_answ = &Usart485.buf485[2];         //ind payload in risposta  
    uint8_t *data   = &Usart485.buf485[3];            //ind data in TX/RX
    uint8_t *p = data;                                //temporary data pointer
    uint16_t t1, t2;                                  //temporary
    
    uint8_t answLen = 3;                              //minimi caratteri di ritorno: addr, function, payload (anche se 0!)
    
    switch (funct)
    {
        /* DEBUG FUNCTIONS*/
        case COMM_FNC_SET_485_BRIDGE:                 //Forza lo stato dell'ancora: 1 = battezzata, 0 = non.  
            t1 = payload;
            if (t1 == '0')
            {
            	RS485_CMD_SetLow();
            }
            else
            {
            	RS485_CMD_SetHigh();
            }
            *payl_answ = 0;
            answLen += *payl_answ;
            break;

        case COMM_FNC_READRAW_MEASURE:
            if (MeasureBusy())
            {
                *payl_answ = 1;
                *data = 'B';
            }
            else
            {
                *payl_answ = 6*2;
                memcpy(data, (char*)&measureVect[0], 6*2);
            }
        	answLen += *payl_answ;
        	break;
            
        case COMM_FNC_RESET_ADDR:
            MDB_addr = '0';
            ShowAddr(MDB_addr-'0');
            BAPTESIM_NOK;
            return 0;         //COmando BROADCAST o comunque senza risposta. SOlop er debug!
        
        /* BAPTESIM FUNCTIONS*/
        case COMM_FNC_SET_ADDR:
            if (MDB_addr == '0')                      //Non � inizializzato: devo settarmi
            {
                t1 = *(data);
                t1 -= '0';
                t2 = *(data+1);
                t2 -= '0';
                t1 = (t1*10) + t2 + '0';              //t1 contiene il nuovo indirizzo in ASCII
                t2 = ReadEEpromMDB_Addr();
                *(data++) = t2;
                *payl_answ = 1;
                answLen += *payl_answ;
                MDB_addr = t1;
                Usart485.buf485[0] = t1;
                WriteEEpromMDB_Addr(MDB_addr-'0');
                BAPTESIM_OK;                          //BATTEZZATO!
                ShowAddr(MDB_addr-'0');
            }
            else
            {
//                *(data++) = MDB_addr + '0';          //T2 in formato 2 cifre
//                *payl_answ = 1;
//                answLen += *payl_answ;               // debug only!
                
            	//NON deve rispondere! risponder� il successivo (se esiste) etc!!!
            	return 0;
            }
            break;
            
        case COMM_FNC_GET_DIAG:
            for (n = 0; n < 7; n++)
                *(data++) =1 + '0';
            t2 = (uint8_t)ErrorVect.bConverter.b;
            //*(data++) = (t2>>4) + '0';
            //*(data++) = (t2&0x0F) + '0';
            ErrorVect.bProcessor.b = PCON0;
            t2 = ErrorVect.bProcessor.b;
#warning CORREGGERE!
            *(data++) = (t2>>4) + '0';
            *(data++) = (t2&0x0F) + '0';
            
            *payl_answ = 7+2;
            answLen += *payl_answ;
            break;
            
        case COMM_FNC_RESET_DIAG:
            *payl_answ = 1;
            *(data++) = PCON0;
            answLen += *payl_answ;
            break;
            
        case COMM_FNC_SET_TRESHOLD:
            t1 = *(data++);
            t2 = *(data++);
            treshold = (t2<<8)+t1;
            // scrivi in flash!
            *payl_answ = 0;
            answLen += *payl_answ;
            break;
            
        case COMM_FNC_GET_TRESHOLD:
            *(data++) = treshold>>8;
            *(data++) = treshold&0xFF;
            *payl_answ = 2;
            answLen += *payl_answ;            
            break;
        
        case COMM_FNC_GET_FW_VERSION:
            *payl_answ = 6;
            *(data++) = 'A';
            *(data++) = 'P';
            *(data++) = 'P';
            *(data++) = MAJOR_VERSION + '0';
            *(data++) = MINOR_VERSION/10 + '0';
            *(data++) = MINOR_VERSION%10 + '0';
            answLen += *payl_answ;
            break;
        
        case COMM_FNC_SET_STRING:            
            WriteConfigSTR(data, payload);
            *payl_answ = 0;
            answLen += *payl_answ;
            break;
            
        case COMM_FNC_GET_STRING:
            *payl_answ = 64;
            ReadConfigSTR(data, *payl_answ);
            answLen += *payl_answ;
            break;
            
/////////////////////BOOTLOADER - TEST!////////////////////////////////////////            
            
        case COMM_FNC_WRITEFLASH:
            t1  = *(data++);
            t1 <<= 8;
            t1 |= *(data++);
            t2 = 0;
            if (payload == 2)
            	FLASH_EraseBlock(t1);
            else
            	t2 = FLASH_WriteBlock(t1, data);
            *p = (uint8_t)t2;
            *payl_answ = 1;
            answLen += *payl_answ;
            break;
            
        case COMM_FNC_CALCCRC:
            t1  = *(data++);
            t1 <<= 8;
            t1 |= *(data++);        //start addr
            t2  = *(data++);
            t2 <<= 8;
            t2 |= *(data++);        //length
            t2 += t1;               //end point per il ciclo for pi� sotto
            CRC162(buf, 256, 1);    //erase value
            for (n = t1; n <= t2; n += 0x80)
            {
                FLASH_ReadSector64k(buf, n);
                crc = CRC162(buf, 128, 0);
            }
            *(p++) = crc>>8;
            *(p++) = crc;
            *payl_answ = 2;
            answLen += *payl_answ;
            break;

///////////////////////MEASUREMENT/////////////////////////////////////////////

        case COMM_FNC_EXEC_MEASURE:
        	//start relays multiplexing & read!
        	t1 = payload;
        	*payl_answ = 0;
        	answLen += *payl_answ;
            StartMeasure();
        	break;

        case COMM_FNC_READ_MEASURE:
            if (MeasureBusy())
            {
                *payl_answ = 1;
                *data = 'B';
            }
            else
            {
                ConvertMeasureToStr(measureVect, buf);
                n = strlen(buf);
                memcpy(data, buf, n);
                *payl_answ = n;
            }
        	answLen += *payl_answ;
        	break;

/////////////////////////OTHER//////////////////////////////////////////////////

        case COMM_FNC_GOTO_BOOTLOADER:		/*Bootloader only*/
            // write to EEPROM!
            DATAEE_WriteByte(BOOTLOADER_KEEPINBOOT_ADDR, KEEPBOOT_MAGICNUMBER);
        case COMM_FNC_REBOOT:
        	*payl_answ = 0;
            ResetRequest();
            answLen += *payl_answ;
            break;
            
        case COMM_FNC_CUSTOM1:
            *payl_answ = 0;
            testfnc();
            answLen += *payl_answ;
            break;

        default:
            strcpy(data, "FUNCTION NOT IMPLEMENTED");
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
