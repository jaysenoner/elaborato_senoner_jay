//
// Created by jayse on 06/07/2022.
//

#include "Transaction.h"


const std::string &Transaction::getDescription() const {
    return description;
}

float Transaction::getAmount() const {
    return amount;
}

const std::string &Transaction::getIban() const {
    return iban;
}

const Date &Transaction::getDate() const {
    return date;
}

Hour Transaction::getTHour() const {
    return t_hour;
}

bool Transaction::isACharge1() const {
    return isACharge;
}

void Transaction::printTransaction() const {
    std::cout << description << std::endl;
    std::cout << "EUR: " << amount << std::endl;
    std::cout << date.dateToString() << std::endl;
    std::cout << t_hour.hourToString() << std::endl;
    std::cout << iban << std::endl;
    std::cout << std::endl;
}

void Transaction::setDescription(const std::string &description) {
    Transaction::description = description;
}


