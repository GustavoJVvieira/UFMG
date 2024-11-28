#include <stdio.h>
#include <stdlib.h>

// Função para ler os elementos do vetor
void lerElementos(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%d", &vetor[i]);
    }
}

int main() {
    int n;

    // Ler o tamanho do vetor
    scanf("%d", &n);

    // Alocar dinamicamente memória para o vetor de n elementos
    int *vetor = (int *)malloc(n * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Ler os elementos do vetor
    lerElementos(vetor, n);

    // Imprimir os elementos do vetor
    for (int i = 0; i < n; i++) {
        printf("%d\n", vetor[i]);
    }

    // Liberar a memória alocada
    free(vetor);

    return 0;
}