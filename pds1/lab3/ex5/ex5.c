#include <stdio.h>

int main (){

    int l,c, maior = 0, i,j;

    scanf("%d", &l);
    scanf("%d", &c);

    int matriz[l][c];
            
    for (i = 0; i < l; i++){
        for (j = 0; j < c; j++)
        {
            scanf("%d",&matriz[i][j]);
        }
    }
    
    for (i = 0; i < l; i++){
        for (j = 0; j < c; j++){
            if(maior < matriz[i][j]) maior = matriz[i][j];
        }


    }

printf("%d\n", maior);

return 0;
}