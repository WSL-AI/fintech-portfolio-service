#pragma once

#include <iostream>
#include <string>

using namespace std;

// Общий базовый класс для всех финансовых инструментов.
class FinancialInstrument {
public:
    FinancialInstrument(string symbol, string name, double price);
    virtual ~FinancialInstrument() = default;

    virtual string getType() const = 0;
    virtual void print() const;

    const string& getSymbol() const;
    const string& getName() const;
    double getPrice() const;

protected:
    string symbol_;
    string name_;
    double price_;
};

class Stock : public FinancialInstrument {
public:
    using FinancialInstrument::FinancialInstrument;
    string getType() const override;
};

class Bond : public FinancialInstrument {
public:
    using FinancialInstrument::FinancialInstrument;
    string getType() const override;
};

class Cryptocurrency : public FinancialInstrument {
public:
    using FinancialInstrument::FinancialInstrument;
    string getType() const override;
};

