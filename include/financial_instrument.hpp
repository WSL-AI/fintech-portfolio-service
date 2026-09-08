#pragma once

#include <iostream>
#include <string>

// Общий базовый класс для всех финансовых инструментов.
class FinancialInstrument {
public:
    FinancialInstrument(std::string symbol, std::string name, double price);
    virtual ~FinancialInstrument() = default;

    virtual std::string getType() const = 0;
    virtual void print() const;

    const std::string& getSymbol() const;
    const std::string& getName() const;
    double getPrice() const;

protected:
    std::string symbol_;
    std::string name_;
    double price_;
};

class Stock : public FinancialInstrument {
public:
    using FinancialInstrument::FinancialInstrument;
    std::string getType() const override;
};

class Bond : public FinancialInstrument {
public:
    using FinancialInstrument::FinancialInstrument;
    std::string getType() const override;
};

class Cryptocurrency : public FinancialInstrument {
public:
    using FinancialInstrument::FinancialInstrument;
    std::string getType() const override;
};

