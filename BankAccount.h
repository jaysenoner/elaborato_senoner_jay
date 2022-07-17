//
// Created by jayse on 09/07/2022.
//

#ifndef ELABORATO_SENONER_JAY_BANKACCOUNT_H
#define ELABORATO_SENONER_JAY_BANKACCOUNT_H


#include <list>
#include <fstream>
#include <sstream>
#include <utility>
#include "Transaction.h"

class BankAccount {

private:

    const int precision = 2;
    float totalBalance;
    bool isInTheRed;
    std::fstream transactionsFile;
    std::string myIban;
    void updateAccount(const Transaction &transaction);

public:

    explicit BankAccount(std::string myIban,float totalBalance=0,bool isInTheRed=false) :myIban(std::move(myIban)), totalBalance(totalBalance), isInTheRed(isInTheRed) {
        transactionsFile.open("src/transactions_file.txt",std::ios::app | std::ios::in);
        if(!transactionsFile.is_open()){

            throw std::runtime_error("Failed to open transactions file");
        }
        else {
            totalBalance = BankAccount::readTotalBalance();
            if(totalBalance<0) this->isInTheRed = true;
        }
    };
    ~BankAccount(){
        transactionsFile.close();

    }
    void readTransactionsFile();
    void writeTransaction(const Transaction& transaction);
    float readTotalBalance();
    bool isInTheRed1() const;
    float extractFloatFromString(std::string tmp_string);
    void writeTotalBalance();
    const std::string &getMyIban() const;
};


#endif //ELABORATO_SENONER_JAY_BANKACCOUNT_H
