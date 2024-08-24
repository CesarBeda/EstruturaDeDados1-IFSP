#include <iostream>
#include <vector>
#include <list>
#include <limits>
#include <locale>
#include <windows.h>
#include <string>

using namespace std;

// Estrutura de pilha usando vetor
class StackVector {
private:
    vector<int> stack;

public:
    void push(int value) {
        stack.push_back(value);
    }

    int pop() {
        if (!stack.empty()) {
            int value = stack.back();
            stack.pop_back();
            return value;
        }
        return -1; // Indica pilha vazia
    }

    bool isEmpty() {
        return stack.empty();
    }
};

// Estrutura de pilha usando lista encadeada
class StackList {
private:
    list<int> stack;

public:
    void push(int value) {
        stack.push_back(value);
    }

    int pop() {
        if (!stack.empty()) {
            int value = stack.back();
            stack.pop_back();
            return value;
        }
        return -1; // Indica pilha vazia
    }

    bool isEmpty() {
        return stack.empty();
    }
};

bool isInteger(const string &str) {
    // Verifica se há algum ponto ou qualquer caractere não numérico
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

    StackVector evenStackVector;
    StackList oddStackList;

    cout << "Digite 30 números, onde sucessor obrigatoriamente é maior.\n";

    int previousNumber = -1; // Inicializa com -1 para garantir que o primeiro número seja maior
    int count = 0; // Contador para garantir que exatamente 30 números válidos sejam inseridos

    while (count < 30) {
        string input;
        int number;

        cout << "Digite o " << count + 1 << "º número inteiro da lista, deve ser maior que " << previousNumber << ": ";
        cin >> input;

        // Verifica se a entrada é um número inteiro
        if (!isInteger(input)) {
            cout << "Digite apenas números inteiros.\n";
            continue;
        }

        // Converte a string para inteiro
        number = stoi(input);

        if (number <= previousNumber) {
            cout << "O número deve ser maior que " << previousNumber << ".\n";
            continue;
        }

        // Número válido
        previousNumber = number;
        ++count;

        // Empilha o número em uma das estruturas conforme paridade
        if (number % 2 == 0) {
            evenStackVector.push(number);
        } else {
            oddStackList.push(number);
        }
    }

    // Desempilha e exibe os números pares em ordem decrescente
    cout << "\nNúmeros pares em ordem decrescente:\n";
    while (!evenStackVector.isEmpty()) {
        cout << evenStackVector.pop() << ", ";
    }

    // Desempilha e exibe os números ímpares em ordem decrescente
    cout << "\nNúmeros ímpares em ordem decrescente:\n";
    while (!oddStackList.isEmpty()) {
        cout << oddStackList.pop() << ", ";
    }

    return 0;
}
