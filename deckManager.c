#include "deckManager.h"
#include <stdio.h>

Card *createDeck () {
    Card *head = NULL;
    Card *current = NULL;
    Card *last = NULL

    for (int j = 0; j < 4; j++) {
        for (int i = 1; i < 14; i++) {
            Card *newCard = (Card*)malloc(sizeof(Card));
            newCard->naipe = j;
            newCard->rank = i;
            newCard->stamp = 0;

            newCard->next = NULL;
            newCard->prev = NULL;
            
            if (head == NULL) {
                head = newCard;
                current = head; //implementar um sistema que va e volte nas cartas
            } else {            //usando as posições next e prev, vai ser util para testes
                current->next = newCard;
                current = newCard;                
            }
        }
    }

    return head;
}

void showCard(Card *card) {
    switch (card->rank)
    {
    case 1:
        printf("As de ");
        break;

    case 11:
        printf("Valete de ");
        break;
   
    case 12:
        printf("Rainha de ");
        break;
   
    case 13:
        printf("Rei de ");
        break;
    
           
    default:
        printf("%i de ", card->rank);
        break;
    }

           switch (card->naipe)
       {
       case PAUS:
        printf("Paus\n");
        break;

       case ESPADAS:
        printf("Espadas\n");
        break;

       case OUROS:
        printf("Ouros\n");
        break;
        
       case COPAS:
        printf("Copas\n");
        break;

       default:
         printf("Naipe invalido\n");
        break;
       }
}

void showDeck (Card *baralho) {
    Card *current = baralho;

    while (current != NULL) {
       showCard(current);

       current = current->next;
    }
}