//
// Created by jayse on 09/07/2022.
//

#ifndef ELABORATO_SENONER_JAY_BANKACCOUNT_H
#define ELABORATO_SENONER_JAY_BANKACCOUNT_H


#include <list>
#include <fstream>
#include "Transaction.h"

class BankAccount {

private:
    std::list<Transaction*> transactionList;
    const int precision = 2;
    float totalBalance;
    bool isInTheRed;
    std::fstream transactionsFile;
    void updateAccount(const Transaction &transaction);

public:
    explicit BankAccount(float totalBalance=0,bool isInTheRed=false) : totalBalance(totalBalance), isInTheRed(isInTheRed) {
        transactionsFile.open("src/transactions_file.txt",std::ios::app | std::ios::in);
        if(!transactionsFile.is_open()){
            std::cerr<<"Failed to open transactions file"<<std::endl;
            throw std::runtime_error("Failed to open transactions file");
        }
    };
    ~BankAccount(){
        transactionsFile.close();
        for(auto i : transactionList)
            delete i;
    }
    void readTransactionsFile();
    void writeTransaction(const Transaction& transaction);
    void writeAllTransactions();


};


#endif //ELABORATO_SENONER_JAY_BANKACCOUNT_H
