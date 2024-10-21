#ifndef __LOOP_H__
#define __LOOP_H__

#include "at32f423.h"
#include "tim.h"
void OpenControlLoop(void);
void ControlLoop1(void);
void ControlLoop2(void);

#define MainLoopClose           \
    {                           \
        MainLoopTimeITClose;    \
        MainLoopTime->cval = 0; \
    }
#define MainLoopOpen            \
    {                           \
        MainLoopTimeITOpen;     \
        MainLoopTime->cval = 0; \
    }
#endif
