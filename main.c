#include <stdio.h>
#include <stdlib.h>
#include "gameFeatures.h"

int main () {

    Card *baralho = NULL, *selectedHand = NULL, *currentHand = NULL;
    int *poitns, *mult, *ypoints, *hands, *discarts;

    baralho = createDeck();
    shuffle(&baralho);

    int handSize = 8;

    // Criar currentHand como lista ligada
    for (int i = 0; i < handSize; i++) {
        Card *newCard = pickLast(&baralho);
        insertLast(&currentHand, newCard);
    }
    idRegulator(&currentHand);

    // screen(currentHand, selectedHand);
    
    while(1) {roundPlay(&selectedHand, &currentHand);}
    
    // showDeck(currentHand[0]);
    system("pause");
}