#include <stdio.h>
#include <stdbool.h>

// Função para verificar se um número é primo
bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Função para encontrar o maior primo menor que m e o menor primo maior que m
void primos(int m, int *p1, int *p2) {
    // Encontrar o maior primo menor que m
    for (int i = m - 1; i > 1; i--) {
        if (is_prime(i)) {
            *p1 = i;
            break;
        }
    }

    // Encontrar o menor primo maior que m
    for (int i = m + 1;; i++) {
        if (is_prime(i)) {
            *p2 = i;
            break;
        }
    }
}

int main() {
    int m, p1 = -1, p2 = -1;
    
    
    scanf("%d", &m);

    // Chama a função primos para calcular p1 e p2
    primos(m, &p1, &p2);

    // Imprime os resultados
    printf("%d\n", p1);
    printf("%d\n", p2);

    return 0;
}