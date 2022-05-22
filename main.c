#include <stdio.h>
#include "functions_tools.h"
#include "functions_games.h"


int main() {
    int choice, tab1[12],tab2[12], N=12, restart = 1, game = 0,replay = 0;
    while(restart) {
        if (!replay){
            menu(&choice);
            fill_in_tab(tab1, N);
            fill_in_tab(tab2, N);
        }

        switch (choice) {
            case 1 :
                printf("Single Player Mode :\n");
                Single_Player_Mode(tab1,tab2,N);
                game = 1;
                break;
            case 2 :
                printf("Duo Player Mode :\n");
                Duo_Player_Mode(tab1,tab2,N);
                game = 2;
                break;
            case 3 :
                printf("Resume Game : \n");
                resume_game(tab1,tab2,N);
                choice = game; replay = 1;
                break;
            case 4 :
                printf("Good bye");
                restart = 0;
                break;
            default:
                printf("An error has occurred");
                break;
        }
    }
    return 0;
}