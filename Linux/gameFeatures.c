
#include "gameFeatures.h"
#include <stdio.h>
#include <time.h>
#include <string.h>

void screen(Card *currentHand, Card *selectedHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips) {
    system("cls");
    printf("--------------------------------------------------------\n");
    printf("|%03i| x |%03i|             %02i/52                    |%03i|\n", 
    *chips, *multi, getSize(baralho), *currentBlind);
    printf("--------------------------------------------------------\n");
    printf("Pontuacao atual: %03i\nMaos: %02i | Descartes %02i\n\n", *score, *hands, *discart);
    printf("Sua jogada:\n\n");
    showDeck(selectedHand);
    printf("\n");

    printf("Sua mao:\n\n");
    showDeck(currentHand);
    
}

void scoreHand(Card *currentHand, Card *selectedHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips) {

    Card *card = selectedHand;

    while (card != NULL) {
        screen(currentHand, selectedHand, baralho, hands, discart, score, multi, currentBlind, chips);
        *chips += card->rank;
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
        
        default: printf("opcao invalida");
            break;
        }
}

void confirmPlay(Card **selectedHand, Card **currentHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips) {
    HandRank playedHand;
    int size = 0;

    int opt;
    printf("1-Jogar mao selecionada\n2-Descartar mao selecionada\n\nSelecione uma opcao: ");    
    scanf("%d", &opt);

    switch (opt) {
        case 1:

            if (selectedHand != NULL && *selectedHand != NULL) {
            processHandModifiers(*selectedHand, chips, multi);
            scoreHand(*currentHand, *selectedHand, baralho, hands, discart, score, multi, currentBlind, chips);
            clearDeck(selectedHand);

            size = getSize(*currentHand);

            while (size < 8) {
                insertLast(currentHand, pickLast(&baralho));
                size = getSize(*currentHand);
            }
            idRegulator(currentHand);
            (*hands)--;
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

void roundPlay (Card **selectedHand, Card **currentHand, Card *baralho, int *hands, int *discart, int *score, int *multi, int *currentBlind, int *chips) {

    screen(*currentHand, *selectedHand, baralho, hands, discart, score, multi, currentBlind, chips);

    int opt;
    printf("\n\n1: Modificar jogada\n");
    printf("2: Confirmar jogada\n\n");
    scanf("%i", &opt);
    
    switch (opt) {
    case 1: //modificar jogada
        modPlay(currentHand, selectedHand);
        break;    
    case 2: //confirmar jogada
        confirmPlay(selectedHand, currentHand, baralho, hands, discart, score, multi, currentBlind, chips);
        break;
    
    default:
        printf("opção invalida");
        break;
    }
}

//salvar e carregar arquivos do jogo ------------------------------------------------------------------------

int countSaves() {
    FILE *fp;
    char line[256];
    int count = 0;
    
    fp = fopen("save.txt", "r");
    if (fp == NULL) {
        return 0;
    }
    
    while (fgets(line, sizeof(line), fp)) {
        if (strlen(line) > 1) { // Linha não vazia
            count++;
        }
    }
    fclose(fp);
    return count;
}

int validateSave(char *saveLine) {
    char dateString[20];
    int round, currentBlind;
    
    if (sscanf(saveLine, "%s %d %d", dateString, &round, &currentBlind) == 3) {
        if (round >= 0 && currentBlind > 0) {
            return 1;
        }
    }
    return 0;
}

void saveGame(int round, int currentBlind, char *currentSave) {
    FILE *fp;
    time_t rawtime;
    struct tm *timeinfo;
    char newSave[256];

    time(&rawtime);
    timeinfo = localtime(&rawtime);
    

    sprintf(newSave, "%02d/%02d/%04d-%02d:%02d:%02d %d %d",
            timeinfo->tm_mday,
            timeinfo->tm_mon + 1,
            timeinfo->tm_year + 1900,
            timeinfo->tm_hour,
            timeinfo->tm_min,
            timeinfo->tm_sec,
            round,
            currentBlind);
    

    if (strlen(currentSave) > 0) {
        FILE *tempFp;
        char line[256];
        char saves[MAX_SAVES][256];
        int saveCount = 0;
        int found = 0;
        

        fp = fopen("save.txt", "r");
        if (fp != NULL) {
            while (fgets(line, sizeof(line), fp) && saveCount < MAX_SAVES) {
                line[strcspn(line, "\n")] = 0; // Remove \n
                if (strlen(line) > 0) {
                    if (strcmp(line, currentSave) == 0) {
                        strcpy(saves[saveCount], newSave);
                        found = 1;
                    } else {
                        strcpy(saves[saveCount], line);
                    }
                    saveCount++;
                }
            }
            fclose(fp);
        }
        
        if (!found) {
            
            if (saveCount < MAX_SAVES) {
                strcpy(saves[saveCount], newSave);
                saveCount++;
            } else {
                printf("Limite de saves atingido (%d). Não foi possível salvar.\n", MAX_SAVES);
                return;
            }
        }

        fp = fopen("save.txt", "w");
        if (fp == NULL) {
            printf("Erro: Nao foi possivel atualizar o arquivo de salvamento!\n");
            return;
        }
        
        for (int i = 0; i < saveCount; i++) {
            fprintf(fp, "%s\n", saves[i]);
        }
        fclose(fp);
        
        strcpy(currentSave, newSave);
        
    } else {

        if (countSaves() >= MAX_SAVES) {
            printf("Limite de saves atingido (%d). Não foi possível salvar.\n", MAX_SAVES);
            return;
        }
        
        fp = fopen("save.txt", "a");
        if (fp == NULL) {
            printf("Erro: Nao foi possivel criar o arquivo de salvamento!\n");
            return;
        }
        
        fprintf(fp, "%s\n", newSave);
        fclose(fp);
        
        
        strcpy(currentSave, newSave);
    }
    
    printf("Jogo salvo com sucesso!\n");
}

int loadGame(int *round, int *currentBlind, char *currentSave) {
    FILE *fp;
    char line[256];
    char saves[MAX_SAVES][256];
    int saveCount = 0;
    int choice;
    
    fp = fopen("save.txt", "r");
    if (fp == NULL) {
        printf("Erro: Arquivo de salvamento nao encontrado!\n");
        return 0; 
    }
    
    printf("\n=== SAVES DISPONIVEIS ===\n\n");
    while (fgets(line, sizeof(line), fp) && saveCount < MAX_SAVES) {
        line[strcspn(line, "\n")] = 0;
        
        if (strlen(line) > 0 && validateSave(line)) { 
            strcpy(saves[saveCount], line);
            printf("%d. %s\n", saveCount + 1, line);
            saveCount++;
        }
    }
    fclose(fp);
    
    if (saveCount == 0) {
        printf("Nenhum save valido encontrado!\n");
        return 0;
    }
    
    printf("\nEscolha um save (1-%d) ou 0 para cancelar: ", saveCount);
    scanf("%d", &choice);
    
    if (choice < 1 || choice > saveCount) {
        printf("Escolha cancelada.\n");
        return 0;
    }
    
    char dateString[20];
    int loadedRound, loadedBlind;
    
    if (sscanf(saves[choice - 1], "%s %d %d", dateString, &loadedRound, &loadedBlind) == 3) {
        *round = loadedRound;
        *currentBlind = loadedBlind;
        
        strcpy(currentSave, saves[choice - 1]);
        
        printf("\nSave carregado com sucesso!\n");
        printf("Data: %s\n", dateString);
        printf("Round: %d\n", *round);
        printf("Current Blind: %d\n", *currentBlind);
        system("pause");
        
        return 1;
    } else {
        printf("Erro: Formato de save invalido!\n");
        return 0;
    }
}


