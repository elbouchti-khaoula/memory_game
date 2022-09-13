#ifndef MAIN_H
    #define PLAYER_H
#include <stdio.h>

void menu2(void);
char menu();
char getSpecChar(int ini, int lim);
int difficulte(void);
void generer(int n);
int position(int g);
void rang();
int lescore(int lvl, int chances, int score);
void about();
void organiserrang(int pos);
typedef struct __player{
    int id;
    char* name;
    char* username;
    char* password;
    int score;
}player;
typedef struct __player* Player;
struct classeement cl;
struct classeement
{
    char nom[10][11];
    int score[10];
};



#endif
