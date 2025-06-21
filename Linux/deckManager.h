#ifndef DECKMANAGER_H
#define DECKMANAGER_H

#include <stdlib.h>


enum Naipe {
    PAUS = 0,
    ESPADAS,
    COPAS,
    OUROS
} Naipe;

typedef enum{
    HIGH_CARD,
    PAIR,
    TWO_PAIR,
    TRIPLE,
    STRAIGHT,
    FLUSH,
    FULL_HOUSE,
    STRAIGHT_FLUSH
} HandRank;

// enum Stamp { //não implementado
//     NONE = 0
// } Stamp;

typedef struct Card{
    enum Naipe naipe;
    int rank;
    // enum Stamp stamp; //não implementado

    int id;
    struct Card* next;
    struct Card* prev;
} Card;

Card *createDeck ();
void clearDeck(Card **baralho);
void showCard(Card *card);
void debugCard(Card *card);
void showDeck (Card *baralho);
void showDeckAll (Card *baralho);
Card *pickById(Card **baralho, int id);
void removeById(Card **baralho, int id);
Card *pickLast(Card **baralho);
void insertLast(Card **baralho, Card *nCard);
int getSize (Card *baralho);
void shuffle (Card **baralho_ptr);
void idRegulator(Card **baralho);

#endif