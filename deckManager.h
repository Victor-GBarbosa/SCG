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
    struct Card* prev;
} Card;

Card *createDeck ();
void showCard(Card *card);
void showDeck (Card *baralho);