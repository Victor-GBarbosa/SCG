#ifndef GAMEFEATURES_H
#define GAMEFEATURES_H

#include "gameFeatures.h"
#include <stdio.h>

void screen(Card *hand[], Card *selectedHand) {
    printf("--------------------------------------------------------\n");
    printf("|999| x |333|             52/52                    |3000|\n");
    printf("--------------------------------------------------------\n\n");
    printf("Sua jogada:\n\n");
    showDeck(selectedHand);
    printf("Sua mao\n\n");

    showDeck(hand[0]);

    printf("\n\n1: Modificar jogada\n");
    printf("2: Confirmar jogada\n\n");
}

Card *modPlay (int opt, Card *selectedHand, Card *currentHand) {
    //Selected hand == Sua jogada //Current hand == Sua mão
    printf("Modplay iniciado\n"); //Debug
    int id;

    
    Card *currentCard;
    switch (opt) {

    case 1:
        printf("Qual carta deseja selecionar?\n\n");
        showDeck(currentHand);
        printf("\n\nSelecione a carta digitando o id: ");
        scanf("%i", &id);

        printf("id da carta selecionada\n"); //Debug
        Card *selectedCard = pickById(&currentHand, id);
        printf("Carta pega\n"); //Debug
        insertLest(&selectedHand, selectedCard);
        printf("Carta inserida no final\n"); //Debug
        idRegulator(&selectedHand);
        idRegulator(&currentHand);
        break;

    case 2:
        //Remover carta na mão jogada
        break;
    
    default: printf("Opcao invalida");
        break;
    }

    return selectedHand;
}

void roundPlay (Card *selectedHand, Card *currentHand) {

    screen(&currentHand, selectedHand);

    printf("Round play iniciado\n"); //Debug

    int opt;
    int opt2;
    scanf("%i", &opt);
    
    switch (opt)
    {
    case 1:
        printf("1-Adicionar carta\n2-Remover carta\n\nOpcao: ");
        scanf("%d", &opt2);
        printf("Scan concludo\n"); //Debug
        selectedHand = modPlay(opt2, selectedHand, currentHand);
        break;

    case 2:
        
        break;
    
    default:
        printf("opção invalida");
        break;
    }
}
#endif