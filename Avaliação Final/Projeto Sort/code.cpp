#include <iostream>
#include <locale>
#include <windows.h>
#include <limits>  // Para limpar o buffer de entrada
#include <string>  // Para manipulação de strings
#include <sstream> // Para verificar o formato de entrada

// Função para realizar a ordenação por seleção (Selection Sort)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Troca o menor elemento encontrado com o primeiro elemento não ordenado
        int temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
}

// Função para garantir que a entrada seja um número inteiro
int lerInteiro(const std::string& mensagem) {
    std::string entrada;
    int numero;
    while (true) {
        std::cout << mensagem;
        std::getline(std::cin, entrada);

        // Usa uma stringstream para verificar se a entrada é um inteiro válido
        std::stringstream ss(entrada);
        if (ss >> numero && ss.eof()) {
            return numero;
        } else {
            std::cout << "Entrada inválida! Insira um número inteiro.\n";
        }
    }
}

int main() {
    // Configura o console para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "pt_BR.UTF-8");
    
    const int MAX_NUMEROS = 10;
    int numeros[MAX_NUMEROS];
    int n;

    // Solicita a quantidade de números a serem ordenados
    n = lerInteiro("Quantos números você deseja ordenar? (máximo 10): ");
    
    while (n > MAX_NUMEROS || n <= 0) {
        std::cout << "Número inválido! Insira um número entre 1 e 10: ";
        n = lerInteiro("");
    }

    // Solicita os números a serem ordenados
    for (int i = 0; i < n; ++i) {
        numeros[i] = lerInteiro("Digite um número entre 1 e 100: ");
        
        while (numeros[i] < 1 || numeros[i] > 100) {
            std::cout << "Número inválido! Insira um número entre 1 e 100: ";
            numeros[i] = lerInteiro("");
        }
    }

    // Ordena os números
    selectionSort(numeros, n);

    // Exibe os números ordenados
    std::cout << "Números ordenados: ";
    for (int i = 0; i < n; ++i) {
        std::cout << numeros[i] << ", ";
    }
    std::cout << std::endl;

    return 0;
}
