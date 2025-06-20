

#include "deckManager.h"
#include <stdio.h>
#include <stdlib.h>

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
            // newCard->stamp = 0; //não implementado 
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

void debugCard(Card *card) {
    printf("\n----------\n");
    showCard(card);
    
    if (card->next == NULL) {
        printf("\nNext Card: NULL");
    } else {
        printf("Next Card: ");
        showCard(card->next);
    }
    printf("\n----------\n");
}

void showDeckAll (Card *baralho) {
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

void showDeck (Card *baralho) {
    Card *current = baralho;

    while (current != NULL) {
       showCard(current);
       printf("\n");

       current = current->next;
    }
}



Card *pickById(Card **baralho, int id) {

    Card *card = *baralho;
    int size = getSize(*baralho);

    printf("Size: %i\n", size); //debug

    if(id > size - 1  || id < 0) {
        printf("id nao encontrado no baralho");
        return NULL;
    }

    while (card->id != id) {
        card = card->next;
    }

    if (card->prev == NULL) {

        *baralho = card->next;
        if (card->next != NULL) {
            card->next->prev = NULL;
        }
    } else if (card->next == NULL) {
        card->prev->next = NULL;
    } else {
        card->next->prev = card->prev;
        card->prev->next = card->next;
    }

    card->next = NULL;
    card->prev = NULL;
    
    return card;
}

void removeById(Card **baralho, int id) {
    Card *carta = pickById(baralho, id);
    if (carta != NULL) {
        free(carta);  // Libera a memória automaticamente
    }
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

void insertLast(Card **baralho, Card *nCard) {

    if (nCard == NULL){
        return;
    }
    

    if (baralho == NULL || *baralho == NULL) {
        *baralho = nCard;
        nCard->next = NULL;
        nCard->prev = NULL;
        return;
    }
    
    Card *card = *baralho;
    while (card->next != NULL) {
        card = card->next;
    }

    card->next = nCard;
    nCard->prev = card;
    nCard->next = NULL;
}
    

int getSize (Card *baralho) {
    int index = 0;

    while (baralho != NULL) {
        baralho = baralho->next;
        index++;
    }

    return index;
    
}

void idRegulator(Card **baralho) {
    int index = 0;
    Card *current = *baralho;

    while (current != NULL) {
        current->id = index;
        current = current->next;
        index++;
    }
}

void shuffle (Card **baralho_ptr) {

    if (baralho_ptr == NULL || *baralho_ptr == NULL) {
        return;
    }

    Card *baralho = malloc(sizeof(Card));
    baralho = *baralho_ptr;

    int size = getSize(baralho);

    Card *temp[size];
    Card *current = baralho;

    for (int i = 0; i < size; i++) { // passando o baralho para um vetor
        temp[i] = current;
        current = current->next;
    }

    for (int i = size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card *swap = temp[i];
        temp[i] = temp[j];
        temp[j] = swap;
    }

        for (int i = 0; i < size; i++) {
        if (i == 0) {
            temp[i]->prev = NULL;
            *baralho_ptr = temp[i];
        } else {
            temp[i]->prev = temp[i-1];
            temp[i-1]->next = temp[i];
        }
        
        if (i == size - 1) {
            temp[i]->next = NULL;
        }
        }
}

void clearDeck(Card **baralho) {
    if (baralho == NULL || *baralho == NULL) {
        return;
    }
    
    Card *current = *baralho;
    Card *next;
    
    while (current != NULL) {
        next = current->next;  // Salva a próxima carta antes de liberar
        free(current);         // Libera a carta atual
        current = next;        // Move para a próxima
    }
    
    *baralho = NULL;  // Define o ponteiro como NULL (lista vazia)
}


