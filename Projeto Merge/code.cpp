#include <iostream>
#include <vector>
#include <list>

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

int main() {
    StackVector evenStackVector;
    StackList oddStackList;

    int previousNumber = -1; // Inicializa com -1 para garantir que o primeiro número seja maior
    int number;

    for (int i = 0; i < 30; ++i) {
        do {
            cout << "Digite um número inteiro maior que " << previousNumber << ": ";
            cin >> number;
        } while (number <= previousNumber); // Garante que o número digitado seja maior que o anterior

        previousNumber = number;

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
        cout << evenStackVector.pop() << " ";
    }

    // Desempilha e exibe os números ímpares em ordem decrescente
    cout << "\nNúmeros ímpares em ordem decrescente:\n";
    while (!oddStackList.isEmpty()) {
        cout << oddStackList.pop() << " ";
    }

    return 0;
}