//
// Created by jayse on 06/07/2022.
//

#ifndef ELABORATO_SENONER_JAY_TRANSACTION_H
#define ELABORATO_SENONER_JAY_TRANSACTION_H
#include <string>
#include <utility>
#include <iomanip>
#include "Date.h"
#include "Hour.h"

// TODO: Make precision work
class Transaction {
    private:
        std::string description;
        float amount{};
        std::string iban;
      //const int precision = 2;        //Fixed precision that we use(along with std::setprecision()) to print and read values
        Date date{};
        Hour t_hour{};
        bool isACharge{};

    public:
        Transaction() = default;
        ~Transaction() = default;
        Transaction(std::string description,float sum,std::string iban,int day,int month,int year,int hour,int min) :
                description(std::move(description)), amount(sum), iban(std::move(iban)), date(day, month, year), t_hour(hour, min) {
            if(sum<0) isACharge = true;
            else isACharge = false;
        };
        Transaction(std::string description,float sum,std::string iban,Date& date,Hour& hour) :
                description(std::move(description)), amount(sum), iban(std::move(iban)), date(date), t_hour(hour) {
                    if(sum<0) isACharge = true;
                    else isACharge = false;
        };




        //Getters and Setters
        const std::string &getDescription() const;
        float getAmount() const;
        const std::string &getIban() const;
        const Date &getDate() const;
        Hour getTHour() const;
        bool isACharge1() const;

};


#endif //ELABORATO_SENONER_JAY_TRANSACTION_H
