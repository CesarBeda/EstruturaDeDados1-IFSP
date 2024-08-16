#include <iostream>
#include <string>
#include <thread>
#include <chrono>

void exibirMensagemCentralizada(const std::string& mensagem) {
    const int larguraTela = 80;
    int posicaoInicio = (larguraTela - mensagem.length()) / 2;
    for (int i = 0; i < 20; ++i) {
        std::cout << "\n";
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    for (int linha = 5; linha <= 20; ++linha) {
        for (int col = 0; col < posicaoInicio; ++col) {
            std::cout << " ";
        }
        std::cout << mensagem << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        if (linha < 20) {
            std::system("clear"); // ou "cls" no Windows
        }
    }
}

int main() {
    std::string mensagem;
    std::cout << "Digite uma mensagem: ";
    std::getline(std::cin, mensagem);

    exibirMensagemCentralizada(mensagem);

    return 0;
}
