#include "at32f423.h"
#include "main.h"

#define entry_size  32
typedef struct
{
    uint16_t m_getIdx;
    uint16_t m_putIdx;
    uint8_t m_entry[entry_size];
} PC_Send_Stack;


#define datentry_size  256
typedef struct
{
    uint16_t m_getIdx;
    uint16_t m_putIdx;
    uint8_t m_entry[datentry_size];
} PC_Send_Dat;


#define PCBUF_Init( cbuf )       cbuf.m_getIdx = cbuf.m_putIdx = 0
#define PCBUF_Len( cbuf )        (( cbuf.m_putIdx ) - ( cbuf.m_getIdx ))
#define PCBUF_Push( cbuf, elem ) (cbuf.m_entry)[ cbuf.m_putIdx++ % entry_size ] = (elem)
#define PCBUF_Pop( cbuf )        (cbuf.m_entry)[ cbuf.m_getIdx++ % entry_size]

#define DATBUF_Len( cbuf )        (( cbuf.m_putIdx ) - ( cbuf.m_getIdx ))
#define DATBUF_Push( cbuf, elem ) (cbuf.m_entry)[ cbuf.m_putIdx++ % datentry_size ] = (elem)
#define DATBUF_Pop( cbuf )        (cbuf.m_entry)[ cbuf.m_getIdx++ % datentry_size]
#define PARAREDEUCE 10  //与上位机之间通讯的数据的缩放比，用于通讯使用
#define POWERREDUCE 100

void CarryoutOrder(uint8_t *data);


