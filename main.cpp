#include <iostream>
#include <fstream>
#include "Transaction.h"
#include "BankAccount.h"

int main() {

    Date d(17,9,1999);
    Hour h(13,29);
    Transaction t("Acquisto presso apple",1000,"IT734284728293743298",d,h);
    BankAccount myBank;
    myBank.writeTransaction(t);
    myBank.readTransactionsFile();



}
