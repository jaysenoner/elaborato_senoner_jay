//
// Created by jayse on 09/07/2022.
//

#include "BankAccount.h"

//Reads all the transactions file and prints its content in the console
void BankAccount::readTransactionsFile() {

    std::string tmp;
    while(std::getline(transactionsFile,tmp))
        std::cout<<tmp<<std::endl;
}
//Writes a single given transaction in the transactions file

void BankAccount::writeTransaction(const Transaction &transaction) {

    transactionsFile << transaction.getDescription() <<std::endl;
    transactionsFile << transaction.getDate().dateToString()  <<std::endl;
    transactionsFile << transaction.getIban()  <<std::endl;
    transactionsFile  << transaction.getSum()  <<std::endl;
    transactionsFile<<std::endl;


}
//Writes all the transactions in the transaction list into the transaction file
void BankAccount::writeAllTransactions() {
    for(auto i : transactionList){
        writeTransaction(*i);
    }

}

float BankAccount::getTotalBalance() const {
    return totalBalance;
}

void BankAccount::setTotalBalance(float totalBalance) {
    BankAccount::totalBalance = totalBalance;
}

bool BankAccount::isInTheRed1() const {
    return isInTheRed;
}

void BankAccount::setIsInTheRed(bool isInTheRed) {
    BankAccount::isInTheRed = isInTheRed;
}
