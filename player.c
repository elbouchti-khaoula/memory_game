#include "player.h"
#include <stdlib.h>
#include <string.h>


static int id=0;

Player createNewPlayer(){
    Player p=(Player)malloc(sizeof(player));
    p->id=++id;
    p->name=(char*)malloc(50*sizeof(char));
    p->username=(char*)malloc(50*sizeof(char));
    p->password=(char*)malloc(50*sizeof(char));
    printf("Nom:\n");
    scanf("%s",p->name);
    printf("Username:\n");
    scanf("%s",p->username);
    p->score=0;
    printf("tapper le numero de l'operation desire apres que vous ");
    return p;
}


int savePlayer(Player p){
    FILE *fp=fopen("player.rangement","wb");
    if(fp==NULL){
        printf("Erreur lors d'acces au fichier des joueurs.\n");
        return -1;
    }
    int i=fwrite(p,sizeof(player),1,fp);
    if(i==0){
        printf("Erreur lors d'ecriture dans le fichier des joueurs.\n");
        return -1;
    }
    printf("Player Saved!\n");
    fclose(fp);
    return 0;
}



