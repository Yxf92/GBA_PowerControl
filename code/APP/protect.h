#ifndef __PROTECT_H__
#define __PROTECT_H__

#include "at32f423.h"

extern float Volbus, V3bus;

void TPS54302_Set_VBAT(uint8_t mode);
void PROTECT_Loop(void);
#endif
