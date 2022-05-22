#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "functions_tools.h"



int displacement(int *tab, char J[4]){
    int p, dplt, dpltsup;
    if (J == "Comp") { // Computeur displacement
        do {
            srand(time(NULL));
            p = rand() % 12;
        } while (tab[p] == 0 || (p < 0 || p > 11));
        printf("%s : The computer has chosen the %d th box \n", J, p + 1);
    } else { // Palyers displacement
        do {
            printf("%s : The seeds from which hole do you want to take?", J);
            scanf("%d", &p);
            p--;
        } while (tab[p] == 0 || (p < 0 || p > 11));
    }
    //Seed displacement
    while (tab[p] != 0){
        dplt = tab[p];
        tab[p] = 0;
        if (p+dplt<12){ // Displacement less than 12
            for (int i=p+1;i<(p+dplt+1);i++) tab[i]++;
            if (tab[p+dplt]!=1) p=p+dplt;
        }
        else { // Displacement greater than 12
            dpltsup = p+dplt-12;
            for (int i=p+1;i<12;i++) tab[i]++;
            for (int i=0;i<dpltsup+1;i++) tab[i]++;
            if (tab[dpltsup]!=1) p = dpltsup;
        }
    }
    return p+dplt;
}

void Duo_Player_Mode(int *tab1, int *tab2, int N){
    int c, loop=1,save;
    display(tab1,tab2);
    do{
        // Player 1 playing
        c = displacement(tab1,"J1");
        display(tab1,tab2);
        // Harvesting the seeds
        if (c>5 && c<12) {
            harvest(tab2,c);
            display(tab1,tab2);
        }
        // Checks if player 1 has won
        if (winner(tab2)) {
            printf("The Winner is the player 1\n");
            loop = 0;
        } else {
            // Player 2 playing
            c = displacement(tab2,"J2");
            display(tab1,tab2);
            // Harvesting the seeds
            if (c>5 && c<12) {
                harvest(tab1,c);
                display(tab1,tab2);
            }
            // Checks if player 2 has won
            if (winner(tab1)) {printf("The Winner is the player 2\n"); loop = 0;}
            do{
                printf("Do you want to stop the game and save it 1/0?");
                scanf("%d", &save);
            } while (save>1 || save<0);
            if (save == 1) { // sauvegarde
                save_game(tab1,tab2,N);
                loop = 0;
            }
        }
    }while (loop);
}

void Single_Player_Mode(int *tab1, int *tab2, int N){
    int c, loop = 1,save;
    display(tab1,tab2);
    do{
        // Player 1 playing
        c = displacement(tab1,"J");
        display(tab1,tab2);
        // Harvesting the seeds
        if (c>5 && c<12) {
            harvest(tab2,c);
            display(tab1,tab2);
        }
        // Checks if player 1 has won
        if (winner (tab1)) {
            printf("The Winner is the player 1");
            loop = 0;
        } else {
            // Computer playing
            c = displacement(tab2, "Comp");
            display(tab1, tab2);
            // Harvesting the seeds
            if (c > 5 && c < 12) {
                harvest(tab1, c);
                display(tab1, tab2);
            }
            // Checks if computer has won
            if (winner(tab2)) {printf("The Winner is the computer"); loop = 0;}
            do{
                printf("Do you want to stop the game and save it 1/0?");
                scanf("%d", &save);
            } while (save>1 || save<0);
            if (save == 1) {
                save_game(tab1,tab2,N);
                loop = 0;
            }
        }
    }while (loop);
}