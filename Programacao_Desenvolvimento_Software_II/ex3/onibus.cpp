#include "Onibus.hpp"

Onibus::Onibus(const std::string& placa, int capacidade_maxima)
    : placa(placa), capacidade_maxima(capacidade_maxima), lotacao_atual(0) {}

void Onibus::subir_passageiros(int num_pessoas) {
    if (lotacao_atual + num_pessoas <= capacidade_maxima) {
        lotacao_atual += num_pessoas;
    }
}

void Onibus::descer_passageiros(int num_pessoas) {
    if (lotacao_atual - num_pessoas >= 0) {
        lotacao_atual -= num_pessoas;
    }
}

void Onibus::transfere_passageiros(Onibus* outro_onibus, int num_pessoas) {
    if (outro_onibus != nullptr && lotacao_atual >= num_pessoas && 
        outro_onibus->get_lotacao_atual() + num_pessoas <= outro_onibus->get_capacidade_maxima()) {
        descer_passageiros(num_pessoas);
        outro_onibus->subir_passageiros(num_pessoas);
    }
}

void Onibus::imprimir_estado() const {
    std::cout << placa << " (" << lotacao_atual << "/" << capacidade_maxima << ")\n";
}

std::string Onibus::get_placa() const {
    return placa;
}

int Onibus::get_lotacao_atual() const {
    return lotacao_atual;
}

int Onibus::get_capacidade_maxima() const {
    return capacidade_maxima;
}