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


