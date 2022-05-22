#ifndef MEFUHVA_FUNCTIONS_TOOLs_H
#define MEFUHVA_FUNCTIONS_TOOLs_H

void menu(int *choix);
void display(int *tab1, int *tab2);
void fill_in_tab(int *tab,int N);
int winner(int *tab);
int harvest(int *tab,int c);
void save_game(int *tab1,int *tab2,int N);
void resume_game(int *tab1,int *tab2,int N);

#endif //MEFUHVA_FUNCTIONS_TOOLs_H
