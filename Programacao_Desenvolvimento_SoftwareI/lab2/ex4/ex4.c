#include <stdio.h>

int main() {
    int x;
    scanf("%d", &x);

    int contador2 = 0, contador3 = 0, contador5 = 0, contadortodos = 0;
    int num = 1;

    do {
        if (num % 2 == 0) {
            contador2++;
        }
        if (num % 3 == 0) {
            contador3++;
        }
        if (num % 5 == 0) {
            contador5++;
        }
        if (num % 2 == 0 && num % 3 == 0 && num % 5 == 0) {
            contadortodos++;
        }
        num++;
    }while(num <=x);

    printf("Múltiplos de 2: %d\n", contador2);
    printf("Múltiplos de 3: %d\n", contador3);
    printf("Múltiplos de 5: %d\n", contador5);
    printf("Múltiplos de todos: %d\n", contadortodos);

    return 0;
}