#include <stdio.h>
#include "deckManager.h"

int main () {

    Card *baralho = NULL;

    Card *curinga = malloc(sizeof(Card));
    
    curinga->id = 69;
    curinga->rank = 13;
    curinga->naipe = 2;
    curinga->next = NULL;


    baralho = createDeck();

    // showDeck(baralho);

    int id = 50;

    showDeck(baralho);

    printf("-------Carta selecionada-------\n\n");

    // showCard(pickById(baralho, id));
    showCard(pickLast(&baralho)); //Rei de ouros

    insertLest(&baralho, curinga);

    showDeck(baralho);

    return 0;
}

