#include <stdio.h>
int main(){

int n, x0, x1;

scanf("%d", &n);
scanf("%d", &x0);
scanf("%d", &x1);

    int contador = 2;
    int primx = x0, secx = x1;

    printf("X0: %d\n", primx);
    printf("X1: %d\n", secx);
    for(int i = 0; i <= n - 2; i++){

        int num = (4 * secx ) - (2 * primx); 
  
        printf("X%d: %d\n",contador, num);

        primx = secx;

        secx = num;

        contador ++;
    }
}
