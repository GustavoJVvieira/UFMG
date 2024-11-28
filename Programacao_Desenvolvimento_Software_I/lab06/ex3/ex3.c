#include <stdio.h>

// Função para verificar se um número é primo
int Primo(int num) {
    if (num < 2)
        return 0; // Números menores que 2 não são primos
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return 0; // Encontrou um divisor, então não é primo
    }
    
    return 1; // Não encontrou divisores, então é primo
}

// Função para calcular a soma dos N primeiros números primos
long long int Soma_Primos(int N) {
    int contador = 0; // Contador de números primos encontrados
    long long int soma = 0; // Soma dos números primos
    int numero = 2; // Começa a verificar a partir do número 2
    
    while (contador < N) {
        if (Primo(numero)) {
            soma += numero;
            contador++;
        }
        numero++;
    }
    
    return soma;
}

int main() {
    int N;
    
    while (scanf("%d", &N) == 1) {
        long long int resultado = Soma_Primos(N);
        printf("%lld\n", resultado);
    }
    
    return 0;
}