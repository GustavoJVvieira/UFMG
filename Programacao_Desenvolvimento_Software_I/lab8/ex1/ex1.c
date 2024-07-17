#include <stdio.h>
#include <math.h>

// Função para calcular a média e encontrar a posição do valor mais próximo da média
void media(double vet[], int n, int *i) {
    double soma = 0.0;

    // Calcula a soma dos elementos do vetor
    for (int j = 0; j < n; j++) {
        soma += vet[j];
    }

    // Calcula a média
    double media = soma / n;

    // Inicializa a diferença mínima como um valor grande e a posição como 0
    double min_diff = fabs(vet[0] - media);
    *i = 0;

    // Encontra a posição do valor mais próximo da média
    for (int j = 1; j < n; j++) {
        double diff = fabs(vet[j] - media);
        if (diff < min_diff) {
            min_diff = diff;
            *i = j;
        }
    }
}

int main() {
    int n;
    printf("Digite a quantidade de valores do vetor: ");
    scanf("%d", &n);

    double vet[n];

    // Lê os elementos do vetor
    printf("Digite os elementos do vetor:\n");
    for (int j = 0; j < n; j++) {
        scanf("%lf", &vet[j]);
    }

    int posicao;
    // Chama a função media e armazena a posição do valor mais próximo da média
    media(vet, n, &posicao);

    // Imprime a posição do valor mais próximo da média
    printf("Posição do valor mais próximo da média: %d\n", posicao);

    return 0;
}