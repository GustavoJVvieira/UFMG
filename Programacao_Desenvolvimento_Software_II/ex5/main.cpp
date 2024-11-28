#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <sstream>

void toLowerCase(std::string& str) {
    std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
}

bool isAlnumOrSpace(char c) {
    return std::isalnum(c) || std::isspace(c);
}

int main() {
    std::string filename;
    std::cout << "Digite o nome do arquivo: ";
    std::cin >> filename;

    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Erro ao abrir o arquivo: " << filename << std::endl;
        return 1;
    }

    std::map<std::string, int> wordCount;
    std::string line;

    while (std::getline(file, line)) {
        // Remove caracteres não alfanuméricos, exceto espaços
        std::replace_if(line.begin(), line.end(), [](char c) { return !isAlnumOrSpace(c); }, ' ');

        // Transforma em letras minúsculas
        toLowerCase(line);

        // Divide em palavras
        std::istringstream stream(line);
        std::string word;
        while (stream >> word) {
            wordCount[word]++;
        }
    }

    file.close();

    // Imprime as palavras em ordem alfabética
    for (const auto& pair : wordCount) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}