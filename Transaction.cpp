//
// Created by jayse on 06/07/2022.
//

#include "Transaction.h"



const std::string &Transaction::getDescription() const {
    return description;
}


float Transaction::getSum() const {
    return sum;
}



const std::string &Transaction::getIban() const {
    return iban;
}



const Date &Transaction::getDate() const {
    return date;
}

const Hour Transaction::getTHour() const {
    return t_hour;
}

bool Transaction::isACharge1() const {
    return isACharge;
}


