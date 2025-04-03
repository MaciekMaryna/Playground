#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "multable.h"
#include "ring.h"
#include "config.h"

#define BUFFER_LEN  (8)

void Show(Ring_BufferHandler_t* handler)
{
    printf("Buffer address:         0x%8X\r\n", handler -> addr);
    printf("Head:                   %3d | ", handler -> head);
    printf("Tail:                   %3d\r\n", handler -> tail);
    printf("Value[Head]:            %3d | ", *(handler -> addr + handler -> head));
    printf("Value[Tail]:            %3d\r\n", *(handler -> addr + handler -> tail));       
    printf("Value[Head-1]:          %3d | ", *(handler -> addr + (handler -> head - 1) % handler -> len));
    printf("Value[Tail-1]:          %3d\r\n", *(handler -> addr + (handler -> tail - 1) % handler -> len));    

    for (int i = 0; i < BUFFER_LEN; i++)
    {
        printf("%3d\t", *(handler -> addr + i));    
    }
    printf("\r\n\n");        
}

int main()
{
#if (MAIN_DEBUG_MODE == DEBUG_ON)    
    printf("MAIN: Start.\r\n");
#endif /* (MAIN_DEBUG_MODE == DEBUG_ON) */

    Ring_BufferHandler_t MyBuffer;
    Ring_InitBuffer(&MyBuffer, BUFFER_LEN);

    Show(&MyBuffer);
    for (int i = 0; i < BUFFER_LEN + 2; i++)
    {
        printf("Last operation status:  %d\r\n", Ring_PutElement(&MyBuffer, (Ring_BufferElement_t)(100 + i)));
        Show(&MyBuffer);
    } 
    
    Ring_BufferElement_t MyData;
    for (int i = 0; i < BUFFER_LEN + 2; i++)
    {
        MyData = 100 + i;
        printf("Last operation status:  %d\r\n", Ring_GetElement(&MyBuffer, &MyData));
        Show(&MyBuffer);
    }     

    Ring_FlushBuffer(&MyBuffer);
    Ring_KillBuffer(&MyBuffer);

#if (MAIN_DEBUG_MODE == DEBUG_ON)
    printf("MAIN: The end.\r\n");
#endif /* (MAIN_DEBUG_MODE == DEBUG_ON) */

    return 0;
}