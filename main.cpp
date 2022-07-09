#include <iostream>
#include <fstream>
#include "Transaction.h"
#include "BankAccount.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    system("cd");

    Date d(17,9,1999);
    Transaction t("Acquisto presso apple store",1000,"IT734284728293743298",d);
    BankAccount myBank;
    myBank.writeTransaction(t);




}
