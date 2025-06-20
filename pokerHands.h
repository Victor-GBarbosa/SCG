#include "deckManager.h"

HandRank handRankChecker(Card *selectedHand);


int isFlush(int suitCount[]);
int isStraight(int ranks[]);
int isFullHouse(int rankCount[]);
int isTriple(int rankCount[]);
int isTwoPair(int rankCount[]);
int isPair(int rankCount[]);
void sortArray(int arr[], int size);

void processHandModifiers(Card *selectedHand, int *chips, int *multi);