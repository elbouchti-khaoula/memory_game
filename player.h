#include <stdio.h>

#ifndef PLAYER_H
    #define PLAYER_H
typedef struct __player{
    int id;
    char* name;
    char* username;
    char* password;
    int score;
}player;

struct classeement
{
    char nom[10][11];
    int score[10];
};


struct classeement cl;

typedef struct __player* Player;
Player createNewPlayer(void);
int savePlayer(Player p);



#endif
