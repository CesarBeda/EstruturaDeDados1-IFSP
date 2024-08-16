#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> senhasGeradas;
    queue<int> senhasAtendidas;
    int opcao;
    int senhaAtual = 1; // Inicia a contagem de senhas a partir de 1

    do {
        cout << "Senhas aguardando atendimento: " << senhasGeradas.size() << endl;
        cout << "Selecione uma opção:\n";
        cout << "0. Sair\n";
        cout << "1. Gerar senha\n";
        cout << "2. Realizar atendimento\n";
        cin >> opcao;

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
                    opcao = -1; // Força a continuação do programa
                }
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 0);

    cout << "Programa encerrado. Senhas atendidas: " << senhasAtendidas.size() << endl;

    return 0;
}