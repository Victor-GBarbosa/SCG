#ifndef GAMEFEATURES_H
#define GAMEFEATURES_H


#include "deckManager.h"

void screen(Card *currentHand, Card *selectedHand, Card *baralho, int hands, int discart, int score, int multi, int actualBlind);
void roundPlay (Card **selectedHand, Card **currentHand, Card *baralho, int hands, int discart, int score, int multi, int actualBlind);

#endif