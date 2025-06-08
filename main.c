#include <stdio.h>
#include <stdlib.h>
#include "gameFeatures.h"

int main () {

    Card *baralho = NULL;

    baralho = createDeck();
    shuffle(&baralho);

    int handSize = 8;

    Card *pHand[handSize];

    for (int i = 0; i < 8; i++) {
        pHand[i] = pickLast(&baralho);
    }

    screen(pHand, handSize);
}