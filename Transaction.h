//
// Created by jayse on 06/07/2022.
//

#ifndef ELABORATO_SENONER_JAY_TRANSACTION_H
#define ELABORATO_SENONER_JAY_TRANSACTION_H
#include <string>
#include "Date.h"

class Transaction {
    private:
        std::string description;
        float sum;
        std::string iban;
        const int precision = 2;        //Fixed precision that we use(along with setprecision()) to print and read values
        Date date;

};


#endif //ELABORATO_SENONER_JAY_TRANSACTION_H
