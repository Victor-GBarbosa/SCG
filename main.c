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


    // showCard(pickById(baralho, id)); // testar novamente

    //-------Teste getSize

    shuffle(&baralho);
    idRegulator(&baralho);

    showDeck(baralho);

    printf("%i", getSize(baralho));

    return 0;
}

