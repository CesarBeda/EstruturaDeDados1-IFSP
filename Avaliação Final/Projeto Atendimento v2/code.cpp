#include <iostream>
#include <queue>
#include <limits>
#include <locale>
#include <windows.h>
#include <string>
#include <list>
#include <map>

using namespace std;

struct Guiche {
    int id;
    queue<int> senhasAtendidas;
};

bool isInteger(const string& str) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c) && c != '-') {
            return false;
        }
    }
    return true;
}

bool isPositiveInteger(const string& str, int& num) {
    if (str.empty()) return false;
    for (char c : str) {
        if (!isdigit(c)) return false;
    }
    num = stoi(str);
    return num > 0;
}

int main() {
    // Configura o console para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    queue<int> senhasGeradas;
    map<int, Guiche> guiches; // Mapeia o id do guichê para o objeto Guiche
    int opcao;
    int senhaAtual = 1; // Inicia a contagem de senhas a partir de 1

    do {
        cout << "\nSenhas aguardando atendimento: " << senhasGeradas.size() << endl;
        cout << "Número de guichês abertos: " << guiches.size() << endl;
        cout << "Selecione uma opção:\n";
        cout << "0. Sair\n";
        cout << "1. Gerar senha\n";
        cout << "2. Abrir guichê\n";
        cout << "3. Realizar atendimento\n";
        cout << "4. Listar senhas atendidas\n";
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
            case 1: { // Gerar senha
                senhasGeradas.push(senhaAtual);
                cout << "Senha gerada: " << senhaAtual << endl;
                senhaAtual++;
                break;
            }
            case 2: { // Abrir guichê
                int idGuiche;
                string input;
                cout << "Digite o ID do guichê: ";
                cin >> input;

                while (!isPositiveInteger(input, idGuiche)) {
                    cout << "ID inválido. Digite um número inteiro positivo para o ID do guichê: ";
                    cin >> input;
                }

                if (guiches.find(idGuiche) != guiches.end()) {
                    cout << "Guichê já existe.\n";
                } else {
                    Guiche novoGuiche;
                    novoGuiche.id = idGuiche;
                    guiches[idGuiche] = novoGuiche;
                    cout << "Guichê " << idGuiche << " aberto.\n";
                }
                break;
            }
            case 3: { // Realizar atendimento
                int idGuiche;
                string input;
                cout << "Digite o ID do guichê: ";
                cin >> input;

                while (!isPositiveInteger(input, idGuiche)) {
                    cout << "ID inválido. Digite um número inteiro positivo para o ID do guichê: ";
                    cin >> input;
                }

                if (guiches.find(idGuiche) != guiches.end()) {
                    if (!senhasGeradas.empty()) {
                        int senhaAtendida = senhasGeradas.front();
                        senhasGeradas.pop();
                        guiches[idGuiche].senhasAtendidas.push(senhaAtendida);
                        cout << "Senha atendida pelo guichê " << idGuiche << ": " << senhaAtendida << endl;
                    } else {
                        cout << "Não há senhas aguardando atendimento.\n";
                    }
                } else {
                    cout << "Guichê não encontrado.\n";
                }
                break;
            }
            case 4: { // Listar senhas atendidas
                int idGuiche;
                string input;
                cout << "Digite o ID do guichê: ";
                cin >> input;

                while (!isPositiveInteger(input, idGuiche)) {
                    cout << "ID inválido. Digite um número inteiro positivo para o ID do guichê: ";
                    cin >> input;
                }

                if (guiches.find(idGuiche) != guiches.end()) {
                    cout << "Senhas atendidas pelo guichê " << idGuiche << ": ";
                    queue<int> tempQueue = guiches[idGuiche].senhasAtendidas;

                    if (tempQueue.empty()) {
                        cout << "Nenhuma senha atendida.\n";
                    } else {
                        while (!tempQueue.empty()) {
                            cout << tempQueue.front();
                            tempQueue.pop();
                            if (!tempQueue.empty()) {
                                cout << ", "; // Adiciona a vírgula se houver mais senhas na fila
                            }
                        }
                        cout << endl;
                    }
                } else {
                    cout << "Guichê não encontrado.\n";
                }
                break;
            }
            case 0: // Sair
                if (!senhasGeradas.empty()) {
                    cout << "Ainda há senhas aguardando atendimento. Continue o atendimento.\n";
                    opcao = -1; // Força a continuação do programa até que todas as senhas sejam atendidas
                } else {
                    cout << "Programa encerrado. Senhas atendidas: ";

                    int totalAtendidas = 0;
                    for (map<int, Guiche>::iterator it = guiches.begin(); it != guiches.end(); ++it) {
                        totalAtendidas += it->second.senhasAtendidas.size();
                    }

                    cout << totalAtendidas << endl;
                }
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 0 || !senhasGeradas.empty());

    return 0;
}
