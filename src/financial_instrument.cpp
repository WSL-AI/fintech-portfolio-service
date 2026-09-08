#include "financial_instrument.hpp"

#include <utility>

FinancialInstrument::FinancialInstrument(std::string symbol, std::string name, double price)
    : symbol_(std::move(symbol)), name_(std::move(name)), price_(price) {}

void FinancialInstrument::print() const {
    std::cout << getType() << ": " << name_ << " (" << symbol_ << ") — " << price_
              << " USD\n";
}

const std::string& FinancialInstrument::getSymbol() const {
    return symbol_;
}

const std::string& FinancialInstrument::getName() const {
    return name_;
}

double FinancialInstrument::getPrice() const {
    return price_;
}

std::string Stock::getType() const {
    return "Акция";
}

std::string Bond::getType() const {
    return "Облигация";
}

std::string Cryptocurrency::getType() const {
    return "Криптовалюта";
}

