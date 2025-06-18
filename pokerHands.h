#include "deckManager.h"

HandRank handRankChecker(Card *selectedHand);

// Funções auxiliares
int isFlush(int suitCount[]);
int isStraight(int ranks[]);
int isFullHouse(int rankCount[]);
int isTwoPair(int rankCount[]);
int isPair(int rankCount[]);
void sortArray(int arr[], int size);