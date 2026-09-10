#include <stdexcept>

#include "FinancialInstrument.h"

using namespace std;

FinancialInstrument::FinancialInstrument(string symbol, string name, double price):symbol_(symbol), name_(name), price_(price)
{
    if (price < 0) throw invalid_argument("Цена не может быть отрицательной");
}

Stock::Stock(string symbol, string name, double price, string exchange, double dividendYield) :
        FinancialInstrument(symbol, name, price), exchange_(exchange), dividendYield_(dividendYield) {

    if (dividendYield < 0) {
        throw invalid_argument(
            "Дивидендная доходность не может быть отрицательной"
        );
    }
}
Bond::Bond(string symbol, string name, double price, double faceValue, double couponRate, string maturityDate) :
        FinancialInstrument(symbol, name, price), faceValue_(faceValue), couponRate_(couponRate), maturityDate_(maturityDate) {
    if (faceValue < 0) {
        throw invalid_argument(
            "Номинал не может быть отрицательным"
        );
    }

    if (couponRate < 0) {
        throw invalid_argument(
            "Процент купона не может быть отрицательным"
        );
    }
}
Cryptocurrency::Cryptocurrency(string symbol,string name,double price,string blockchainNetwork):
        FinancialInstrument(symbol, name, price), blockchainNetwork_(blockchainNetwork) {
}

//общие
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


// для акциий
void Stock::print() const {
    FinancialInstrument::print();
    cout << "  Биржа: " << exchange_ << ", дивидендная доходность: " << dividendYield_ << "%\n";
}
string Stock::getType() const {
    return "Акция";
}
const string& Stock::getExchange() const {
    return exchange_;
}
double Stock::getDividendYield() const {
    return dividendYield_;
}


// для облигаций
void Bond::print() const {
    FinancialInstrument::print();
    cout << "  Номинал облигации: " << faceValue_
         << ", процент купона: " << couponRate_
         << "%, дата погашения: " << maturityDate_ << '\n';
}
double Bond::getFaceValue() const {
    return faceValue_;
}
double Bond::getCouponRate() const {
    return couponRate_;
}
const string& Bond::getMaturityDate() const {
    return maturityDate_;
}
string Bond::getType() const {
    return "Облигация";
}


//для критпы
string Cryptocurrency::getType() const {
    return "Крипта";
}
const string& Cryptocurrency::getBlockchainNetwork() const {
    return blockchainNetwork_;
}
void Cryptocurrency::print() const {
    FinancialInstrument::print();
    cout << "  Блокчейн: "
         << blockchainNetwork_ << '\n';
}
