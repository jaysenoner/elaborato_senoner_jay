//
// Created by jayse on 09/07/2022.
//

#include "BankAccount.h"


//Reads all the transactions file and prints its content in the console
void BankAccount::readTransactionsFile() {

    std::string tmp;
    transactionsFile.seekg(0);

    while(std::getline(transactionsFile,tmp))
        std::cout<<tmp<<std::endl;


}
//Writes a single given transaction in the transactions file
//Updates the total balance of the account and determines if the account is in the red
void BankAccount::writeTransaction(const Transaction &transaction) {

    std::ofstream transactionsFile;
    transactionsFile.open("src/transactions_file.txt",std::ios::app);


    transactionsFile << transaction.getDescription() << std::endl;
    transactionsFile << transaction.getDate().dateToString();
    transactionsFile << " alle ";
    transactionsFile << transaction.getTHour().hourToString() << std::endl;
    transactionsFile << transaction.getIban() << std::endl;
    transactionsFile << "EUR " << transaction.getAmount() << std::endl;
    transactionsFile << std::endl;
    transactionsFile.close();
    updateAccount(transaction);
}



//Private method that updates the total balance of the account and determines if the account is in the red
void BankAccount::updateAccount(const Transaction &transaction) {
    totalBalance = BankAccount::readTotalBalance() + transaction.getAmount();
    writeTotalBalance();
    if(totalBalance<0)
        isInTheRed = true;

}



bool BankAccount::isInTheRed1() const {
    return isInTheRed;
}

//Method that opens a file reading stream that reads the first line,which contains the total balance of the account
float BankAccount::readTotalBalance() {
        std::ifstream infile("src/transactions_file.txt");
        std::string tmp_string;
        std::getline(infile,tmp_string);
        infile.close();
        return extractFloatFromString(tmp_string);


}
//Method that extracts the floating point value of the total balance from the first line of the file
float BankAccount::extractFloatFromString(std::string tmp_string) {
    float tmp_float;
    std::stringstream  ss;
    ss << tmp_string;
    while(!ss.eof()){
        ss >> tmp_string;
        std::stringstream(tmp_string) >> tmp_float;
        tmp_string = "";
    }

    return tmp_float;
}

//Method that writes the updated value of the totalBalance(it is called after updateAccount has computed the new value)
// in the transactions file (it actually creates a new file to replace the old one)
void BankAccount::writeTotalBalance() {

            std::string newFirstLine = "Total Balance: EUR " +std::to_string(totalBalance)+ ";";
            std::string tmpString;
            std::ifstream filein("src/transactions_file.txt");
            std::ofstream tmp_out;
            tmp_out.open("src/tmp_file.txt");
            if(!filein || !tmp_out) std::cerr<<"Error opening files"<<std::endl;
            else {
                tmp_out <<std::fixed << std::setprecision(precision)<< newFirstLine <<std::endl ;
                int c = 0;
                while(std::getline(filein,tmpString)){
                    if(c!=0){
                        tmp_out << tmpString << std::endl;
                    }
                    c++;

                }
            }
            filein.close();
            tmp_out.close();
            transactionsFile.close();
            remove("src/transactions_file.txt");
            rename("src/tmp_file.txt","src/transactions_file.txt");
            transactionsFile.open("src/transactions_file.txt");


}

const std::string &BankAccount::getMyIban() const {
    return myIban;
}





