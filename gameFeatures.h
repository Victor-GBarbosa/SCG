#ifndef GAMEFEATURES_H
#define GAMEFEATURES_H

#define MAX_SAVES 10

#include "deckManager.h"
#include "pokerHands.h"

void screen(Card *currentHand, Card *selectedHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips);
void confirmPlay(Card **selectedHand, Card **currentHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips);
void roundPlay (Card **selectedHand, Card **currentHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips);
void scoreHand(Card *currentHand, Card *selectedHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips);
void saveGame(int round, int currentBlind, char *currentSave);
int loadGame(int *round, int *currentBlind, char *currentSave);
int validateSave(char *saveLine);
int countSaves();

#endif