#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::string formatoAgendaTelefonica(const std::string& nome) {
    std::stringstream ss(nome);
    std::vector<std::string> partes;
    std::string palavra;

    while (ss >> palavra) {
        partes.push_back(palavra);
    }

    std::string ultimoSobrenome = partes.back();
    partes.pop_back();
    std::string nomeFormatado = ultimoSobrenome + ", ";

    for (const auto& parte : partes) {
        nomeFormatado += parte + " ";
    }

    nomeFormatado.pop_back(); // Remove o espaço final
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
        std::cout << formatoAgendaTelefonica(linha) << std::endl;
    }

    return 0;
}
