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

    std::list<Transaction> transactionList;

    float totalBalance;
    bool isInTheRed;
    std::fstream transactionsFile;
    std::string myIban;

    void updateAccount(const Transaction &transaction);

    std::list<Transaction>::iterator searchTransaction(const std::string &description);


public:

    explicit BankAccount(const std::string &myIban, float totalBalance = 0, bool isInTheRed = false) : myIban(myIban),
                                                                                                       totalBalance(
                                                                                                               totalBalance),
                                                                                                       isInTheRed(
                                                                                                               isInTheRed) {
        transactionsFile.open("src/transactions_file.txt", std::ios::app | std::ios::in);
        if (!transactionsFile.is_open()) {

            throw std::runtime_error("Failed to open transactions file");
        } else {
            totalBalance = BankAccount::readTotalBalance();
            if (totalBalance < 0) this->isInTheRed = true;
        }
    };

    BankAccount(const std::string &myIban, const std::string &path, float totalBalance = 0, bool isInTheRed = false)
            : myIban(myIban), totalBalance(totalBalance), isInTheRed(isInTheRed) {
        transactionsFile.open(path, std::ios::app | std::ios::in);
        if (!transactionsFile.is_open()) {

            throw std::runtime_error("Failed to open transactions file");
        } else {
            totalBalance = BankAccount::readTotalBalance();
            if (totalBalance < 0) this->isInTheRed = true;
        }
    };


    ~BankAccount() {
        transactionsFile.close();

    }

    // TODO: modificare transazione,cercare e cancellare
    void loadTransactionList();

    void updateTransaction(const std::string &description);

    void deleteTransaction(const std::string &description);

    void saveTransactionList();

    void printTransactionsList() const;

    const Transaction &addTransaction(const Transaction &transaction);

    int getTransactionListSize() const { return transactionList.size(); }

    void readTransactionsFile() const;

    void writeTransaction(const Transaction &transaction);

    float readTotalBalance() const;

    bool isInTheRed1() const;

    float extractFloatFromString(std::string tmp_string) const;

    void writeTotalBalance();

    const std::string &getMyIban() const;
};


#endif //ELABORATO_SENONER_JAY_BANKACCOUNT_H
