#include <iostream>
#include <thread>   // Inclua <thread> para utilizar sleep_for
#include <chrono>   // Inclua <chrono> para utilizar std::chrono::milliseconds
#include <locale>
#include <windows.h>
#include <string>

// Função para exibir a mensagem centralizada
void exibirMensagemCentralizada(const std::string& mensagem) {
    const int larguraTela = 80;
    int posicaoInicio = (larguraTela - mensagem.length()) / 2;

    for (int i = 0; i < 20; ++i) {
        std::cout << "\n";
    }
    
    // Pausa inicial antes de começar a exibir a mensagem
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Exibe a mensagem com uma animação de linhas
    for (int linha = 5; linha <= 20; ++linha) {
        for (int col = 0; col < posicaoInicio; ++col) {
            std::cout << " ";
        }
        std::cout << mensagem << std::endl;

        // Pausa entre cada linha
        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // Limpa a tela para "movimentar" a mensagem
        if (linha < 20) {
            std::system("cls");  // Use "cls" no Windows
        }
    }
}

int main() {
    // Configura o console para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    std::string mensagem;
    std::cout << "Digite uma mensagem: ";
    std::getline(std::cin, mensagem);

    exibirMensagemCentralizada(mensagem);

    return 0;
}
