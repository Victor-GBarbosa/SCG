#include <stdio.h>
#include <stdlib.h>

#include "pokerHands.h"


HandRank handRankChecker(Card *selectedHand) {

    if (selectedHand == NULL) {
        return NULL;
    }

    int size = getSize(selectedHand);

                              //                                                    {0, 2, 0, 2, 0...etc} 
    int rankCount[14] = {0};  //array que armazena as "cartas possiveis de uma mão" {2, 3, 4, 5, 6...etc}
    int naipeCount[4] = {0};   //armazena os nipes presentes não mão                                     Neste caso a carta tem 2 cartas 3 e 2 cartas 5 formando 2 pares
    int ranks[5];             //guarda individualmente o rank de cada carta, para verificar o se é uma sequencia
    
    
    Card *current = selectedHand;
    for (int i = 0; i < 5; i++) {
        rankCount[current->rank]++;
        naipeCount[current->naipe]++;
        ranks[i] = current->rank;
        current = current->next;
    }
    
    sortArray(ranks, 5);
    
    if (isFlush(naipeCount) && isStraight(ranks)) {
        return STRAIGHT_FLUSH;
    }
    
    if (isFullHouse(rankCount)) {
        return FULL_HOUSE;
    }
    
    if (isFlush(naipeCount)) {
        return FLUSH;
    }
    
    if (isStraight(ranks)) {
        return STRAIGHT;
    }
    
    if (isTwoPair(rankCount)) {
        return TWO_PAIR;
    }
    
    if (isPair(rankCount)) {
        return PAIR;
    }
    
    return HIGH_CARD;
}


int isFlush(int naipeCount[]) {
    for (int i = 0; i < 4; i++) {
        if (naipeCount[i] == 5) {
            return 1;  
        }
    }
    return 0;
}

int isStraight(int ranks[]) {
    // Verifica sequência normal
    for (int i = 1; i < 5; i++) {
        if (ranks[i] != ranks[i-1] + 1) {
            // Verifica sequência especial A,2,3,4,5
            if (!(ranks[0] == 1 && ranks[1] == 2 && ranks[2] == 3 && 
                  ranks[3] == 4 && ranks[4] == 5)) {
                return 0;
            }
        }
    }
    return 1;
}

int isFullHouse(int rankCount[]) {
    int hasThree = 0, hasPair = 0;
    for (int i = 1; i <= 13; i++) {
        if (rankCount[i] == 3) hasThree = 1;
        if (rankCount[i] == 2) hasPair = 1;
    }
    return hasThree && hasPair;
}


int isTwoPair(int rankCount[]) {
    int pairCount = 0;
    for (int i = 1; i <= 13; i++) {
        if (rankCount[i] == 2) {
            pairCount++;
        }
    }

    if (pairCount == 2) {
        return pairCount;
    } else {
        return 0;
    }
    
}

int isPair(int rankCount[]) {
    for (int i = 1; i <= 13; i++) {
        if (rankCount[i] == 2) {
            return 1;
        }
    }
    return 0;
}


void sortArray(int rankArray[], int size) {

    for (int i = 0; i < size - 1; i++) {

        for (int j = 0; j < size - i - 1; j++) {
            if (rankArray[j] > rankArray[j + 1]) {
                int temp = rankArray[j];
                rankArray[j] = rankArray[j + 1];
                rankArray[j + 1] = temp;
            }
        }
    }
}