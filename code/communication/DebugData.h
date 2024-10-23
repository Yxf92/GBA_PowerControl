#ifndef __DEBUGDATA_H__
#define __DEBUGDATA_H__

#include "at32f423.h"
#include "main.h"

void SendDebugDataInit(void);
void DefaultSendDebugData(void);
void RecoverySendDebugData(void);
void PacketDebugData0(void);
void RF_ComData(char *SendArry);
void SendOneTime( uint8_t *data, uint8_t lenth);
void SendDebugData(void);
#endif
