#include <iostream>

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

int main() {
    const int MAX_NUMEROS = 10;
    int numeros[MAX_NUMEROS];
    int n;

    std::cout << "Quantos números você deseja ordenar (máximo 10)? ";
    std::cin >> n;

    while (n > MAX_NUMEROS || n <= 0) {
        std::cout << "Número inválido! Insira um número entre 1 e 10: ";
        std::cin >> n;
    }

    std::cout << "Digite " << n << " números entre 1 e 100: " << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> numeros[i];
        while (numeros[i] < 1 || numeros[i] > 100) {
            std::cout << "Número inválido! Insira um número entre 1 e 100: ";
            std::cin >> numeros[i];
        }
    }

    selectionSort(numeros, n);

    std::cout << "Números ordenados: ";
    for (int i = 0; i < n; ++i) {
        std::cout << numeros[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
