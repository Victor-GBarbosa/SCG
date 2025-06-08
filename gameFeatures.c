#ifndef GAMEFEATURES_H
#define GAMEFEATURES_H

#include "gameFeatures.h"
#include <stdio.h>

void screen(Card *hand[], int hSize) {
    printf("--------------------------------------------------------\n");
    printf("|999| x |333|             52/52                    |3000|\n");
    printf("--------------------------------------------------------\n\n");
    printf("Sua jogada:\n\n");
    printf("Sua mao\n\n");

    for( int i = 0; i < hSize; i++) {
        showCard(hand[i]);
        printf("\n");
    }

    printf("\n\n1: Modificar jogada\n");
    printf("2: Confirmar jogada\n\n");
}

void roundPlay () {
    int opt;
    scanf("%i", &opt);
    
    switch (opt)
    {
    case 1:
        printf("");
        break;

    case 2:
        
        break;
    
    default:
        printf("opção invalida");
        break;
    }
}
#endif