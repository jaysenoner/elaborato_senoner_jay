#include <iostream>
#include <fstream>
#include "Transaction.h"
#include "BankAccount.h"

int main() {
    BankAccount myBank;

    Date d(17,9,1999);
    Hour h(13,29);
    Transaction t("Acquisto presso apple",1000,"IT734284728293743298",d,h);


    myBank.writeTransaction(t);
    myBank.readTransactionsFile();
    std::cout<<myBank.readTotalBalance()<<std::endl;






}
