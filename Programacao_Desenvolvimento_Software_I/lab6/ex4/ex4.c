#include <stdio.h>

// Função para verificar se um ano é bissexto
int ehBissexto(int ano) {
    if ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0)
        return 1; // Ano bissexto
    else
        return 0; // Não é ano bissexto
}

int main() {
    int ano;
    
    while (scanf("%d", &ano) != EOF) {
        if (ehBissexto(ano))
            printf("1\n"); // Ano bissexto
        else
            printf("0\n"); // Não é ano bissexto
    }
    
    return 0;
}