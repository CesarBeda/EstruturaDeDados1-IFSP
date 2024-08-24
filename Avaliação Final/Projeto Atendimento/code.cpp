#include <iostream>
#include <queue>
#include <limits> // Incluído para usar std::numeric_limits
#include <locale>
#include <windows.h>
#include <string>

using namespace std;

bool isInteger(const string& str) {
    // Verifica se toda a string representa um número inteiro
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c) && c != '-') {
            return false;
        }
    }
    return true;
}

int main() {
    // Configura o console para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    queue<int> senhasGeradas;
    queue<int> senhasAtendidas;
    int opcao;
    int senhaAtual = 1; // Inicia a contagem de senhas a partir de 1

    do {
        cout << "\nSenhas aguardando atendimento: " << senhasGeradas.size() << endl;
        cout << "Selecione uma opção:\n";
        cout << "0. Sair\n";
        cout << "1. Gerar senha\n";
        cout << "2. Realizar atendimento\n";
        cout << "Opção: ";
        
        string input;
        cin >> input;

        if (!isInteger(input)) {
            cout << "Digite apenas números inteiros.\n";
            cin.clear(); // Limpa o estado do fluxo
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta a entrada inválida
            continue; // Reinicia o loop para solicitar uma nova entrada
        }

        opcao = stoi(input); // Converte a string para inteiro

        switch (opcao) {
            case 1: // Gerar senha
                senhasGeradas.push(senhaAtual);
                cout << "Senha gerada: " << senhaAtual << endl;
                senhaAtual++;
                break;
            case 2: // Realizar atendimento
                if (!senhasGeradas.empty()) {
                    int senhaAtendida = senhasGeradas.front();
                    senhasGeradas.pop();
                    senhasAtendidas.push(senhaAtendida);
                    cout << "Senha atendida: " << senhaAtendida << endl;
                } else {
                    cout << "Não há senhas aguardando atendimento." << endl;
                }
                break;
            case 0: // Sair
                if (!senhasGeradas.empty()) {
                    cout << "Ainda há senhas aguardando atendimento. Continue o atendimento." << endl;
                    opcao = -1; // Força a continuação do programa até que todas as senhas sejam atendidas
                } else {
                    cout << "Programa encerrado. Senhas atendidas: " << senhasAtendidas.size() << endl;
                }
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    return 0;
}
