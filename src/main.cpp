#include "financial_instrument.hpp"

#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::cout << "Система управления финансовым портфелем\n\n";

    // Пока данные создаются прямо в программе.
    // Позже вместо этого добавим чтение из CSV, а затем из Parquet.
    std::vector<std::unique_ptr<FinancialInstrument>> instruments;
    instruments.push_back(std::make_unique<Stock>("AAPL", "Apple", 230.0));
    instruments.push_back(std::make_unique<Bond>("US10Y", "US Treasury 10Y", 98.5));
    instruments.push_back(std::make_unique<Cryptocurrency>("BTC", "Bitcoin", 110000.0));

    std::cout << "Доступные инструменты:\n";
    for (const auto& instrument : instruments) {
        instrument->print();
    }

    return 0;
}

