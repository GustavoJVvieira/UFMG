#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar uma data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Função para verificar se um ano é bissexto
int ehBissexto(int ano) {
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0))
        return 1;
    else
        return 0;
}

// Função para calcular o número de dias em um mês
int diasNoMes(int mes, int ano) {
    int dias[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && ehBissexto(ano))
        return 29;
    return dias[mes - 1];
}

// Função para calcular o número de dias desde 01/01/0001 até a data fornecida
int diasDesdeInicio(Data data) {
    int dias = 0;
    for (int ano = 1; ano < data.ano; ano++) {
        dias += ehBissexto(ano) ? 366 : 365;
    }
    for (int mes = 1; mes < data.mes; mes++) {
        dias += diasNoMes(mes, data.ano);
    }
    dias += data.dia;
    return dias;
}

// Função principal que calcula os dias entre a data fornecida e 17/09/2020
int diasTranscorridos(Data data) {
    Data dataReferencia = {17, 9, 2020};
    int dias1 = diasDesdeInicio(data);
    int dias2 = diasDesdeInicio(dataReferencia);
    return abs(dias2 - dias1) + 1; // Incluindo o dia final
}

int main() {
    int dia, mes, ano;
    while (scanf("%d %d %d", &dia, &mes, &ano) == 3) {
        // Condição de parada: todos os valores são zero
        if (dia == 0 || mes == 0 || ano == 0) {
            break;
        }
        Data data = {dia, mes, ano};
        int dias = diasTranscorridos(data);
        printf("%d\n", dias);
    }

    return 0;
}