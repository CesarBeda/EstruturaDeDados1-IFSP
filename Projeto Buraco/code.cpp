#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// Função para gerar o baralho
void gerarBaralho(std::vector<std::string>& baralho) {
    for (int n = 0; n < 2; ++n) {  // Dois baralhos
        for (int i = 0; i < 4; ++i) {  // 4 naipes
            for (int j = 0; j < 13; ++j) {  // 13 valores
                std::string carta = std::to_string(i + 1) + "-" + std::to_string(j + 1) + "-" + std::to_string(n + 1);
                // Formatar como "4131"
                carta = std::to_string(i + 1) + std::string(2 - std::to_string(j + 1).length(), '0') + std::to_string(j + 1) + std::to_string(n + 1);
                baralho.push_back(carta);
            }
        }
    }
}

// Função para distribuir as cartas
void distribuirCartas(const std::vector<std::string>& baralho, std::vector<std::vector<std::string>>& maos) {
    std::vector<std::string> baralhoEmbaralhado = baralho;
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(baralhoEmbaralhado.begin(), baralhoEmbaralhado.end(), g);

    int cartaIndex = 0;
    for (int j = 0; j < 4; ++j) {  // 4 jogadores
        for (int c = 0; c < 11; ++c) {  // 11 cartas para cada jogador
            maos[j][c] = baralhoEmbaralhado[cartaIndex++];
        }
    }
}

// Função para imprimir as mãos dos jogadores
void imprimirMaos(const std::vector<std::vector<std::string>>& maos) {
    for (int j = 0; j < 4; ++j) {  // 4 jogadores
        std::cout << "Mão do Jogador " << (j + 1) << ":\n";
        for (int c = 0; c < 11; ++c) {  // 11 cartas
            std::cout << maos[j][c];
            if (c < 10) std::cout << ", "; // Adiciona vírgula após cada carta, exceto a última
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::string> baralho;
    std::vector<std::vector<std::string>> maos(4, std::vector<std::string>(11));

    gerarBaralho(baralho);
    distribuirCartas(baralho, maos);
    imprimirMaos(maos);

    return 0;
}
