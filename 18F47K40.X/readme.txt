>>Correzione bug array initialization:

https://www.microchip.com/forums/m965517.aspx
"Enter +nvmreg in the Project Properties XC8 global options->XC8 Linker->Additional Options->Errata box"

https://www.microchip.com/forums/m964177-p2.aspx#964223
<<Workaround was OK until I enabled internal EEPROM read/write.
Had to manually add  NVMCON1bits.NVMREG = 2; after each EEPROM Read/write.>>


>>Altro per IIC:


https://www.settorezero.com/wordpress/utilizzo-librerie-i2c-generate-dall-mplab-code-configurator-lettura-accelerometro/


https://microcontrollerslab.com/i2c-communication-pic-microcontroller/


https://www.vincenzov.net/tutorial/PIC18/i2c.htm
https://embetronicx.com/tutorials/microcontrollers/pic16f877a/pic16f877a-i2c-tutorial/#Master_Synchronous_Serial_Port_MSSP
https://stackoverflow.com/questions/63620541/interface-mcp7940n-with-pic18f24k40

QUI!
https://www.eevblog.com/forum/microcontrollers/does-everyone-seriously-write-their-own-i2c-library-for-pic-mcus/

