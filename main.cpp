#include "FinancialInstrument.h"

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main() {
    cout << "Система управления финансовым портфелем\n\n";

    // Пока данные создаются прямо в программе.
    // Позже вместо этого добавим чтение из CSV, а затем из Parquet.
    vector<unique_ptr<FinancialInstrument>> instruments;
    instruments.push_back(make_unique<Stock>("AAPL", "Apple", 230.0));
    instruments.push_back(make_unique<Bond>("US10Y", "US Treasury 10Y", 98.5));
    instruments.push_back(make_unique<Cryptocurrency>("BTC", "Bitcoin", 110000.0));

    cout << "Доступные инструменты:\n";
    for (const auto& instrument : instruments) {
        instrument->print();
    }

    return 0;
}

