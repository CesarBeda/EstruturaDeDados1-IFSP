#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <locale>
#include <windows.h>
#include <iomanip>  // Para fixed e setprecision
#include <cctype>   // Para verificar se é dígito
#include <algorithm> // Para std::replace

struct Funcionario {
    int prontuario;
    std::string nome;
    double salario;
};

std::vector<Funcionario> funcionarios;

// Função para validar se a string é composta apenas por dígitos
bool ehNumeroInteiro(const std::string& str) {
    for (char c : str) {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Função para verificar se a string está no formato válido de salário
bool formatoSalarioValido(const std::string& str) {
    if (str.empty()) return false;

    std::string strModificada = str;
    // Verifica se o formato é válido com exatamente 2 casas decimais
    size_t pontoPos = strModificada.find('.');
    if (pontoPos == std::string::npos) {
        return false; // Deve ter um ponto decimal
    }

    std::string inteiroPart = strModificada.substr(0, pontoPos);
    std::string decimalPart = strModificada.substr(pontoPos + 1);

    if (decimalPart.length() != 2) {
        return false; // Deve ter exatamente 2 casas decimais
    }

    // Verifica se a parte inteira e a parte decimal são numéricas
    return std::all_of(inteiroPart.begin(), inteiroPart.end(), ::isdigit) &&
           std::all_of(decimalPart.begin(), decimalPart.end(), ::isdigit);
}

// Função para converter string de salário para double
double stringParaDouble(const std::string& str) {
    std::string strModificada = str;
    // Substitui vírgula por ponto
    std::replace(strModificada.begin(), strModificada.end(), ',', '.');
    return std::stod(strModificada);
}

void incluir() {
    Funcionario f;
    std::string prontuario_str;
    std::cout << "Digite o prontuario: ";
    while (true) {
        std::cin >> prontuario_str;
        if (ehNumeroInteiro(prontuario_str)) {
            f.prontuario = std::stoi(prontuario_str);
            break;
        } else {
            std::cout << "Por favor, insira um número inteiro válido para o prontuário: ";
        }
    }

    for (const auto& funcionario : funcionarios) {
        if (funcionario.prontuario == f.prontuario) {
            std::cout << "Funcionario com este prontuario ja existe.\n";
            return;
        }
    }

    std::cout << "Digite o nome: ";
    std::cin.ignore(); // Limpa o buffer antes de ler o nome
    std::getline(std::cin, f.nome);
    
    std::string salario_str;
    std::cout << "Digite o salario (no formato 0000.00): ";
    while (true) {
        std::cin >> salario_str;
        if (formatoSalarioValido(salario_str)) {
            f.salario = stringParaDouble(salario_str);
            if (f.salario >= 0) {
                break;
            } else {
                std::cout << "O salário não pode ser negativo. ";
                std::cout << "Por favor, insira um número válido para o salário (no formato 0000.00): ";
            }
        } else {
            std::cout << "Formato inválido. ";
            std::cout << "Por favor, insira um número válido para o salário (no formato 0000.00): ";
        }
    }
    
    funcionarios.push_back(f);
}

void excluir() {
    std::string prontuario_str;
    int prontuario;
    std::cout << "Digite o prontuario do funcionario a ser excluido: ";
    while (true) {
        std::cin >> prontuario_str;
        if (ehNumeroInteiro(prontuario_str)) {
            prontuario = std::stoi(prontuario_str);
            break;
        } else {
            std::cout << "Por favor, insira um número inteiro válido para o prontuário: ";
        }
    }

    for (auto it = funcionarios.begin(); it != funcionarios.end(); ++it) {
        if (it->prontuario == prontuario) {
            funcionarios.erase(it);
            std::cout << "Funcionario excluido.\n";
            return;
        }
    }
    std::cout << "Funcionario nao encontrado.\n";
}

void pesquisar() {
    std::string prontuario_str;
    int prontuario;
    std::cout << "Digite o prontuario do funcionario a ser pesquisado: ";
    while (true) {
        std::cin >> prontuario_str;
        if (ehNumeroInteiro(prontuario_str)) {
            prontuario = std::stoi(prontuario_str);
            break;
        } else {
            std::cout << "Por favor, insira um número inteiro válido para o prontuário: ";
        }
    }

    for (const auto& funcionario : funcionarios) {
        if (funcionario.prontuario == prontuario) {
            std::cout << "Nome: " << funcionario.nome 
                      << ", Salario: " << std::fixed << std::setprecision(2) << funcionario.salario << "\n";
            return;
        }
    }
    std::cout << "Funcionario nao encontrado.\n";
}

void listar() {
    double total_salario = 0;
    for (const auto& funcionario : funcionarios) {
        std::cout << "Prontuario: " << funcionario.prontuario 
                  << ", Nome: " << funcionario.nome 
                  << ", Salario: " << std::fixed << std::setprecision(2) << funcionario.salario << "\n";
        total_salario += funcionario.salario;
    }
    std::cout << "Total dos salarios: " << std::fixed << std::setprecision(2) << total_salario << "\n";
}

int main() {
    // Configura o console para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    std::string opcao_str;
    int opcao;
    do {
        std::cout << "\n0. Sair\n1. Incluir\n2. Excluir\n3. Pesquisar\n4. Listar\nDigite a opcao: ";
        while (true) {
            std::cin >> opcao_str;
            if (ehNumeroInteiro(opcao_str)) {
                opcao = std::stoi(opcao_str);
                if (opcao >= 0 && opcao <= 4) {
                    break;
                } else {
                    std::cout << "Por favor, insira um número válido para a opção: ";
                }
            } else {
                std::cout << "Por favor, insira um número válido para a opção: ";
            }
        }

        switch (opcao) {
            case 1: incluir(); break;
            case 2: excluir(); break;
            case 3: pesquisar(); break;
            case 4: listar(); break;
        }
    } while (opcao != 0);

    return 0;
}
