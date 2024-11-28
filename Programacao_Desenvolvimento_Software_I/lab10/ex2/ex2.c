#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;

    // Ler a quantidade de linhas e colunas
    scanf("%d", &N);
    scanf("%d", &M);

    // Alocar dinamicamente memória para a matriz
    int **matriz = (int **)malloc(N * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro ao alocar memória\n");
        return 1;
    }

    // Preencher a matriz com valores fornecidos pelo usuário
    for (int i = 0; i < N; i++) {
        matriz[i] = (int *)malloc(M * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro ao alocar memória\n");
            return 1;
        }


        for (int j = 0; j < M; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    // Imprimir os valores da matriz
   
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    // Liberar a memória alocada
    for (int i = 0; i < N; i++) {
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}