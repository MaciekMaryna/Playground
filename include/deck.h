#ifndef DECK_H
#define DECK_H

#include <stdint.h>

void Deck_Show(uint8_t*, uint8_t);
void Deck_Fill(uint8_t*, uint8_t);
uint8_t* Deck_Init(uint8_t);
void Deck_Shuffle(uint8_t*, uint8_t);
void Deck_SortCardsUp(uint8_t*, uint8_t);
void Deck_SortCardsDown(uint8_t*, uint8_t);

#endif /* #ifndef DECK_H */
