#include "at32f423.h"
#include "UserIdentifier.h"

#define UIDADR 0x1FFFF7E8 // UID地址

void ReadUID(uint16_t *uiddata)
{
    for (uint8_t i = 0; i < 6; i++)
    {
        *(uiddata + i) = *(uint16_t *)(UIDADR + 2 * i);
    }
}