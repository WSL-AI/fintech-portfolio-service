#include "FinancialInstrument.h"

#include <iostream>
#include <memory>
#include <stdexcept>
#include <vector>

using namespace std;

int main() {
    cout << "Система управления финансовым портфелем\n\n";

    vector<unique_ptr<FinancialInstrument>> instruments;
    instruments.push_back(
        make_unique<Stock>("AAPL", "Apple", 230.0, "NASDAQ", 0.44)
    );

    instruments.push_back(
        make_unique<Bond>( "US10Y", "US Treasury 10Y", 98.5, 100.0, 4.25, "2035-05-15")
    );

    instruments.push_back(
        make_unique<Cryptocurrency>( "BTC", "Bitcoin", 110000.0, "Bitcoin")
    );

    // проверка
    try {
        Stock invalidStock(
            "TEST",
            "Некорректная акция",
            -100.0,
            "NASDAQ",
            2.5
        );
    } catch (const invalid_argument& error) {
        cout << "Ошибка: " << error.what() << '\n';
    }

    cout << "Доступные инструменты:\n";
    for (const auto& instrument : instruments) {
        instrument->print();
    }

    return 0;
}
