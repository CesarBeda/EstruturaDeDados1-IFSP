#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::string formatoCitacaoBibliografica(const std::string& nome) {
    std::stringstream ss(nome);
    std::vector<std::string> partes;
    std::string palavra;

    while (ss >> palavra) {
        partes.push_back(palavra);
    }

    std::string ultimoSobrenome = partes.back();
    partes.pop_back();
    std::string nomeFormatado = ultimoSobrenome + ", ";

    for (size_t i = 0; i < partes.size(); ++i) {
        nomeFormatado += partes[i][0];
        if (i < partes.size() - 1) {
            nomeFormatado += ". ";
        }
    }

    return nomeFormatado;
}

int main() {
    std::ifstream arquivo("nomes.txt");
    std::string linha;

    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    while (std::getline(arquivo, linha)) {
        std::cout << formatoCitacaoBibliografica(linha) << std::endl;
    }

    return 0;
}
