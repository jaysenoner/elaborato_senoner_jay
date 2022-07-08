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
        float sum;
        std::string iban;
        const int precision = 2;        //Fixed precision that we use(along with setprecision()) to print and read values
        Date date;

    public:
        Transaction() = default;
        ~Transaction() = default;
        Transaction(std::string description,float sum,std::string iban,int day,int month,int year) :
        description(std::move(description)),sum(sum),iban(std::move(iban)), date(Date(day,month,year)) {

        };
        void printTransaction();


        //Getters and Setters
        const std::string &getDescription() const {
            return description;
        }
        void setDescription(const std::string &description) {
            Transaction::description = description;
        }
        float getSum() const {
            return sum;
        }
        void setSum(float sum) {
            Transaction::sum = sum;
        }
        const std::string &getIban() const {
            return iban;
        }
        void setIban(const std::string &iban) {
            Transaction::iban = iban;
        }
        const int getPrecision() const {
            return precision;
        }
        const Date &getDate() const {
            return date;
        }
        void setDate(const Date &date) {
            Transaction::date = date;
        }


};


#endif //ELABORATO_SENONER_JAY_TRANSACTION_H
