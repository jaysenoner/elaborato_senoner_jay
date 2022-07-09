//
// Created by jayse on 06/07/2022.
//

#include "Transaction.h"

void Transaction::printTransaction() {

    std::cout<<"Description: "<< description <<std::endl;
    std::cout<<"Iban: "<< iban<<std::endl;
    std::cout<<"Date: ";
    date.printDate();
    std::cout<<"Sum:"<<std::setprecision(precision) << sum  <<std::endl;
}

const std::string &Transaction::getDescription() const {
    return description;
}

void Transaction::setDescription(const std::string &description) {
    Transaction::description = description;
}

float Transaction::getSum() const {
    return sum;
}

void Transaction::setSum(float sum) {
    Transaction::sum = sum;
}

const std::string &Transaction::getIban() const {
    return iban;
}

void Transaction::setIban(const std::string &iban) {
    Transaction::iban = iban;
}

const int Transaction::getPrecision() const {
    return precision;
}

const Date &Transaction::getDate() const {
    return date;
}

void Transaction::setDate(const Date &date) {
    Transaction::date = date;
}
