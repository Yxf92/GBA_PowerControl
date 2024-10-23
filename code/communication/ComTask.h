#ifndef __COMTASK_H__
#define __COMTASK_H__

#include "at32f423.h"

typedef struct
{
   uint8_t msgid;
   uint8_t data;
} Message_t;

typedef enum
{
   MESSAGE_NONE = 0,
   MESSAGE_HADE,
   MESSAGE_DATA,
   MESSAGE_TELL,
   MESSAGE_OK,
} Message_status;

void _handle_msg(Message_t *message);
uint8_t mavlink_parse_char (uint8_t data, Message_t *msg, uint8_t status);

#endif
