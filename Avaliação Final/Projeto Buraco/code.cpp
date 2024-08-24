#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <locale>
#include <windows.h>
#include <string>
#include <ctime> // Inclui a biblioteca para obter o tempo atual

// Função para gerar o baralho
void gerarBaralho(std::vector<std::string>& baralho) {
    baralho.clear(); // Limpa o baralho antes de gerar as cartas
    for (int n = 0; n < 2; ++n) {  // Dois baralhos
        for (int i = 0; i < 4; ++i) {  // 4 naipes
            for (int j = 0; j < 13; ++j) {  // 13 valores
                // Formatar como "4131"
                std::string carta = std::to_string(i + 1) + std::string(2 - std::to_string(j + 1).length(), '0') + std::to_string(j + 1) + std::to_string(n + 1);
                baralho.push_back(carta);
            }
        }
    }
}

// Função para distribuir as cartas
void distribuirCartas(std::vector<std::string>& baralho, std::vector<std::vector<std::string>>& maos) {
    // Embaralhar o baralho
    std::mt19937 g(static_cast<unsigned int>(std::time(0))); // Inicializa o gerador de números aleatórios com o tempo atual
    std::shuffle(baralho.begin(), baralho.end(), g); // Embaralha o baralho

    int cartaIndex = 0;
    for (int j = 0; j < 4; ++j) {  // 4 jogadores
        for (int c = 0; c < 11; ++c) {  // 11 cartas para cada jogador
            maos[j][c] = baralho[cartaIndex++];
        }
    }
}

// Função para imprimir as mãos dos jogadores
void imprimirMaos(const std::vector<std::vector<std::string>>& maos) {
    for (int j = 0; j < 4; ++j) {  // 4 jogadores
        std::cout << "\nMão do Jogador " << (j + 1) << ":\n";
        for (int c = 0; c < 11; ++c) {  // 11 cartas
            std::cout << maos[j][c];
            if (c < 10) std::cout << ", "; // Adiciona vírgula após cada carta, exceto a última
        }
        std::cout << "."; // ponto final na mão
        std::cout << "\n"; // pular linhas para próximo jogador
    }
}

int main() {
    // Configura o console para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    std::vector<std::string> baralho;
    std::vector<std::vector<std::string>> maos(4, std::vector<std::string>(11));

    gerarBaralho(baralho);
    distribuirCartas(baralho, maos);
    imprimirMaos(maos);

    return 0;
}