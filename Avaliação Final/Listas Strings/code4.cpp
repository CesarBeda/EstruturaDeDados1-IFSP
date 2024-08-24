#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <locale>
#include <windows.h>
#include <algorithm>

// Lista de preposições comuns
std::vector<std::string> preposicoes = {"da", "de", "do", "das", "dos", "e"};

// Função para verificar se uma palavra é uma preposição
bool isPreposicao(const std::string& palavra) {
    std::string palavraLower = palavra;
    std::transform(palavraLower.begin(), palavraLower.end(), palavraLower.begin(), ::tolower);
    return std::find(preposicoes.begin(), preposicoes.end(), palavraLower) != preposicoes.end();
}

std::string formatoCitacaoBibliografica(const std::string& nome) {
    std::stringstream ss(nome);
    std::vector<std::string> partes;
    std::string palavra;

    // Separar o nome em partes
    while (ss >> palavra) {
        partes.push_back(palavra);
    }

    // Manter preposições unidas ao último sobrenome
    std::string ultimoSobrenome = partes.back();
    partes.pop_back();

    // Verifica se o penúltimo nome é uma preposição e a junta ao último sobrenome
    if (!partes.empty() && isPreposicao(partes.back())) {
        ultimoSobrenome = partes.back() + " " + ultimoSobrenome;
        partes.pop_back();
    }

    // Colocar o último sobrenome (exceto preposições) em maiúsculas
    std::string ultimoSobrenomeUpper = ultimoSobrenome;
    std::transform(ultimoSobrenomeUpper.begin(), ultimoSobrenomeUpper.end(), ultimoSobrenomeUpper.begin(), ::toupper);

    // Montar o nome formatado
    std::string nomeFormatado = ultimoSobrenomeUpper + ", " + partes[0]; // Primeiro nome não abreviado

    // Abreviar os demais nomes, exceto o primeiro e as preposições
    for (size_t i = 1; i < partes.size(); ++i) {
        if (!isPreposicao(partes[i])) {
            nomeFormatado += " " + std::string(1, partes[i][0]) + ".";
        } else {
            nomeFormatado += " " + partes[i]; // Mantém preposições
        }
    }

    return nomeFormatado;
}

int main() {
    // Configura o console para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    std::ifstream arquivo("nomes.txt");
    std::string linha;

    if (!arquivo) {
        std::cerr << "Erro ao abrir o arquivo.\n";
        return 1;
    }

    // Processar cada linha do arquivo
    while (std::getline(arquivo, linha)) {
        std::cout << formatoCitacaoBibliografica(linha) << std::endl;
    }

    return 0;
}