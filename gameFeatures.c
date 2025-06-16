
#include "gameFeatures.h"
#include <stdio.h>

void screen(Card *currentHand, Card *selectedHand) {
    printf("--------------------------------------------------------\n");
    printf("|999| x |333|             52/52                    |3000|\n");
    printf("--------------------------------------------------------\n\n");

    printf("Sua jogada:\n\n");
    showDeck(selectedHand);
    printf("\n");

    printf("Sua mao\n\n");
    showDeck(currentHand);


    
}

void modPlay (Card **currentHand, Card **selectedHand) {

    int opt, id;

   printf("1-Adicionar carta\n2-Remover carta\n\nOpcao: ");
   scanf("%d", &opt);

   switch (opt) {
        case 1 :
            printf("Escolha uma carta para ser adicionada\n\n");
            showDeck(*currentHand);    
            printf("Selecione uma carta pelo id: ");
            scanf("%i", &id);

            
            insertLast(selectedHand, pickById(currentHand, id));
            idRegulator(currentHand);
            idRegulator(selectedHand);
            
            showDeck(*selectedHand);
            break;

        case 2:
            if(*selectedHand == NULL) {
                printf("Impossivel remomer essa carta: baralho vazio\n");
                system("pause");
            } else {
                printf("Escolha uma carta para ser REMOVIDA\n\n");
                showDeck(*selectedHand);
                printf("Selecione uma carta pelo id: ");
                scanf("%i", &id);
                insertLast(currentHand, pickById(selectedHand, id));
                idRegulator(currentHand);
                idRegulator(selectedHand);
                
            }
            
            
            break;
        
        default:
            break;
        }
}

void roundPlay (Card **selectedHand, Card **currentHand) {

    screen(*currentHand, *selectedHand);

    printf("Round play iniciado\n"); //Debug

    int opt;
    printf("\n\n1: Modificar jogada\n");
    printf("2: Confirmar jogada\n\n");
    scanf("%i", &opt);
    
    switch (opt) {
    case 1:
        modPlay(currentHand, selectedHand);
        break;

    case 2:
        
        break;
    
    default:
        printf("opção invalida");
        break;
    }
}

HandRank handRankChecker (Card *selectedHand) {
    if (selectedHand) {
        return;
    }

    int size = getSize(selectedHand);
    Card *card1 = selectedHand;
    
    

    for (int i = 0; i < size; i++) { 
        for (int j = 0; j < size; j++) {

            Card *card2 = selectedHand;
            if (card1 == card2) {
                card2 = card2->next;
                continue;
            }
            
            card2 = card2->next;
        }
        card1 = card1->next;
    }
}
