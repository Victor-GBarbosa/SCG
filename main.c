#include <stdio.h>
#include <stdlib.h>
#include "gameFeatures.h"

int main () {

    Card *baralho = NULL, *selectedHand = NULL;
    int *poitns, *mult, *ypoints, *hands, *discarts;

    baralho = createDeck();
    shuffle(&baralho);

    int handSize = 8;

    Card *currentHand[handSize];
    

    for (int i = 0; i < 8; i++) {
        currentHand[i] = pickLast(&baralho);
        if (i == 0) {
            currentHand[i]->prev = NULL;
            currentHand[i]->next = NULL;
        } else {
            currentHand[i]->prev = currentHand[i-1];
            currentHand[i]->prev->next = currentHand[i];
        }
        currentHand[i]->id = i + 1;
    }

    // screen(currentHand, selectedHand);
    while(1) {roundPlay(selectedHand, currentHand[0]);}
    
    // showDeck(currentHand[0]);
    system("pause");
}