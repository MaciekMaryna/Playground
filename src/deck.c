#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <config.h>

#include "deck.h"

/******************************************************************************
 * Function Swap
 ******************************************************************************/
static inline void Swap(uint8_t* a, uint8_t* b)
{
#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step into --->>> Swap function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */
    uint8_t tmp = *a;
    *a = *b;
    *b = tmp;
#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step out  <<<--- Swap function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */    
}

/******************************************************************************
 * Function InitRandomization
 ******************************************************************************/
static void InitRandomization()
{
#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step into --->>> InitRandomization function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */

    srand(time(NULL));

#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step out  <<<--- InitRandomization function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */

}

/******************************************************************************
 * Function Deck_Show
 ******************************************************************************/
void Deck_Show(uint8_t* deck, uint8_t number)
{
#if (DECK_DEBUG_MODE == DEBUG_ON)
    printf("INFO: Step into --->>> Deck_Show function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */
    for (int i = 0; i < number; i++)
    {
        printf("%d  ", deck[i]);
    }
    printf("\r\n");

#if (DECK_DEBUG_MODE == DEBUG_ON)
    printf("INFO: Step out  <<<--- Deck_Show function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */

}

/******************************************************************************
 * Function Deck_Fill
 ******************************************************************************/
void Deck_Fill(uint8_t* deck, uint8_t number)
{
#if (DECK_DEBUG_MODE == DEBUG_ON)
    printf("INFO: Step into --->>> Deck_Fill function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */

    for (int i = 0; i < number; i++)
    {
        deck[i] = i + 1;
    }

#if (DECK_DEBUG_MODE == DEBUG_ON)
    printf("INFO: Step out  <<<--- Deck_Fill function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */
}

/******************************************************************************
 * Function Deck_Init
 ******************************************************************************/
uint8_t* Deck_Init(uint8_t numCards)
{
#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step into --->>> Deck_Init.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */

    uint8_t* result = (uint8_t*)(malloc(numCards * sizeof(uint8_t)));

#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step out  <<<--- Deck_Init.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */

    return result;
}

/******************************************************************************
 * Function Deck_Shuffle
 ******************************************************************************/
void Deck_Shuffle(uint8_t* deck, uint8_t numCards)
{
#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step into --->>> Deck_Shuffle function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */    

    for (uint8_t i = 0; i < numCards; i++)
    {
        Swap(&deck[i], &deck[rand() % numCards]);
    }

#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step out  <<<--- Deck_Shuffle function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */      
}

/******************************************************************************
 * Function Deck_SortCardsUp
 ******************************************************************************/
void Deck_SortCardsUp(uint8_t* deck, uint8_t numCards)
{
#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step into --->>> Deck_SortCardsUp function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */       

    bool wasSwaped;
    do {
        wasSwaped = false;
        for (uint8_t i = 0; i < numCards - 1; i++)
        {
            if (deck[i] > deck[i + 1])
            {
                Swap(&deck[i], &deck[i + 1]);
                wasSwaped = true;
            }
        }
    } while (true == wasSwaped);
#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step out  <<<--- Deck_SortCardsUp function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */   
}

/******************************************************************************
 * Function Deck_SortCardsDown
 ******************************************************************************/
void Deck_SortCardsDown(uint8_t* deck, uint8_t numCards)
{
#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step into --->>> Deck_SortCardsDown function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */       

    bool wasSwaped;
    do {
        wasSwaped = false;
        for (uint8_t i = 0; i < numCards - 1; i++)
        {
            if (deck[i] < deck[i + 1])
            {
                Swap(&deck[i], &deck[i + 1]);
                wasSwaped = true;
            }
        }
    } while (true == wasSwaped);
#if (DECK_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Step out  <<<--- Deck_SortCardsDown function.\r\n");
#endif /* (DECK_DEBUG_MODE == DEBUG_ON) */   
}