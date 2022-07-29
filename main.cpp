#include <iostream>

#include "Transaction.h"
#include "BankAccount.h"
#include <windows.h>

HANDLE he = GetStdHandle(STD_OUTPUT_HANDLE);

// TODO: Use this method to print charges in red and accreditations in green
// (Possible solutions): use string streams when reading the file,extract the floating point amount value, then call this
// method before printing
// Make so that the data is constantly held in a list, so we have easy access to it

void setColor(float value ){
    if(value<0) SetConsoleTextAttribute(he,12);
    else SetConsoleTextAttribute(he,10);
}


int main() {




    BankAccount myBank("IT47R0300203280386336756863");

    Date * date;
    Hour * hour;

    bool exit = false;
    bool dateFailed = false;
    bool hourFailed = false;
    char slash;
    int d, m, y;
    std::string description;
    float sum;
    myBank.loadTransactionList();






    do{
        int choice;
        SetConsoleTextAttribute(he,9);

        std::cout<<"===================================================== "<<std::endl;
        std::cout<<"Menu:" << std::endl;
        std::cout<<"  Press 1 to register a new transaction "<<std::endl;
        std::cout<<"  Press 2 to print the transactions list content to the console  " << std::endl;
        std::cout<<"  Press 3 to print the transactions file content to the console "<<std::endl;
        std::cout<<"  Press 4 to exit"<<std::endl;
        std::cout<<"===================================================== "<<std::endl;
        std::cin>>choice;


        switch(choice){

            //Takes in input the transaction data while checking for exceptions , then outputs the data into the file
            case 1:
                std::cout<<"Insert a description for the transaction"<<std::endl;
                std::getline(std::cin >> std::ws, description);
                std::cout<<"Insert the amount of money(positive or negative) involved in the transaction"<<std::endl;
                std::cin >>sum;
                if(sum<0 && myBank.isInTheRed1()){

                    std::cerr<<"[!] Cannot register charges while your account is in the red"<<std::endl;
                    break;
                }

                do {
                   // system("cls"); // TODO: replace with safer console clearing
                    std::cout << "Insert a valid date in the format DD/MM/YYYY" << std::endl;

                    std::cin >> d >> slash >> m >> slash >> y;
                    try {
                        date = new Date(d, m, y);
                    }
                    catch (std::runtime_error &e) {
                        std::cerr << e.what() << std::endl;
                        dateFailed = true;

                    }
                }while(dateFailed);

                do{
                   // system("cls"); // TODO: replace with safer console clearing
                    std::cout << "Insert a valid hour in the format HH:MM" << std::endl;
                    std::cin >> d >> slash >> m ;
                    try{
                        hour = new Hour(d,m);

                    }
                    catch (std::runtime_error &e) {
                        std::cerr << e.what() << std::endl;
                        hourFailed = true;

                    }
                }while(hourFailed);


                 //adds the transaction to the list and saves it in the file,while updating total balance;
                myBank.writeTransaction( myBank.addTransaction(Transaction(description, sum, myBank.getMyIban(), *date, *hour)));
                break;

            //Prints all the content of the transactions list to the console
            case 2:
                //system("cls"); // TODO: replace with safer console clearing

                myBank.printTransactionsList();


                break;

            case 3:
                myBank.readTransactionsFile();

                break;

            case 4:
                myBank.saveTransactionList();
                exit = true;
                break;
            default:
                std::cout<<"Please insert a valid command"<<std::endl;
            break;

        }




    }while(!exit);





}



