#include <iostream>
#include <string>
#include <algorithm>
#include <locale>
#include <windows.h>
#include <string>

bool ehPalindromo(const std::string& mensagem) {
    std::string original, invertida;
    
    for (char c : mensagem) {
        if (std::isalpha(c)) {
            original += std::tolower(c);
        }
    }

    invertida = original;
    std::reverse(invertida.begin(), invertida.end());

    return original == invertida;
}

int main() {

    // Configura o console para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    std::string mensagem;
    std::cout << "Digite uma mensagem: ";
    std::getline(std::cin, mensagem);

    if (ehPalindromo(mensagem)) {
        std::cout << "A mensagem é um palíndromo.\n";
    } else {
        std::cout << "A mensagem não é um palíndromo.\n";
    }

    return 0;
}