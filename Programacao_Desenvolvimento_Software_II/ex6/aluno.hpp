#ifndef ALUNO_HPP
#define ALUNO_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Aluno {
private:
    std::string nome;
    int matricula;
    std::vector<int> notas;

public:
    // Construtor
    Aluno(std::string nome, int matricula);

    // Métodos acessores
    std::string getNome() const;
    int getMatricula() const;
    const std::vector<int>& getNotas() const;

    // Métodos de operação
    void adicionarNota(int nota);
    double calcularMedia() const;
    int obterNotaMaxima() const;
    int obterNotaMinima() const;
};

#endif