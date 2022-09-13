#include <windows.h>
#include <stdio.h>
#include "main.h"
#include "player.h"
#define charRand(x)  ((x == 33) || (x == 159) ||(x == 317) ||(x == 209) || (x == 50) || (x == 318) ||(x == 359) || (x == 348) || (x == 168) || (x == 63)|| (x == 64) ||(x == 169) || (x == 173) || (x == 175) || (x == 190) ||(x == 197 ) || (x == 155 ) || (x == 156 ) || (x == 157) ||(x == 35) ||(x == 36) ||(x == 37) ||(x == 38) ||(x == 42) ||(x == 145) ||(x == 146) ||(x == 158) ||(x == 159) ||(x == 165) ||(x == 184) ||(x == 189) ||(x == 190) ||(x == 207) ||(x == 208) ||(x == 224) ||(x == 229) ||(x == 243) ||(x == 244)|| (x == 245)) ? 1 : 0


#define TFACILE 5000
#define TNORMAL 10000
#define TDIFICILE 15000
#define FACILE 4
#define NORMAL 6
#define DIFICILE 8
#define TRUE 1
#define FALSE 0
#define ASCII 300

void menu2()
  {
   createNewPlayer();
    FILE *fpp=fopen("player.rangement","rb");
    if(fpp==NULL) return -1;
    Player p=(Player)malloc(sizeof(player));
    size_t r=fread(p,sizeof(player),1,fpp);
    if(r==0){
        fclose(fpp);
        p=createNewPlayer();
        savePlayer(p);
        }
}
int main()
{
    char q;
    int i;

    for (i = 0; i < 10; i++)
        strcpy(cl.nom[i], "          ");
    for (i = 0; i < 10; i++)
        cl.score[i] = 0;
    do
    {
        q= menu();
        switch(q)
        {
            case '1': { generer(difficulte()) ; break; }
            case '2': { rang(); break; }
            case '3': { about(); break; }
            case '4': { createNewPlayer(); break; }
            case '5': { printf("\n\nO le jeu sera ferme!\n\n"); Sleep(3000); break; }
        }
        system("pause");
    } while (q != '5');
    return 0;
}

char menu()
{
    char l;

    system("cls");
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("\n    %c  JEU DE MEMOIRE   %c", 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c JOUER         %c", 186, 1, 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c CLASSEMENT    %c", 186, 2, 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c A PROPOS      %c", 186, 3, 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c S'INSCRIR     %c", 186,4, 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c SORTIR        %c", 186, 5, 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n\n", 200 , 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188);
    return l = getSpecChar(1,5);
}

char getSpecChar(int ini, int lim)
{
    char c;

    if ((ini >= 0 && ini <= 9) && (lim >= 0 && lim <= 9))
    {
        ini = ini + '0';
        lim = lim + '0';
        do
        {
            c = getch();
        } while (c < ini || c > lim);
    }
    else if ((ini >= 65 && ini <= 90) && (lim >= 65 && lim <= 90))
    {
        do
        {
            c = getch();
            if ((c == 13) && (lim > 'H'))
                break;
        } while ((c < ini || c > lim) && (c < ini + 32 || c > lim + 32));
    }
    putchar(c);
    return c;
}

int difficulte()
{
    char op;

    system("cls");
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187);
    printf("\n    %c       NIVEAU      %c", 186, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 203, 205, 205, 205, 205, 205, 205, 205, 205, 205, 203, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c FACILE  %c %2ds %c", 186, 1, 186, 186, TFACILE / 1000, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c NORMAL  %c %2ds %c", 186, 2, 186, 186, TNORMAL / 1000, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 205, 205, 205, 205, 205, 205, 206, 205, 205, 205, 205, 205, 185);
    printf("\n    %c %d %c DIFICILE%c %2ds %c", 186, 3, 186, 186, TDIFICILE / 1000, 186);
    printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n\n\n\n\n", 200 , 205, 205, 205, 202, 205, 205, 205, 205, 205, 205, 205, 205, 205, 202, 205, 205, 205, 205, 205, 188);
    op = getSpecChar(1, 3);
    switch(op)
    {
        case '1': { return FACILE; break; }
        case '2': { return NORMAL; break; }
        case '3': { return DIFICILE; break; }
    }
    return 0;
}

