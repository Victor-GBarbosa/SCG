#include <stdio.h>
#include "deckManager.h"

int main () {

    Card *baralho = NULL;

    baralho = createDeck();

    // showDeck(baralho);

    int id = 50;

    showDeck(baralho);

    printf("-------Carta selecionada-------\n\n");

    // showCard(pickById(baralho, id));
    showCard(pickLast(&baralho)); //Rei de ouros

    showDeck(baralho);

    return 0;
}

