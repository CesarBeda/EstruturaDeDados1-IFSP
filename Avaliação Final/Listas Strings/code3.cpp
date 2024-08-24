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

std::string formatoAgendaTelefonica(const std::string& nome) {
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

    // Montar o nome formatado
    std::string nomeFormatado = ultimoSobrenome + ", ";

    // Adicionar os outros nomes, preservando os espaços
    for (const auto& parte : partes) {
        nomeFormatado += parte + " ";
    }

    // Remove o espaço final extra
    nomeFormatado.pop_back(); 

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
        std::cout << formatoAgendaTelefonica(linha) << std::endl;
    }

    return 0;
}