void generer(int const n)
{
    int chances = 1, fin = 0, flag, fois = -1, col = 0, col2 = 0, ln = 0, ln2 = 0, temp, cont, score = 0, cont2, i, j, mat[n][n], mat2[n][n], matcomp[((n * n) / 2)];
    float multi = 0.0;

    srand(time(0));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mat2[i][j] = 219;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            mat[i][j] = 0;
    for (i = 0; i < n + n; i++)
        matcomp[i] = 0;
    for (cont = 0; cont < ((n * n) / 2); cont++)
    {

        i = rand() % n;
        j = rand() % n;
        while (mat[i][j] != 0)
        {
            i = rand() % n;
            j = rand() % n;
        }
        flag = FALSE;
        while (flag == FALSE)
        {
            while (flag == FALSE)
            {
                temp = rand() % ASCII;
                flag = charRand(temp);
            }
            flag = FALSE;
            for (cont2 = 0; cont2 < ((n * n) / 2); cont2++)
                if (temp == matcomp[cont2])
                    break;
                else if ((temp != matcomp[cont2]) && (cont2 == (((n * n) / 2) - 1)))
                    flag = TRUE;
        }
        mat[i][j] = temp;
        matcomp[cont] = temp;
        while (mat[i][j] != 0)
        {
            i = rand() % n;
            j = rand() % n;
        }
        mat[i][j] = temp;
    }

    flag = FALSE;
    //======================================================================
    if (n == 4)
    {
        for (i = (TFACILE / 1000); i > 0; i--)
        {
            system("cls");
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c", 65, 66, 67, 68);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 1, 186, mat[0][0], 186, mat[0][1], 186, mat[0][2], 186, mat[0][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 2, 186, mat[1][0], 186, mat[1][1], 186, mat[1][2], 186, mat[1][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 3, 186, mat[2][0], 186, mat[2][1], 186, mat[2][2], 186, mat[2][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 4, 186, mat[3][0], 186, mat[3][1], 186, mat[3][2], 186, mat[3][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            printf("vous avez: %d secondes", i);
            Sleep(1000);
        }
        do
        {
            system("cls");
            fois++;
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c", 65, 66, 67, 68);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 1, 186, mat2[0][0], 186, mat2[0][1], 186, mat2[0][2], 186, mat2[0][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 2, 186, mat2[1][0], 186, mat2[1][1], 186, mat2[1][2], 186, mat2[1][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 3, 186, mat2[2][0], 186, mat2[2][1], 186, mat2[2][2], 186, mat2[2][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c", 4, 186, mat2[3][0], 186, mat2[3][1], 186, mat2[3][2], 186, mat2[3][3], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            if ((fin== ((n * n) / 2)))
                break;
            while (TRUE)
            {
                printf("\n\nentrer la colonne: ");
                switch(fois)
                {
                    case 0: { col = position(getSpecChar('A', 'D')); break; }
                    case 1: { col2 = position(getSpecChar('A', 'D')); break; }
                }
                printf("\nentrer la ligne: ");
                switch(fois)
                {
                    case 0: { ln = position(getSpecChar(1, 4)); break; }
                    case 1: { ln2 = position(getSpecChar(1, 4)); break; }
                }
                if (((mat2[ln][col] == 219) && (fois== 0)) || ((mat2[ln2][col2] == 219) && (fois == 1)))
                    break;
                else
                    printf("\nvous avez deja choisi cette position!");
            }
            if (fois == 0)
                mat2[ln][col] = mat[ln][col];
            else if (fois == 1)
            {
                mat2[ln2][col2] = mat[ln2][col2];
                chances++;
            }
            if ((mat[ln][col] == mat[ln2][col2]) && (fois== 1))
            {
                score = score + 50 + (multi * score);
                multi += 0.05;
                fin++;
                fois = -1;
            }
            else if (((fois == 1) && (mat[ln][col] != mat[ln2][col2])))
            {
                system("cls");
                printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
                printf("      %c   %c   %c   %c", 65, 66, 67, 68);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c", 1, 186, mat2[0][0], 186, mat2[0][1], 186, mat2[0][2], 186, mat2[0][3], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c", 2, 186, mat2[1][0], 186, mat2[1][1], 186, mat2[1][2], 186, mat2[1][3], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c", 3, 186, mat2[2][0], 186, mat2[2][1], 186, mat2[2][2], 186, mat2[2][3], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c", 4, 186, mat2[3][0], 186, mat2[3][1], 186, mat2[3][2], 186, mat2[3][3], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
                printf("\n\ndommage c'est faux!!");
                Sleep(2000);
                system("cls");
                multi = 0;
                fois = -1;
                mat2[ln][col] = 219;
                mat2[ln2][col2] = 219;
            }
        } while (TRUE);
    }

    else if (n == 6)
    {
        for (i = (TNORMAL / 1000); i > 0; i--)
        {
            system("cls");
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, mat[0][0], 186, mat[0][1], 186, mat[0][2], 186, mat[0][3], 186, mat[0][4], 186, mat[0][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, mat[1][0], 186, mat[1][1], 186, mat[1][2], 186, mat[1][3], 186, mat[1][4], 186, mat[1][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, mat[2][0], 186, mat[2][1], 186, mat[2][2], 186, mat[2][3], 186, mat[2][4], 186, mat[2][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, mat[3][0], 186, mat[3][1], 186, mat[3][2], 186, mat[3][3], 186, mat[3][4], 186, mat[3][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, mat[4][0], 186, mat[4][1], 186, mat[4][2], 186, mat[4][3], 186, mat[4][4], 186, mat[4][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, mat[5][0], 186, mat[5][1], 186, mat[5][2], 186, mat[5][3], 186, mat[5][4], 186, mat[5][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            printf("Vous avez: %d secondes", i);
            Sleep(1000);
        }
        do
        {
            system("cls");
            fois++;
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, mat2[0][0], 186, mat2[0][1], 186, mat2[0][2], 186, mat2[0][3], 186, mat2[0][4], 186, mat2[0][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, mat2[1][0], 186, mat2[1][1], 186, mat2[1][2], 186, mat2[1][3], 186, mat2[1][4], 186, mat2[1][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, mat2[2][0], 186, mat2[2][1], 186, mat2[2][2], 186, mat2[2][3], 186, mat2[2][4], 186, mat2[2][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, mat2[3][0], 186, mat2[3][1], 186, mat2[3][2], 186, mat2[3][3], 186, mat2[3][4], 186, mat2[3][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, mat2[4][0], 186, mat2[4][1], 186, mat2[4][2], 186, mat2[4][3], 186, mat2[4][4], 186, mat2[4][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, mat2[5][0], 186, mat2[5][1], 186, mat2[5][2], 186, mat2[5][3], 186, mat2[5][4], 186, mat2[5][5], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            if ((fin == ((n * n) / 2)))
                break;
            while (TRUE)
            {
                printf("\n\nentrer la colonne: ");
                switch(fois)
                {
                    case 0: { col = position(getSpecChar('A', 'F')); break; }
                    case 1: { col2 = position(getSpecChar('A', 'F')); break; }
                }
                printf("\nentrer la ligne: ");
                switch(fois)
                {
                    case 0: { ln = position(getSpecChar(1, 6)); break; }
                    case 1: { ln2 = position(getSpecChar(1, 6)); break; }
                }
                if (((mat2[ln][col] == 219) && (fois == 0)) || ((mat2[ln2][col2] == 219) && (fois == 1)))
                    break;
                else
                    printf("\nvous avez deja choisi cet emplacement!");
            }
            if (fois == 0)
                mat2[ln][col] = mat[ln][col];
            else if (fois == 1)
            {
                mat2[ln2][col2] = mat[ln2][col2];
                chances++;
            }
            if ((mat[ln][col] == mat[ln2][col2]) && (fois == 1))
            {
                score = score + 50 + (multi * score);
                multi += 0.05;
                fin++;
                fois= -1;
            }
            else if ((fois == 1) && (mat[ln][col] != mat[ln2][col2]))
            {
                system("cls");
                printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
                printf("      %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, mat2[0][0], 186, mat2[0][1], 186, mat2[0][2], 186, mat2[0][3], 186, mat2[0][4], 186, mat2[0][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, mat2[1][0], 186, mat2[1][1], 186, mat2[1][2], 186, mat2[1][3], 186, mat2[1][4], 186, mat2[1][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, mat2[2][0], 186, mat2[2][1], 186, mat2[2][2], 186, mat2[2][3], 186, mat2[2][4], 186, mat2[2][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, mat2[3][0], 186, mat2[3][1], 186, mat2[3][2], 186, mat2[3][3], 186, mat2[3][4], 186, mat2[3][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, mat2[4][0], 186, mat2[4][1], 186, mat2[4][2], 186, mat2[4][3], 186, mat2[4][4], 186, mat2[4][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, mat2[5][0], 186, mat2[5][1], 186, mat2[5][2], 186, mat2[5][3], 186, mat2[5][4], 186, mat2[5][5], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
                printf("\n\nDommage c'est faux!!");
                Sleep(2000);
                system("cls");
                multi = 0;
                fois = -1;
                mat2[ln][col] = 219;
                mat2[ln2][col2] = 219;
            }
        } while (TRUE);
    }
    //=================================================================
    else if (n == 8)
    {
        for (i = (TDIFICILE / 1000); i > 0; i--)
        {
            system("cls");
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70, 71, 72);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, mat[0][0], 186, mat[0][1], 186, mat[0][2], 186, mat[0][3], 186, mat[0][4], 186, mat[0][5], 186, mat[0][6], 186, mat[0][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, mat[1][0], 186, mat[1][1], 186, mat[1][2], 186, mat[1][3], 186, mat[1][4], 186, mat[1][5], 186, mat[1][6], 186, mat[1][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, mat[2][0], 186, mat[2][1], 186, mat[2][2], 186, mat[2][3], 186, mat[2][4], 186, mat[2][5], 186, mat[2][6], 186, mat[2][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, mat[3][0], 186, mat[3][1], 186, mat[3][2], 186, mat[3][3], 186, mat[3][4], 186, mat[3][5], 186, mat[3][6], 186, mat[3][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, mat[4][0], 186, mat[4][1], 186, mat[4][2], 186, mat[4][3], 186, mat[4][4], 186, mat[4][5], 186, mat[4][6], 186, mat[4][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, mat[5][0], 186, mat[5][1], 186, mat[5][2], 186, mat[5][3], 186, mat[5][4], 186, mat[5][5], 186, mat[5][6], 186, mat[5][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 7, 186, mat[6][0], 186, mat[6][1], 186, mat[6][2], 186, mat[6][3], 186, mat[6][4], 186, mat[6][5], 186, mat[6][6], 186, mat[6][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 8, 186, mat[7][0], 186, mat[7][1], 186, mat[7][2], 186, mat[7][3], 186, mat[7][4], 186, mat[7][5], 186, mat[7][6], 186, mat[7][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n\n", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            printf("vous avez: %d secondes", i);
            Sleep(1000);
        }
        do
        {
            system("cls");
            fois++;
            printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
            printf("      %c   %c   %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70, 71, 72);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, mat2[0][0], 186, mat2[0][1], 186, mat2[0][2], 186, mat2[0][3], 186, mat2[0][4], 186, mat2[0][5], 186, mat2[0][6], 186, mat2[0][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, mat2[1][0], 186, mat2[1][1], 186, mat2[1][2], 186, mat2[1][3], 186, mat2[1][4], 186, mat2[1][5], 186, mat2[1][6], 186, mat2[1][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, mat2[2][0], 186, mat2[2][1], 186, mat2[2][2], 186, mat2[2][3], 186, mat2[2][4], 186, mat2[2][5], 186, mat2[2][6], 186, mat2[2][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, mat2[3][0], 186, mat2[3][1], 186, mat2[3][2], 186, mat2[3][3], 186, mat2[3][4], 186, mat2[3][5], 186, mat2[3][6], 186, mat2[3][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, mat2[4][0], 186, mat2[4][1], 186, mat2[4][2], 186, mat2[4][3], 186, mat2[4][4], 186, mat2[4][5], 186, mat2[4][6], 186, mat2[4][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, mat2[5][0], 186, mat2[5][1], 186, mat2[5][2], 186, mat2[5][3], 186, mat2[5][4], 186, mat2[5][5], 186, mat2[5][6], 186, mat2[5][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 7, 186, mat2[6][0], 186, mat2[6][1], 186, mat2[6][2], 186, mat2[6][3], 186, mat2[6][4], 186, mat2[6][5], 186, mat2[6][6], 186, mat2[6][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
            printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 8, 186, mat2[7][0], 186, mat2[7][1], 186, mat2[7][2], 186, mat2[7][3], 186, mat2[7][4], 186, mat2[7][5], 186, mat2[7][6], 186, mat2[7][7], 186);
            printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
            if ((fin== ((n * n) / 2)))
                break;
            while (TRUE)
            {
                printf("\n\nentrer une colonne: ");
                switch(fois)
                {
                    case 0: { col = position(getSpecChar('A', 'H')); break; }
                    case 1: { col2 = position(getSpecChar('A', 'H')); break; }
                }
                printf("\nentrer une ligne: ");
                switch(fois)
                {
                    case 0: { ln = position(getSpecChar(1, 8)); break; }
                    case 1: { ln2 = position(getSpecChar(1, 8)); break; }
                }
                if (((mat2[ln][col] == 219) && (fois == 0)) || ((mat2[ln2][col2] == 219) && (fois == 1)))
                    break;
                else
                    printf("\nvous avez deja choisi cette position!");
            }
            if (fois == 0)
                mat2[ln][col] = mat[ln][col];
            else if (fois == 1)
            {
                mat2[ln2][col2] = mat[ln2][col2];
                chances++;
            }
            if ((mat[ln][col] == mat[ln2][col2]) && (fois == 1))
            {
                score = score + 50 + (multi * score);
                multi += 0.05;
                fin++;
                fois = -1;
            }
            else if ((fois == 1) && (mat[ln][col] != mat[ln2][col2]))
            {
                system("cls");
                printf("               #%d CHANCE        SCORE: %d     BONUS: +%3.0f%%\n\n\n", chances, score, multi * 100);
                printf("      %c   %c   %c   %c   %c   %c   %c   %c", 65, 66, 67, 68, 69, 70, 71, 72);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 201, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 203, 205, 205, 205, 187);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 1, 186, mat2[0][0], 186, mat2[0][1], 186, mat2[0][2], 186, mat2[0][3], 186, mat2[0][4], 186, mat2[0][5], 186, mat2[0][6], 186, mat2[0][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 2, 186, mat2[1][0], 186, mat2[1][1], 186, mat2[1][2], 186, mat2[1][3], 186, mat2[1][4], 186, mat2[1][5], 186, mat2[1][6], 186, mat2[1][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 3, 186, mat2[2][0], 186, mat2[2][1], 186, mat2[2][2], 186, mat2[2][3], 186, mat2[2][4], 186, mat2[2][5], 186, mat2[2][6], 186, mat2[2][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 4, 186, mat2[3][0], 186, mat2[3][1], 186, mat2[3][2], 186, mat2[3][3], 186, mat2[3][4], 186, mat2[3][5], 186, mat2[3][6], 186, mat2[3][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 5, 186, mat2[4][0], 186, mat[4][1], 186, mat2[4][2], 186, mat2[4][3], 186, mat2[4][4], 186, mat2[4][5], 186, mat2[4][6], 186, mat2[4][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 6, 186, mat2[5][0], 186, mat2[5][1], 186, mat2[5][2], 186, mat2[5][3], 186, mat2[5][4], 186, mat2[5][5], 186, mat2[5][6], 186, mat2[5][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 7, 186, mat2[6][0], 186, mat2[6][1], 186, mat2[6][2], 186, mat2[6][3], 186, mat2[6][4], 186, mat2[6][5], 186, mat2[6][6], 186, mat2[6][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 204, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 206, 205, 205, 205, 185);
                printf(" \n%d - %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c %c", 8, 186, mat2[7][0], 186, mat2[7][1], 186, mat2[7][2], 186, mat2[7][3], 186, mat2[7][4], 186, mat2[7][5], 186, mat2[7][6], 186, mat2[7][7], 186);
                printf("\n    %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c", 200 , 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 202, 205, 205, 205, 188);
                printf("\n\nDommage c'est faux!!");
                Sleep(2000);
                system("cls");
                multi = 0;
                fois = -1;
                mat2[ln][col] = 219;
                mat2[ln2][col2] = 219;
            }
        } while (TRUE);
        //=====================================================================================
    }
    printf("\n\nFélicitations!!!");
    printf("\n le calcul du score va commencer");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    printf(".");
    Sleep(1000);
    system("cls");
    score = lescore(n, chances, score);
    for (j = 0; j < 10; j++)
    {
        if (score > cl.score[j])
        {
            flag = TRUE;
            printf("BRAVO!!! NOUVEA SCORE\n\n");
            break;
        }
        else
            flag = FALSE;
    }
    printf("\n\n\nLe score final: %d\n\n", score);
    if (flag == TRUE)
    {
        organiserrang(j);
        strcpy(cl.nom[j], "          ");
        cl.score[j] = score;
        printf("\n\nentrer votre nom: ");
        for (i = 0; i < 10; i++)
        {
            temp = getSpecChar('A', 'Z');
            if (temp == 13)
                break;
            else
                cl.nom[j][i] = temp;
        }
        printf("\n\nmaintenant , votre nom est dans le classement!!!\n\n");
    }
}

int position(int g)
{
    switch(g)
    {
        case 'A': { g = 0; break; }
        case 'a': { g = 0; break; }
        case 'B': { g = 1; break; }
        case 'b': { g = 1; break; }
        case 'C': { g = 2; break; }
        case 'c': { g = 2; break; }
        case 'D': { g = 3; break; }
        case 'd': { g = 3; break; }
        case 'E': { g = 4; break; }
        case 'e': { g = 4; break; }
        case 'F': { g = 5; break; }
        case 'f': { g = 5; break; }
        case 'G': { g = 6; break; }
        case 'g': { g = 6; break; }
        case 'H': { g = 7; break; }
        case 'h': { g = 7; break; }
        case '1': { g = 0; break; }
        case '2': { g = 1; break; }
        case '3': { g = 2; break; }
        case '4': { g = 3; break; }
        case '5': { g = 4; break; }
        case '6': { g = 5; break; }
        case '7': { g = 6; break; }
        case '8': { g = 7; break; }
    }
    return g;
}

void rang()
{
    int i;

    system("cls");
    printf("------------ CLASSEMENT ----------\n\n");
    printf("       NOM              SCORE\n");
    for (i = 0; i < 10; i++)
        printf(" #%2d  %s          %d\n", i + 1, cl.nom[i], cl.score[i]);
    printf("\n\n");
}

int lescore(int lvl, int chances, int score)
{
    int i, temp;

    for (i = 0; i < 20; i++)
    {
        system("cls");
        printf("\n\n\nScore final: ");
        temp = rand() % 50000;
        printf("%d", temp);
        Sleep(100);
    }
    system("cls");
    if (chances == ((lvl * lvl) / 2))
        return (score * 1.4);
    else if ((chances >= ((lvl * lvl) / 2)) && (chances <= (lvl * lvl)))
        return (score * 1.2);
    else if ((chances >= (lvl * lvl)) && (chances <= ((lvl * lvl) + (2 * lvl))))
        return (score * 1.1);
    else if (((chances > (lvl * lvl) + (2 * lvl))) && (chances <= ((lvl * lvl) * 2 + lvl)))
        return score;
    else if ((chances > ((lvl * lvl) * 2 + lvl)))
        return score - (15 * chances);
    return 0;
}

void about()
{
    system("cls");
    printf("      COMPRENDRE LE SCORE\n\n");
    printf("   1 - Pour chaque coup, vous obtenez + 5 %% de BONUS\n");
    printf("   2 - Plus vous utilisez de CHANCES, plus votre SCORE diminue\n\n");
    printf("       la formule du score\n\n");
    printf("  NV = dimension matricielle du niveau choisi (4 || 6 || 8)\n");
    printf("  SCORE = score realise pendant le jeu\n");
    printf("  CHANCES = nombre de chances utilisees pou gagner la partie\n\n");
    printf("CHANCES = ((NV * NV) / 2), SCORE + 40%%\n");
    printf("CHANCES > ((NV * NV) / 2) E CHANCES <= (NV * NV), SCORE + 20%%\n");
    printf("CHANCES > (NV * NV) E CHANCES <= ((NV * NV) + (2 * NV)), SCORE + 10%%\n");
    printf("CHANCES > ((NV * NV) + (2 * NV)) E CHANCES <= ((NV * NV) * 2 + NV), +0%%\n");
    printf("CHANCES > ((NV * NV) * 2 + NV), Votre score recoit - (15 * CHANCES)\n\n");
}

void organiserrang(int pos)
{
    int i;

    for (i = 8; i >= pos; i--)
    {
        strcpy(cl.nom[i + 1], cl.nom[i]);
        cl.score[i + 1] = cl.score[i];
    }
}
