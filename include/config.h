#ifndef CONFIG_H
#define CONFIG_H

#define TRUE    (1)
#define FALSE   (0)

#define DEBUG_ON    (TRUE)
#define DEBUG_OFF   (FALSE)

/******************************************************************************
 * Main Configuration
 ******************************************************************************/
#define MAIN_DEBUG_MODE     (DEBUG_OFF)

/******************************************************************************
 * Mutable Module Configuration
 ******************************************************************************/
#define MUTABLE_DEBUG_MODE     (DEBUG_ON)

/******************************************************************************
 * Ring Module Configuration
 ******************************************************************************/
#define RING_DEBUG_MODE     (DEBUG_ON)

/******************************************************************************
 * Deck Module Configuration
 ******************************************************************************/
#define DECK_DEBUG_MODE         (DEBUG_OFF)
#define DECK_NUMBER_OF_CARDS    (24)

#endif /* #ifndef CONFIG_H */
