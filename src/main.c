#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "multable.h"
#include "ring.h"
#include "config.h"

void Show()
{
    printf("Show something.\r\n");
}

int main()
{
#if (MAIN_DEBUG_MODE == DEBUG_ON)    
    printf("MAIN: Start.\r\n");
#endif /* (MAIN_DEBUG_MODE == DEBUG_ON) */

    Show();
#if (MAIN_DEBUG_MODE == DEBUG_ON)
    printf("MAIN: The end.\r\n");
#endif /* (MAIN_DEBUG_MODE == DEBUG_ON) */

    return 0;
}