//
// Created by jayse on 09/07/2022.
//

#include "BankAccount.h"


//Reads all the transactions file and prints its content in the console
void BankAccount::readTransactionsFile() {

    std::string tmp;
    transactionsFile.seekp(0);
    while(std::getline(transactionsFile,tmp))
        std::cout<<tmp<<std::endl;


}
//Writes a single given transaction in the transactions file
//Updates the total balance of the account and determines if the account is in the red
void BankAccount::writeTransaction(const Transaction &transaction) {

    transactionsFile << transaction.getDescription() <<std::endl;
    transactionsFile << transaction.getDate().dateToString();
    transactionsFile << " alle ";
    transactionsFile << transaction.getTHour().hourToString() <<std::endl;
    transactionsFile << transaction.getIban()  <<std::endl;
    transactionsFile <<"EUR "<< transaction.getSum() <<std::endl;
    transactionsFile<<std::endl;

    updateAccount(transaction);



}
//Writes all the transactions in the transaction list into the transaction file
void BankAccount::writeAllTransactions() {
    for(auto i : transactionList){
        writeTransaction(*i);
    }

}

//Private method that updates the total balance of the account and determines if the account is in the red
void BankAccount::updateAccount(const Transaction &transaction) {
    totalBalance += transaction.getSum();
    if(totalBalance<0)
        isInTheRed = true;
}





