#include <stdio.h>

int main (){

    int num;
    int contador = 0;
    scanf("%d", &num);

    for (int i = 1; i <= num; i++){

        contador += i;

    }

    printf("%d\n", contador);

    return 0;
}