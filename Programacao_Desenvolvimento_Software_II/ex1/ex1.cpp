#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Função para verificar se uma letra está na palavra, mas na posição errada
bool letraPresenteErrada(const string& chave, char letra, int pos) {
    return chave.find(letra) != string::npos && chave[pos] != letra;
}

// Função para verificar se a letra já está no vetor de letras incorretas
bool letraJaInserida(char letra, const vector<char>& letrasErradas) {
    return find(letrasErradas.begin(), letrasErradas.end(), letra) != letrasErradas.end();
}

int main() {
    // Abrir o arquivo "palavras.txt"
    ifstream arquivo("palavras.txt");
    if (!arquivo) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    int n;
    arquivo >> n;
    vector<string> palavras(n);

    // Ler as palavras do arquivo
    for (int i = 0; i < n; ++i) {
        arquivo >> palavras[i];
    }

    // Fechar o arquivo após a leitura
    arquivo.close();

    // Escolher a palavra chave
    int escolha;
    cin >> escolha;
    if (escolha < 1 || escolha > n) {
        cerr << "Número inválido." << endl;
        return 1;
    }

    string chave = palavras[escolha - 1];
    string tentativa;
    vector<char> letrasErradas;  // Vetor para armazenar letras erradas de todas as tentativas

    for (int tentativas = 0; tentativas < 5; ++tentativas) {
        cin >> tentativa;

        if (tentativa.size() != 5) {
            cerr << "Palavra inválida, insira uma palavra de 5 letras." << endl;
            --tentativas;
            continue;
        }

        // Comparar a tentativa com a chave
        string resultado = "";
        for (int i = 0; i < 5; ++i) {
            if (tentativa[i] == chave[i]) {
                resultado += tentativa[i];  // Letra correta e na posição certa
            } else if (letraPresenteErrada(chave, tentativa[i], i)) {
                resultado += tolower(tentativa[i]);  // Letra correta, mas posição errada
            } else {
                resultado += '*';  // Letra não presente
                if (!letraJaInserida(tentativa[i], letrasErradas)) {
                    letrasErradas.push_back(tentativa[i]);  // Adicionar letra ao vetor de erradas
                }
            }
        }

        // Exibir o resultado da tentativa
        cout << resultado << " (";
        for (char letra : letrasErradas) {
            cout << letra;
        }
        cout << ")" << endl;

        // Verificar se o jogador ganhou
        if (tentativa == chave) {
            cout << "GANHOU!" << endl;
            return 0;
        }
    }

    // Se não acertou a palavra, exibir a mensagem de perda
    cout << "PERDEU! " << chave << endl;

    return 0;
}
