#include <stdio.h>
#include <stdlib.h>
#include "ring.h"
#include "config.h"

/******************************************************************************
 * Function Ring_InitBuffer
 ******************************************************************************/
void Ring_InitBuffer(Ring_BufferHandler_t* handler, uint8_t number_of_elements)
{
    /* Important note: Lenght of buffer is number_of_elements plus one (!) 
    because additional position is necessary to maintain the ring buffer*/
    Ring_BufferElement_t* pBuffer = malloc((number_of_elements + 1) * sizeof(Ring_BufferElement_t));
    handler -> addr = pBuffer;
    handler -> head = 0;
    handler -> tail = 0;
    handler -> len = number_of_elements;

#if (RING_DEBUG_MODE == DEBUG_ON)
    if (NULL == pBuffer)
    {
        printf("ERROR: Can't allocate memory.\r\n");
    }
    else
    {
        printf("INFO: Buffer of %d elements initializated succecfully on address: 0x%X.\r\n", number_of_elements, pBuffer);
    }   
#endif    
}

/******************************************************************************
 * Function Ring_KillBuffer
 ******************************************************************************/
void Ring_KillBuffer(Ring_BufferHandler_t* handler)
{   
    if (NULL == handler -> addr) {

#if (RING_DEBUG_MODE == DEBUG_ON)
        printf("Error: Can't kill the buffer.\r\n");
#endif /* (RING_DEBUG_MODE == DEBUG_ON) */      

    }
    else {  

#if (RING_DEBUG_MODE == DEBUG_ON)   
        free(handler -> addr);        
        printf("INFO: Buffer successfully killed.\r\n");
#endif /* (RING_DEBUG_MODE == DEBUG_ON) */
    }
}

void Ring_FlushBuffer(Ring_BufferHandler_t* handler)
{
    handler -> head = handler -> tail;

#if (RING_DEBUG_MODE == DEBUG_ON)
    if (handler -> head != handler -> tail) 
    {
        printf("ERROR: Can't flush the buffer.\r\n");
    }
    else {
        printf("INFO: Buffer successfully flushed.\r\n");
    }

#endif /* (RING_DEBUG_MODE == DEBUG_ON) */
}

/******************************************************************************
 * Function Ring_PutElement
 ******************************************************************************/
Status_t Ring_PutElement(Ring_BufferHandler_t* handler, Ring_BufferElement_t value)
{
    Status_t result = OPERATION_OK;

    uint8_t newHaed = (handler -> head + 1) % handler -> len;

    if (newHaed == handler -> tail)
    {
        handler -> tail = (handler -> tail + 1) % handler -> len;
        result = BUFFER_OVERRIDE;
    }        

    *(handler -> addr + handler -> head) = value;
    handler -> head = newHaed;

    return result;
}

/******************************************************************************
 * Function Ring_GetElemet
 ******************************************************************************/
Status_t Ring_GetElement(Ring_BufferHandler_t* handler, Ring_BufferElement_t* pValue)
{
    Status_t result = OPERATION_OK;

    *(pValue) = *(handler -> addr + handler -> tail);
    if (handler -> tail == handler -> head) 
    {
        result = Buffer_EMPTY;
    } 
    else
    {
        handler -> tail = (handler -> tail + 1) % handler -> len;
    }

    return result;
}

/******************************************************************************
 * end of module
 ******************************************************************************/

