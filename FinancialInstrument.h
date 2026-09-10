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
    Stock(string symbol, string name, double price, string exchange, double dividendYield);

    string getType() const override;
    void print() const override;
    const string& getExchange() const;
    double getDividendYield() const;

    private:
        string exchange_;
        double dividendYield_;
};

class Bond : public FinancialInstrument {
public:
    Bond(string symbol, string name, double price, double faceValue, double couponRate, string maturityDate);

    string getType() const override;
    void print() const override;
    double getFaceValue() const;
    double getCouponRate() const;
    const string& getMaturityDate() const;

    private:
        double faceValue_; //номинал облигации
        double couponRate_; //процент купона
        string maturityDate_; //дата погашения
};

class Cryptocurrency : public FinancialInstrument {
public:
    Cryptocurrency(string symbol, string name, double price, string blockchainNetwork);

    string getType() const override;
    void print() const override;
    const string& getBlockchainNetwork() const;

private:
    string blockchainNetwork_;
};
