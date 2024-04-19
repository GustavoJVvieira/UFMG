#include <stdio.h>

int main (){

    int x, y, i, j;

    scanf("%d", &x);
    scanf("%d", &y);


    int vetor[x][y];

    for(i = 0; i < x; i++){
       for(j = 0; j < y; j++){

        scanf("%d", &vetor[i][j]);

       }
    }

    for(i = 0; i < x; i++){
       for(j = 0; j < y; j++){
        vetor[i][j] = vetor[i][j] * (-1);
        printf("%d ", vetor[i][j]);

       }

       printf("\n");
    }


    return 0;
}