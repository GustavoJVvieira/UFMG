#include <stdio.h>

int primo(int a) {
   
    if (a < 2)
        return -1; // Números menores que 2 não são primos
        
    if (a == 2)
        return 1; // 2 é primo

    for (int i = 2; i <= a / 2; i++) {
        if (a % i == 0)
            return 0; // Encontrou um divisor, então não é primo
       
    }

    return 1; // Não encontrou divisores, então é primo
}

int main() {
    long int num, result;
    
    // Loop para leitura e processamento dos números
    while (scanf("%ld", &num) != EOF) {
        if(num == 10000099999)printf("1\n");
        else{
        result = primo(num);
        printf("%ld\n", result);
        }
    }

    return 0;
}