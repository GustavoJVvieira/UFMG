#include "Empresa.hpp"

Empresa::Empresa() : num_onibus(0) {
    for (int i = 0; i < 20; ++i) {
        onibus[i] = nullptr;
    }
}

Onibus* Empresa::adicionar_onibus(const std::string& placa, int capacidade_maxima) {
    for (int i = 0; i < num_onibus; ++i) {
        if (onibus[i]->get_placa() == placa) {
            return nullptr; // ônibus já cadastrado
        }
    }

    if (num_onibus < 20) {
        onibus[num_onibus] = new Onibus(placa, capacidade_maxima);
        return onibus[num_onibus++];
    }

    return nullptr; // limite de ônibus alcançado
}

Onibus* Empresa::busca_onibus(const std::string& placa) {
    for (int i = 0; i < num_onibus; ++i) {
        if (onibus[i]->get_placa() == placa) {
            return onibus[i];
        }
    }
    return nullptr; // ônibus não encontrado
}

void Empresa::imprimir_estado() const {
    for (int i = 0; i < num_onibus; ++i) {
        onibus[i]->imprimir_estado();
    }
}