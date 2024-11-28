#ifndef EMPRESA_HPP
#define EMPRESA_HPP

#include "Onibus.hpp"

class Empresa {
private:
    int num_onibus;
    Onibus* onibus[20];

public:
    Empresa();
    Onibus* adicionar_onibus(const std::string& placa, int capacidade_maxima);
    Onibus* busca_onibus(const std::string& placa);
    void imprimir_estado() const;
};

#endif // EMPRESA_HPP