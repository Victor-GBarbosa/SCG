#include "deckManager.h"
#include <stdio.h>

Card *createDeck () {
    Card *head = NULL;
    Card *current = NULL;
    Card *last = NULL;

    int index = 0;

    for (int j = 0; j < 4; j++) {
        for (int i = 1; i < 14; i++) {
            Card *newCard = (Card*)malloc(sizeof(Card));
            newCard->naipe = j;
            newCard->rank = i;
            newCard->stamp = 0;
            newCard->id = index;

            newCard->next = NULL;
            newCard->prev = NULL;
            
            if (head == NULL) {
                head = newCard;
                current = head; //implementar um sistema que va e volte nas cartas
            } else {            //usando as posições next e prev, vai ser util para testes
                current->next = newCard;
                current->next->prev = current;
                current = newCard;                
            }
            index++;
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
        printf("Paus");
        break;

       case ESPADAS:
        printf("Espadas");
        break;

       case OUROS:
        printf("Ouros");
        break;
        
       case COPAS:
        printf("Copas");
        break;

       default:
         printf("Naipe invalido\n");
        break;
       }

       printf(" id: %i", card->id);
}

void showDeck (Card *baralho) {
    Card *current = baralho;

    while (current != NULL) {
       printf("\n");
       showCard(current);
       printf("\n\n");

        if (current->prev != NULL)
       {
        printf ("Anterior: ");
        showCard(current->prev);
        printf("\n");
       }

       if (current->next != NULL)
       {
        printf ("Proxima: ");
        showCard(current->next);
        printf("\n\n");
       }
       

       printf("------------------\n");

       current = current->next;
    }
}

Card *pickById(Card *baralho, int id) {

    Card *card = baralho;

    while (card->id != id) {
        card = card->next;
    }

    card->prev->next = card->next;
    return card;
}


Card *pickLast(Card **baralho) {
    if (baralho == NULL || *baralho == NULL) {
        printf("Erro: Baralho não encontrado\n");
        return NULL;
    }

    Card *current = *baralho;

    
    if (current->next == NULL) {
        *baralho = NULL;  
        return current;
    }

    while (current->next != NULL) {
        current = current->next;
    }
  
    current->prev->next = NULL;
    current->prev = NULL;

    return current;
}

void insertLest(Card **baralho, Card *nCard) {

    Card *card = *baralho;
    
    while (card->next != NULL) {
        card = card->next;
    }

    card->next = nCard;
    nCard->prev = card;
    
}
