#include <stdio.h>
#include <stdlib.h>
#include "gameFeatures.h"

int main () {

    Card *baralho = NULL, *selectedHand = NULL, *currentHand = NULL;
    int actualBlind = 1000, multi = 0, score = 0, hands = 4, discarts = 4, chips = 0;

    baralho = createDeck();
    shuffle(&baralho);

    int handSize = 8;

    // Criar currentHand como lista ligada
    for (int i = 0; i < handSize; i++) {
        Card *newCard = pickLast(&baralho);
        insertLast(&currentHand, newCard);
    }    
      idRegulator(&currentHand);    // screen(currentHand, selectedHand, baralho, &hands, &discarts, &score, &multi, &actualBlind, &chips);
    
    while(1) {
        system("cls");
        roundPlay(&selectedHand, &currentHand, baralho, &hands, &discarts, &score, &multi, &actualBlind, &chips);
    }
    
    // showDeck(currentHand[0]);
    system("pause");
}