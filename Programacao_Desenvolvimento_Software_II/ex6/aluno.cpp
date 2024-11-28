#include "aluno.hpp"

// Construtor
Aluno::Aluno(std::string nome, int matricula)
    : nome(nome), matricula(matricula) {}

// Métodos acessores
std::string Aluno::getNome() const {
    return nome;
}

int Aluno::getMatricula() const {
    return matricula;
}

const std::vector<int>& Aluno::getNotas() const {
    return notas;
}

// Método para adicionar uma nota
void Aluno::adicionarNota(int nota) {
    notas.push_back(nota);
}

// Método para calcular a média das notas
double Aluno::calcularMedia() const {
    if (notas.empty()) {
        return 0.0;
    }
    int soma = 0;
    for (int nota : notas) {
        soma += nota;
    }
    return static_cast<double>(soma) / notas.size();
}

// Método para obter a nota máxima
int Aluno::obterNotaMaxima() const {
    return *std::max_element(notas.begin(), notas.end());
}

// Método para obter a nota mínima
int Aluno::obterNotaMinima() const {
    return *std::min_element(notas.begin(), notas.end());
}