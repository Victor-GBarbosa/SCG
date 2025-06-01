#include <stdlib.h>


enum Naipe {
    PAUS = 0,
    ESPADAS,
    COPAS,
    OUROS
} Naipe;

enum Stamp {
    NONE = 0
} Stamp;

typedef struct Card{
    enum Naipe naipe;
    int rank;
    enum Stamp stamp;

    struct Card* next;
} Card;

Card *createDeck () {
    Card *head = NULL;
    Card *current = NULL;

    for (int j = 0; j < 4; j++) {
        for (int i = 1; i < 14; i++) {
            Card *newCard = (Card*)malloc(sizeof(Card));
            newCard->naipe = j;
            newCard->rank = i;
            newCard->stamp = 0;
            newCard->next = NULL;           
        }
    }

    return head;
}
