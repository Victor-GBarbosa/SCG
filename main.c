#include <stdio.h>
#include "deckManager.h"

int main () {

    Card *baralho = NULL;

    baralho = createDeck();

    showDeck(baralho);

    return 0;
}

