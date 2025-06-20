#include <stdio.h>
#include <stdlib.h>
#include "gameFeatures.h"

#define INITIAL_BLIND 300

int main () {    
    
    Card *baralho = NULL, *selectedHand = NULL, *currentHand = NULL; //estruturas do baralho
    
    int currentBlind = INITIAL_BLIND, multi = 0, score = 0, hands = 4, discarts = 4, chips = 0; //variaveis de gameplay
    int roundWin = 0; //identificador de vitoria
    int round = 0;
    char currentSave[256] = ""; // String para armazenar o save atual

    int handSize = 8;
    int menuOpt;
    
    // Menu inicial
    system("cls");
    printf("=== SIMPLE CARD GAME ===\n\n");
    printf("1. Novo Jogo\n");
    printf("2. Carregar Jogo\n");
    printf("\nEscolha uma opcao: ");
    scanf("%d", &menuOpt);
    
    switch(menuOpt) {
        case 1:
            printf("Iniciando novo jogo...\n");
            break;        case 2:
            if (loadGame(&round, &currentBlind, currentSave)) { 
                printf("Jogo carregado! Continuando do round %d...\n", round);
                system("pause");
            } else {
                printf("Falha ao carregar. Iniciando novo jogo...\n");
                round = 0;
                currentBlind = INITIAL_BLIND;
                system("pause");
            }
            break;
        default:
            printf("Opcao invalida. Iniciando novo jogo...\n");
            system("pause");
            break;
    }
    
    do {

        baralho = createDeck();
        shuffle(&baralho);

        for (int i = 0; i < handSize; i++) {
            Card *newCard = pickLast(&baralho);
            insertLast(&currentHand, newCard);
        }  

    idRegulator(&currentHand);


        while(roundWin == 0) {
            if (hands > 0 && (getSize(baralho) > 0 || (getSize(currentHand) > 0 || getSize(selectedHand) > 0))) {
                system("cls");
                roundPlay(&selectedHand, &currentHand, baralho, &hands, &discarts, &score, &multi, &currentBlind, &chips);
                score += chips * multi;
                
                if (score >= currentBlind) { //caso tenha ganhado o round
                    roundWin = 1;
                    round++; // Increment round counter
                    system("cls");
                    printf("Parabens!!\n\nVoce ganhou o round %d com %i pontos\n%i Pontos cima da puntuacao necessaria\n", round, score, score - currentBlind);
                    system("pause");                    currentBlind = currentBlind + (currentBlind * 0.25);
                    //salvar aqui
                    saveGame(round, currentBlind, currentSave);
                    break;
                } else { //não tenha ganhado o round, mas ainda tenha mão
                    multi = 0;
                    chips = 0;
                }
            } else { //caso as "mãos" tenham acabado == perdeu o jogo
                roundWin = -1;
                system("cls");
                printf("Voce perdeu :(\n\nPontuacao necessaria: %i\nPontuacao atingida: %i\nFaltaram %i pontos.", currentBlind, score, currentBlind - score);
                system("pause");
                break;
            }
        } //final do looping de round
        score = 0;
        multi = 0;
        chips = 0;
        hands = 4;
        discarts = 4;
        roundWin = 0;
        
        clearDeck(&baralho);
        clearDeck(&currentHand);
        clearDeck(&selectedHand);
    } while(1);
} //main final
