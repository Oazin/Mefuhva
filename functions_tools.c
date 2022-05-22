#include <stdio.h>
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

void menu(int *choice){
    do {
        printf("Menu:\n"
               "1. Single Player Mode\n"
               "2. Duo Player Mode\n"
               "3. Resume Game\n"
               "4. Quit\n");
        scanf("%d", choice);
    }while (*choice<1 || *choice>4);
}

void display(int *tab1,int *tab2){
    for (int i=5; i>=0; i--){
        printf(""CYN "|  %d  |" RESET"",tab1[i]);
    }
    printf("\n");
    for (int i=6; i<12; i++){
        printf(""CYN "|  %d  |" RESET"",tab1[i]);
    }
    printf( "\n" WHT "------------------------------------------"RESET"\n" );
    for (int i=11; i>5; i--){
        printf(""MAG "|  %d  |" RESET "",tab2[i]);
    }
    printf("\n");
    for (int i=0; i<6; i++){
        printf("" MAG "|  %d  |" RESET "",tab2[i]);
    }
    printf("\n\n\n");
}


void fill_in_tab(int *tab,int N){
    for (int i=0; i<(N-2); i++) tab[i] = 2;
    tab[10] = 1;
    tab[11] = 0;
}

int winner(int *tab){
    int vide = 0,win = 0;
    for (int i=0; i<12; i++) {
        if (tab[i] == 0) vide += 1;
    }
    if (vide == 12)  win = 1;
    return win;
}


void harvest(int *tab, int c) {
    if (c == 11) {if (tab[6]!=0){ tab[6] = 0; tab[5] = 0;}}
    else if (c == 10) {if (tab[7]!=0) {tab[7] = 0; tab[4] = 0;}}
    else if (c == 9) {if (tab[8]!=0){tab[8] = 0; tab[3] = 0;}}
    else if (c == 8) {if (tab[9]!=0){tab[9] = 0; tab[2] = 0;}}
    else if (c == 7) {if (tab[10]!=0){tab[10] = 0; tab[1] = 0;}}
    else if (c == 6) {if (tab[11]!=0){tab[11] = 0; tab[0] = 0;}}
}
void save_game(int *tab1, int *tab2, int N){
    FILE *f = fopen("Save_game.txt","w+");
    if (f != NULL){
        for (int i=0; i<N; i++){
            fprintf(f,"%d ",tab1[i]);
        }
        for (int i=0; i<N; i++){
            fprintf(f,"%d ",tab2[i]);
        }
        fclose(f);
    } else printf("Unable to open Save_game.txt file \n");
}

void resume_game(int *tab1,int *tab2,int N){
    FILE *f = fopen("Save_game.txt","r");
    char c;
    if (f != NULL){
        for (int i=0; i<2*N; i++){
            c = fgetc(f);
            if(i < 12) tab1[i] = (int)c;
            else tab2[i-N] = (int)c;
        }
        fclose(f);
    } else printf("Unable to open Save_game.txt file \n");
}