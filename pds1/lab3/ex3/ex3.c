#include <stdio.h>


int main (){

    int x[10], i, num, y[10];

    for(i = 0; i < 10; i++){

        scanf("%d", &num);
        x[i]= num;

    }

    for(i = 0; i < 10; i++){

        y[i] = x[ 9 - i];

        printf("%d\n", y[i]);
    
    }

    return 0;
}