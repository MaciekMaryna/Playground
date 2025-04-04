/******************************************************************************
 * Project: Playground
 * Description: Training exercises
 * Start data: 03.04.2025r.
 * Author: Maciej Marynowski
 ******************************************************************************/

/******************************************************************************
 * Common includes
 ******************************************************************************/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
/******************************************************************************
 * Project specyfic includes
 ******************************************************************************/
#include "config.h"
#include "multable.h"
#include "ring.h"
#include "deck.h"

/******************************************************************************
 * Macros
 ******************************************************************************/

/******************************************************************************
 * Main Module functions
 ******************************************************************************/

/******************************************************************************
 * Main function
 ******************************************************************************/
int main()
{
#if (MAIN_DEBUG_MODE == DEBUG_ON)    
    printf("INFO: Start main function.\r\n");
#endif /* (MAIN_DEBUG_MODE == DEBUG_ON) */
    
    uint8_t* MyDeck = Deck_Init(DECK_NUMBER_OF_CARDS);
    Deck_Fill(MyDeck, DECK_NUMBER_OF_CARDS);
    Deck_Show(MyDeck, DECK_NUMBER_OF_CARDS);

    Deck_Shuffle(MyDeck, DECK_NUMBER_OF_CARDS);
    Deck_Show(MyDeck, DECK_NUMBER_OF_CARDS);

    Deck_SortCardsUp(MyDeck, DECK_NUMBER_OF_CARDS);
    Deck_Show(MyDeck, DECK_NUMBER_OF_CARDS);

    Deck_SortCardsDown(MyDeck, DECK_NUMBER_OF_CARDS);
    Deck_Show(MyDeck, DECK_NUMBER_OF_CARDS);    

#if (MAIN_DEBUG_MODE == DEBUG_ON)
    printf("INFO: The end of main function.\r\n");
#endif /* (MAIN_DEBUG_MODE == DEBUG_ON) */

    return 0;
}