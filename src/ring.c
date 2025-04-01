#include <stdio.h>
#include <stdlib.h>
#include "ring.h"

#define DEBUG_ON        (TRUE)
#define DEBUG_OFF       (FALSE)

#define DEBUG_MOEDE     (DEBUG_ON)

/******************************************************************************
 * Function Ring_InitBuffer
 ******************************************************************************/
void Ring_InitBuffer(Ring_BufferHandler_t* handler, uint8_t number_of_elements)
{
    /* Important note: Lenght of buffer is number_of_elements plus one (!) 
    because additional position is necessary to maintain the ring buffer*/
    Ring_BufferElement_t* pBuffer = malloc((number_of_elements + 1) * sizeof(Ring_BufferElement_t));
    handler -> addr = pBuffer;
    handler -> head = pBuffer;
    handler -> tail = pBuffer;
    handler -> len = number_of_elements;

#if (DEBUG_MODE == DEBUG_ON)
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

#if (DEBUG_MODE == DEBUG_ON)
        printf("Error: Can't kill the buffer.\r\n");
#endif /* (DEBUG_MODE == DEBUG_ON) */      

    }
    else {  

#if (DEBUG_MODE == DEBUG_ON)   
        free(handler -> addr);        
        printf("INFO: Buffer successfully killed.\r\n");
#endif /* (DEBUG_MODE == DEBUG_ON) */
    }
}

void Ring_FlushBuffer(Ring_BufferHandler_t* handler)
{
    handler -> head = handler -> tail;
#if (DEBUG_MODE == DEBUG_ON)
    if (handler -> head != handler -> tail) 
    {
        printf("ERROR: Can't flush the buffer.\r\n");
    }
    else {
        printf("INFO: Buffer succesfuly flushed.\r\n");
    }

#endif /* (DEBUG_MODE == DEBUG_ON) */
    
}

/******************************************************************************
 * end of module
 ******************************************************************************/

// Ring_PutElement()
// Ring_GetElemet()
