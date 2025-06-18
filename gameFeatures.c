
#include "gameFeatures.h"
#include <stdio.h>

void screen(Card *currentHand, Card *selectedHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *actualBlind, int *chips) {
    printf("--------------------------------------------------------\n");
    printf("|%03i| x |%03i|             %02i/52                    |%03i|\n", 
    *chips, *multi, getSize(baralho), *actualBlind);
    printf("--------------------------------------------------------\n");
    printf("Pontuacao atual: %03i\nMaos: %02i | Descartes %02i\n\n", *score, *hands, *discart);
    printf("Sua jogada:\n\n");
    showDeck(selectedHand);
    printf("\n");

    printf("Sua mao\n\n");
    showDeck(currentHand);
    
}

void scoreHand(Card *selectedHand, int *chips) {

    Card *card = selectedHand;

    while (card != NULL) {
        chips += card->rank;
        card = card->next;
    }
    
}

void modPlay (Card **currentHand, Card **selectedHand) {
    int opt, id;

   printf("1-Adicionar carta\n2-Remover carta\n\nOpcao: ");
   scanf("%d", &opt);

   switch (opt) {
        case 1 :
        if (getSize(*selectedHand) < 5)
        {
            printf("Escolha uma carta para ser adicionada\n\n");
            showDeck(*currentHand);    
            printf("Selecione uma carta pelo id: ");
            scanf("%i", &id);

            
            insertLast(selectedHand, pickById(currentHand, id));
            idRegulator(currentHand);
            idRegulator(selectedHand);
            
            showDeck(*selectedHand);
            break;
        } else {
            system("cls");
            printf("Limite de 5 cartas atingido\n");
            system("pause");
            break;
        }
        


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

void confirmPlay(Card **selectedHand, Card **currentHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *actualBlind, int *chips) {
    HandRank playedHand;
    int size = 0;

    int opt;
    printf("1-Jogar mao selecionada\n2-Descartar mao selecionada\n\nSelecione uma opcao: ");    
    scanf("%d", &opt);

    switch (opt)
    {
    case 1:
        if (selectedHand != NULL && *selectedHand != NULL) {
        processHandModifiers(*selectedHand, chips, multi);
        scoreHand(*selectedHand, chips);
        clearDeck(selectedHand);

        size = getSize(*currentHand);

        while (size < 8) {
                insertLast(currentHand, pickLast(&baralho));
                size = getSize(*currentHand);
        }
        
        *hands--;
        } else {
            printf("nao eh possivel jogar uma mao vazia");
        }
        
        
        break;

    case 2:
        system("cls");
        if (*discart == 0 || *selectedHand == NULL) {
            printf("nao ha descartes restantes ou a mao esta vazia\n");
            system("pause");
            return;
        } else {
            system("cls");
            clearDeck(selectedHand);
            printf("Baralho descartado\n");
            size = getSize(*currentHand);
            while (size < 8) {
                insertLast(currentHand, pickLast(&baralho));
                size = getSize(*currentHand);
            }
            idRegulator(currentHand);
            (*discart)--;
            system("pause");
        }
        
        break;
    
    default:
        break;
    }

}

void roundPlay (Card **selectedHand, Card **currentHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *actualBlind, int *chips) {

    screen(*currentHand, *selectedHand, baralho, hands, discart, score, multi, actualBlind, chips);

    int opt;
    printf("\n\n1: Modificar jogada\n");
    printf("2: Confirmar jogada\n\n");
    scanf("%i", &opt);
    
    switch (opt) {
    case 1: //modificar jogada
        modPlay(currentHand, selectedHand);
        break;

    case 2: //confirmar jogada
        confirmPlay(selectedHand, currentHand, baralho, hands, discart, score, multi, actualBlind, chips);
        break;
    
    default:
        printf("opção invalida");
        break;
    }
}

