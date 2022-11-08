//algorithm.h
#ifndef __ALGORITHM_HLOOKUP_TABLE
#define __ALGORITHM_H

typedef unsigned long ulong;

//#define LOOKUP_TABLE

#ifdef LOOKUP_TABLE
#define MDB_CRC CRC161
#else
#define MDB_CRC CRC16
#endif

//ulong  CRC32(const ulong *pmsg, ulong msg_size);
#ifndef LOOKUP_TABLE
unsigned short CRC16(const unsigned char* puchMsg, unsigned short usDataLen);
#else
unsigned short CRC161(const  unsigned char* puchMsg, unsigned long usDataLen);
unsigned short CRC162(const  unsigned char* puchMsg, unsigned long usDataLen, char init);
#endif  //LOOKUP_TABLE

#endif