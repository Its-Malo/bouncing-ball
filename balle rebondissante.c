#include <stdio.h>
#include <string.h>

#define ligne 30
#define colonne 40
#define balle '0'
#define speedX 1
#define speedY 1

void afficherBordure(int balleX, int balleY) {
    for (int y = 0; y < colonne; y++) {
        for (int x = 0; x < ligne; x++) {
            if ((x == 0 || x == ligne-1 || y == 0 || y == colonne-1) && !(x == balleX && y == balleY)){
                printf("*");
            }else if (x == balleX && y == balleY){
                printf("%c", balle);
            }else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {

    int balleX = ligne / 2;
    int balleY = colonne / 2;
    int balleSpeedX = speedX;
    int balleSpeedY = speedY;

    while(1){
        printf("\033[H\033[J");

        balleX += balleSpeedX;
        balleY += balleSpeedY;

        if (balleX <= 1 || balleX >= ligne-2){
            balleSpeedX = -balleSpeedX;
        }
        if (balleY <= 1 || balleY >= colonne-2){
            balleSpeedY = -balleSpeedY;
        }

        afficherBordure(balleX, balleY);
        usleep(50000);

    }
    return 0;
}

int main() {
    int matrice[2][3] =
    {{1, 2, 3},
    {4, 5, 6}};
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            sprintf("%d ", matrice[i][j]);
        }
        printf("\n");
    }

    return 0;
}
