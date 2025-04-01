#ifndef Ring_H
#define Ring_H

#include <stdint.h>

typedef uint8_t Ring_BufferElement_t;

typedef struct Ring_BufferHandler
{
    Ring_BufferElement_t* addr;
    Ring_BufferElement_t* head;
    Ring_BufferElement_t* tail;
    uint16_t len;
} Ring_BufferHandler_t;

void Ring_InitBuffer(Ring_BufferHandler_t*, uint8_t);
void Ring_KillBuffer(Ring_BufferHandler_t*);
void Ring_FlushBuffer(Ring_BufferHandler_t*);

#endif /* #ifndef Ring_H */