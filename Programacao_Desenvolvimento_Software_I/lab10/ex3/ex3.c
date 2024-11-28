#include <stdio.h>
#include <stdlib.h>

// Função que realiza a soma de dois vetores e armazena o resultado em um terceiro vetor
void somaVetores(int *vetor1, int *vetor2, int *vetorSoma, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetorSoma[i] = vetor1[i] + vetor2[i];
    }
}

int main() {
    int tamanho;

    // Ler o tamanho dos vetores
    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &tamanho);

    // Alocar dinamicamente memória para os três vetores
    int *vetor1 = (int *)malloc(tamanho * sizeof(int));
    int *vetor2 = (int *)malloc(tamanho * sizeof(int));
    int *vetorSoma = (int *)malloc(tamanho * sizeof(int));

    if (vetor1 == NULL || vetor2 == NULL || vetorSoma == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Preencher os dois primeiros vetores com valores fornecidos pelo usuário
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor1[i]);
    }
    
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor2[i]);
    }

    // Realizar a soma dos dois vetores e armazenar o resultado no terceiro vetor
    somaVetores(vetor1, vetor2, vetorSoma, tamanho);

    // Imprimir o conteúdo do vetor que contém a soma
    for (int i = 0; i < tamanho; i++) {
        printf("%d\n", vetorSoma[i]);
    }

    // Liberar a memória alocada para os três vetores
    free(vetor1);
    free(vetor2);
    free(vetorSoma);

    return 0;
}