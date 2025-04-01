#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "multable.h"
#include "ring.h"

#define BUFFER_LEN  (8)

int main()
{
    printf("MAIN: Start.\r\n");
    
    Ring_BufferHandler_t MyBuffer;
    Ring_InitBuffer(&MyBuffer, BUFFER_LEN);
    Ring_FlushBuffer(&MyBuffer);
    Ring_KillBuffer(&MyBuffer);

    printf("MAIN: The end.\r\n");
    return 0;
}