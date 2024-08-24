#include <iostream>
#include <vector>
#include <locale>
#include <windows.h>
#include <string>
#include <limits>

class TicketOffice {
    std::vector<std::vector<bool>> seats;
    std::vector<int> prices = {50, 30, 15};
public:
    TicketOffice(int rows, int columns) : seats(rows, std::vector<bool>(columns, false)) {}

    bool reserveSeat() {
        int row, column;

        // Validar fileira
        while (true) {
            std::cout << "Digite a fileira (1-15): ";
            std::string input;
            std::cin >> input;
            if (!isInteger(input) || !isInRange(input, 1, seats.size())) {
                std::cout << "Entrada inválida. Digite um número inteiro válido para a fileira.\n";
            } else {
                row = std::stoi(input) - 1; // Ajustando para indexação baseada em zero
                break;
            }
        }

        // Validar coluna
        while (true) {
            std::cout << "Digite a coluna (1-40): ";
            std::string input;
            std::cin >> input;
            if (!isInteger(input) || !isInRange(input, 1, seats[0].size())) {
                std::cout << "Entrada inválida. Digite um número inteiro válido para a coluna.\n";
            } else {
                column = std::stoi(input) - 1; // Ajustando para indexação baseada em zero
                break;
            }
        }

        if (seats[row][column]) {
            std::cout << "Poltrona já foi reservada.\n";
            return false;
        }
        seats[row][column] = true;
        std::cout << "Poltrona reservada com sucesso.\n";
        return true;
    }

    void displayOccupancy() const {
        for (const auto& row : seats) {
            for (bool seat : row) {
                std::cout << (seat ? '#' : '.');
            }
            std::cout << '\n';
        }
    }

    void displayRevenue() const {
        int occupiedSeats = 0;
        int revenue = 0;
        for (int i = 0; i < seats.size(); ++i) {
            for (bool seat : seats[i]) {
                if (seat) {
                    ++occupiedSeats;
                    revenue += prices[i / 5];
                }
            }
        }
        std::cout << "Poltronas ocupadas: " << occupiedSeats << '\n';
        std::cout << "Faturamento: R$ " << revenue << ",00\n";
    }

    // Métodos estáticos para validação de entrada
    static bool isInteger(const std::string& str) {
        if (str.empty()) return false;
        for (char c : str) {
            if (!std::isdigit(c)) return false;
        }
        return true;
    }

    static bool isInRange(const std::string& str, int min, int max) {
        int value = std::stoi(str);
        return value >= min && value <= max;
    }
};

int main() {

    // Configura o console para usar UTF-8
    SetConsoleOutputCP(CP_UTF8);
    std::setlocale(LC_ALL, "pt_BR.UTF-8");

    TicketOffice ticketOffice(15, 40);
    int option;
    while (true) {
        // Validar opção do menu
        while (true) {
            std::cout << "\n- Fileiras 1 a 5: R$ 50,00;\n- Fileiras 6 a 10: R$ 30,00;\n- Fileiras 11 a 15: R$ 15,00;\n";
            std::cout << "\n0. Sair\n1. Reservar poltrona\n2. Mostrar ocupação\n3. Mostrar faturamento\n";
            std::cout << "Opção: ";
            std::string input;
            std::cin >> input;
            if (!TicketOffice::isInteger(input) || !TicketOffice::isInRange(input, 0, 3)) {
                std::cout << "Opção inválida. Digite um número inteiro válido.\n";
            } else {
                option = std::stoi(input);
                break;
            }
        }

        switch (option) {
        case 0:
            return 0;
        case 1:
            if (ticketOffice.reserveSeat())
                std::cout << "Reserva efetuada com sucesso!\n";
            break;
        case 2:
            std::cout << "Poltronas . = vagas e # = ocupadas.\n";
            ticketOffice.displayOccupancy();
            break;
        case 3:
            ticketOffice.displayRevenue();
            break;
        default:
            std::cout << "Opção inválida.\n";
        }
    }
}

