#ifndef Ring_H
#define Ring_H

#include <stdint.h>

typedef uint8_t Ring_BufferElement_t;

typedef struct Ring_BufferHandler
{
    Ring_BufferElement_t* addr;
    uint8_t head;
    uint8_t tail;
    uint8_t len;
} Ring_BufferHandler_t;

typedef enum
{
    OPERATION_OK = 0,
    BUFFER_OVERRIDE,
    Buffer_EMPTY,
    NUMBER_OF_STATUS_CODES
 } Status_t;

void Ring_InitBuffer(Ring_BufferHandler_t*, uint8_t);
void Ring_KillBuffer(Ring_BufferHandler_t*);
void Ring_FlushBuffer(Ring_BufferHandler_t*);
Status_t Ring_PutElement(Ring_BufferHandler_t*, Ring_BufferElement_t);
Status_t Ring_GetElement(Ring_BufferHandler_t*, Ring_BufferElement_t*);


#endif /* #ifndef Ring_H */