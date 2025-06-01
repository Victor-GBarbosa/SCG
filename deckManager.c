#include "deckManager.h"

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
            
            if (head == NULL) {
                head = newCard;
                head->next = NULL;
            } else {              
                current->next = newCard;
                current = newCard;                
            }
            
           
        }
    }

    return head;
}