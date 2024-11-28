#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>  // Adicione esta linha para usar std::istringstream
#include "aluno.hpp"

int main() {
    std::vector<Aluno> alunos;
    std::string nome;
    int matricula;
    std::string linhaNota;
    
    // Leitura dos dados dos alunos
    while (true) {
        std::getline(std::cin, nome);
        if (nome == "END") break;

        std::cin >> matricula;
        std::cin.ignore();  // Ignorar a linha de quebra após o número de matrícula
        std::getline(std::cin, linhaNota);
        
        Aluno aluno(nome, matricula);

        // Processar as notas
        int nota;
        std::istringstream notasStream(linhaNota);  // Agora está correto
        while (notasStream >> nota) {
            if (nota == -1) break;
            aluno.adicionarNota(nota);
        }

        alunos.push_back(aluno);
    }

    // Ordena os alunos em ordem alfabética pelo nome
    std::sort(alunos.begin(), alunos.end(), [](const Aluno& a, const Aluno& b) {
        return a.getNome() < b.getNome();
    });

    // Imprimir o relatório
    for (const Aluno& aluno : alunos) {
        // Imprime o número de matrícula, nome e as notas
        std::cout << aluno.getMatricula() << " " << aluno.getNome();
        for (int nota : aluno.getNotas()) {
            std::cout << " " << nota;
        }
        std::cout << std::endl;

        // Imprime a média, nota máxima e nota mínima
        std::cout << std::fixed << std::setprecision(2)
                  << aluno.calcularMedia() << " "
                  << aluno.obterNotaMaxima() << " "
                  << aluno.obterNotaMinima() << std::endl;
    }

    return 0;