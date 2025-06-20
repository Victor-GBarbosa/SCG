#ifndef GAMEFEATURES_H
#define GAMEFEATURES_H


#include "deckManager.h"

void screen(Card *currentHand, Card *selectedHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips);
void confirmPlay(Card **selectedHand, Card **currentHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips);
void roundPlay (Card **selectedHand, Card **currentHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips);
void scoreHand(Card *currentHand, Card *selectedHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips);

#endif