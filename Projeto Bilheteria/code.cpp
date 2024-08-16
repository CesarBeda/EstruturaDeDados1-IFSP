#include <iostream>
#include <vector>

class TicketOffice {
    std::vector<std::vector<bool>> seats;
    std::vector<int> prices = {50, 30, 15};
public:
    TicketOffice(int rows, int columns) : seats(rows, std::vector<bool>(columns, false)) {}

    bool reserveSeat() {
        int row, column;
        std::cout << "Digite a fileira (1-15): ";
        std::cin >> row;
        row--; // Adjusting to zero-based indexing
        if (row < 0 || row >= seats.size()) {
            std::cout << "Fileira inválida.\n";
            return false;
        }
        std::cout << "Digite a coluna (1-40): ";
        std::cin >> column;
        column--; // Adjusting to zero-based indexing
        if (column < 0 || column >= seats[0].size()) {
            std::cout << "Coluna inválida.\n";
            return false;
        }
        if (seats[row][column]) {
            std::cout << "Poltrona já reservada.\n";
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
};

int main() {
    TicketOffice ticketOffice(15, 40);
    int option;
    while (true) {
        std::cout << "0. Sair\n1. Reservar poltrona\n2. Mostrar ocupação\n3. Mostrar faturamento\n";
        std::cin >> option;
        switch (option) {
        case 0:
            return 0;
        case 1:
            if (ticketOffice.reserveSeat())
                std::cout << "Reserva efetuada com sucesso!\n";
            break;
        case 2:
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