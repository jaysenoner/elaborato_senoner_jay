//
// Created by jayse on 06/07/2022.
//

#ifndef ELABORATO_SENONER_JAY_TRANSACTION_H
#define ELABORATO_SENONER_JAY_TRANSACTION_H
#include <string>
#include <utility>
#include <iomanip>
#include "Date.h"


class Transaction {
    private:
        std::string description;
        float sum{};
        std::string iban;
        const int precision = 2;        //Fixed precision that we use(along with setprecision()) to print and read values
        Date date{};


    public:
        Transaction() = default;
        ~Transaction() = default;
        Transaction(std::string description,float sum,std::string iban,int day,int month,int year) :
        description(std::move(description)),sum(sum),iban(std::move(iban)), date(Date(day,month,year)) {

        };
        Transaction(std::string description,float sum,std::string iban,Date& date) :
                description(std::move(description)),sum(sum),iban(std::move(iban)), date(date) {

        };

        void printTransaction();


        //Getters and Setters
        const std::string &getDescription() const;
        void setDescription(const std::string &description);
        float getSum() const;
        void setSum(float sum);
        const std::string &getIban() const;
        void setIban(const std::string &iban);
        const int getPrecision() const;
        const Date &getDate() const;
        void setDate(const Date &date);


};


#endif //ELABORATO_SENONER_JAY_TRANSACTION_H
