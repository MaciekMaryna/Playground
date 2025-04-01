#include <stdio.h>
#include "multable.h"

static void multable_SetColor(const int color_code)
{
    printf("\033[%dm", color_code);
}

void multable_ShowMulTable(void)
{
    multable_SetColor(COLOR_GREEN);

    for (int i = 0; i < MAX_VAL; i++)
    {
        printf("\t%3d", i + 1);
    }
    printf("\n");

    for(int j = 0; j < MAX_VAL; j++)
    {
        multable_SetColor(COLOR_GREEN);
        printf("%3d\t", j + 1);

        multable_SetColor(COLOR_WHITE);
        for (int i = 0; i < MAX_VAL; i++)
        {
            printf("%3d\t", (i + 1) * (j + 1));
        }
        printf("\n");
    }
}