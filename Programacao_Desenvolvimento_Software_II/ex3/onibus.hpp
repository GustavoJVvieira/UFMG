#ifndef ONIBUS_HPP
#define ONIBUS_HPP

#include <string>
#include <iostream>

class Onibus {
private:
    std::string placa;
    int capacidade_maxima;
    int lotacao_atual;

public:
    Onibus(const std::string& placa, int capacidade_maxima);
    void subir_passageiros(int num_pessoas);
    void descer_passageiros(int num_pessoas);
    void transfere_passageiros(Onibus* outro_onibus, int num_pessoas);
    void imprimir_estado() const;
    std::string get_placa() const;
    int get_lotacao_atual() const;
    int get_capacidade_maxima() const;
};

#endif // ONIBUS_HPP