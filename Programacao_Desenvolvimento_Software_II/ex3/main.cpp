#include <iostream>
#include <string>
#include "Empresa.hpp"

int main() {
    Empresa empresa;
    std::string comando, placa1, placa2;
    int lotacao, num_pessoas;

    while (true) {
        std::cin >> comando;
        if (comando == "C") {
            std::cin >> placa1 >> lotacao;
            if (empresa.adicionar_onibus(placa1, lotacao)) {
                std::cout << "novo onibus cadastrado\n";
            } else {
                std::cout << "ERRO : onibus repetido\n";
            }
        } else if (comando == "S") {
            std::cin >> placa1 >> num_pessoas;
            Onibus* onibus = empresa.busca_onibus(placa1);
            if (onibus) {
                if (onibus->get_lotacao_atual() + num_pessoas > onibus->get_capacidade_maxima()) {
                    std::cout << "ERRO : onibus lotado\n";
                } else {
                    onibus->subir_passageiros(num_pessoas);
                    std::cout << "passageiros subiram com sucesso\n";
                }
            } else {
                std::cout << "ERRO : onibus inexistente\n";
            }
        } else if (comando == "D") {
            std::cin >> placa1 >> num_pessoas;
            Onibus* onibus = empresa.busca_onibus(placa1);
            if (onibus) {
                if (onibus->get_lotacao_atual() - num_pessoas < 0) {
                    std::cout << "ERRO : faltam passageiros\n";
                } else {
                    onibus->descer_passageiros(num_pessoas);
                    std::cout << "passageiros desceram com sucesso\n";
                }
            } else {
                std::cout << "ERRO : onibus inexistente\n";
            }
        } else if (comando == "T") {
            std::cin >> placa1 >> placa2 >> num_pessoas;
            Onibus* onibus1 = empresa.busca_onibus(placa1);
            Onibus* onibus2 = empresa.busca_onibus(placa2);
            if (onibus1 && onibus2) {
                if (onibus1->get_lotacao_atual() >= num_pessoas && 
                    onibus2->get_lotacao_atual() + num_pessoas <= onibus2->get_capacidade_maxima()) {
                    onibus1->transfere_passageiros(onibus2, num_pessoas);
                    std::cout << "transferencia de passageiros efetuada\n";
                } else {
                    std::cout << "ERRO : transferencia cancelada\n";
                }
            } else {
                std::cout << "ERRO : onibus inexistente\n";
            }
        } else if (comando == "I") {
            empresa.imprimir_estado();
        } else if (comando == "F") {
            break;
        }
    }

    return 0;
}