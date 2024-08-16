#include <iostream>
#include <vector>
#include <string>
#include <limits>

struct Funcionario {
    int prontuario;
    std::string nome;
    double salario;
};

std::vector<Funcionario> funcionarios;

void incluir() {
    Funcionario f;
    std::cout << "Digite o prontuario: ";
    while(!(std::cin >> f.prontuario)){
        std::cout << "Por favor, insira um número válido para o prontuario: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    for (const auto& funcionario : funcionarios) {
        if (funcionario.prontuario == f.prontuario) {
            std::cout << "Funcionario com este prontuario ja existe.\n";
            return;
        }
    }
    std::cout << "Digite o nome: ";
    std::cin >> f.nome;
    std::cout << "Digite o salario: ";
    while(!(std::cin >> f.salario) || f.salario < 0){
        std::cout << "Por favor, insira um número válido para o salário: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    funcionarios.push_back(f);
}

void excluir() {
    int prontuario;
    std::cout << "Digite o prontuario do funcionario a ser excluido: ";
    while(!(std::cin >> prontuario)){
        std::cout << "Por favor, insira um número válido para o prontuario: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
    int prontuario;
    std::cout << "Digite o prontuario do funcionario a ser pesquisado: ";
    while(!(std::cin >> prontuario)){
        std::cout << "Por favor, insira um número válido para o prontuario: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    for (const auto& funcionario : funcionarios) {
        if (funcionario.prontuario == prontuario) {
            std::cout << "Nome: " << funcionario.nome << ", Salario: " << funcionario.salario << "\n";
            return;
        }
    }
    std::cout << "Funcionario nao encontrado.\n";
}

void listar() {
    double total_salario = 0;
    for (const auto& funcionario : funcionarios) {
        std::cout << "Prontuario: " << funcionario.prontuario << ", Nome: " << funcionario.nome << ", Salario: " << funcionario.salario << "\n";
        total_salario += funcionario.salario;
    }
    std::cout << "Total dos salarios: " << total_salario << "\n";
}

int main() {
    int opcao;
    do {
        std::cout << "0. Sair\n1. Incluir\n2. Excluir\n3. Pesquisar\n4. Listar\nDigite a opcao: ";
        while(!(std::cin >> opcao)){
            std::cout << "Por favor, insira um número válido para a opção: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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