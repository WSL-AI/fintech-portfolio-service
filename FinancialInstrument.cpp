#include "FinancialInstrument.h"

using namespace std;

FinancialInstrument::FinancialInstrument(string symbol, string name, double price)
    : symbol_(symbol), name_(name), price_(price) {}

void FinancialInstrument::print() const {
    cout << getType() << ": " << name_ << " (" << symbol_ << ") — " << price_ << " USD\n";
}

const string& FinancialInstrument::getSymbol() const {
    return symbol_;
}

const string& FinancialInstrument::getName() const {
    return name_;
}

double FinancialInstrument::getPrice() const {
    return price_;
}

string Stock::getType() const {
    return "Акция";
}

string Bond::getType() const {
    return "Облигация";
}

string Cryptocurrency::getType() const {
    return "Криптовалюта";
}

