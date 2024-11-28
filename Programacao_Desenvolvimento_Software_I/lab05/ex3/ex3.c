#include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 8
#define MAX_CARACTERES 50

// Definição da estrutura para armazenar os produtos
typedef struct {
    char nome[MAX_CARACTERES];
    char marca[MAX_CARACTERES];
    float preco;
} Produto;

int main() {
    Produto produtos[MAX_PRODUTOS];
    int i;

    // Leitura dos dados dos produtos
    for (i = 0; i < MAX_PRODUTOS; i++) {
        scanf("%s %s %f", produtos[i].nome, produtos[i].marca, &produtos[i].preco);
        getchar(); // Limpar o buffer de entrada

        printf("\n");
    }

    // Inicialização das variáveis para cálculos
    float total_precos = 0.0;
    int contador_marcas[MAX_PRODUTOS] = {0}; // Array para contar produtos por marca
    float soma_precos_por_marca[MAX_PRODUTOS] = {0.0}; // Array para somar preços por marca
    int num_produtos_por_marca[MAX_PRODUTOS] = {0}; // Array para contar produtos por marca

    // Processamento dos dados para contagem e médias
    for (i = 0; i < MAX_PRODUTOS; i++) {
        total_precos += produtos[i].preco;

        // Encontrar a marca correspondente no array de contadores
        int encontrou = 0;
        for (int j = 0; j < MAX_PRODUTOS; j++) {
            if (strcmp(produtos[i].marca, produtos[j].marca) == 0) {
                contador_marcas[j]++;
                soma_precos_por_marca[j] += produtos[i].preco;
                num_produtos_por_marca[j]++;
                encontrou = 1;
                break;
            }
        }

        // Se não encontrou a marca, adicionar como uma nova
        if (!encontrou) {
            for (int j = 0; j < MAX_PRODUTOS; j++) {
                if (contador_marcas[j] == 0) {
                    strcpy(produtos[j].marca, produtos[i].marca);
                    contador_marcas[j]++;
                    soma_precos_por_marca[j] += produtos[i].preco;
                    num_produtos_por_marca[j]++;
                    break;
                }
            }
        }
    }

    // Imprimir o número de produtos de cada marca
    for (i = 0; i < MAX_PRODUTOS; i++) {
        if (contador_marcas[i] > 0) {
            printf("%s %d\n", produtos[i].marca, contador_marcas[i]);
        }
    }
    printf("\n");

    // Calcular e imprimir o preço médio dos produtos total
    float preco_medio_total = total_precos / MAX_PRODUTOS;
    printf("media total: %.2f\n", preco_medio_total);

    // Calcular e imprimir o preço médio por marca
    for (i = 0; i < MAX_PRODUTOS; i++) {
        if (contador_marcas[i] > 0) {
            float preco_medio_por_marca = soma_precos_por_marca[i] / num_produtos_por_marca[i];
            printf("media %s %.2f\n", produtos[i].marca, preco_medio_por_marca);
        }
    }

    return 0;
}