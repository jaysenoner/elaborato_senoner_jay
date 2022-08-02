//
// Created by jayse on 22/07/2022.
//

#include "gtest/gtest.h"
#include "../BankAccount.h"

class BankAccountTests : public ::testing::Test {

protected:
    Transaction t;
    Hour h{};
    Date d{};
    BankAccount bank{"IT734284728293743298",
                     R"(D:\programming_course_projects\elaborato_senoner_jay\src\transactions_file.txt)"};

    void SetUp() override {
        h = Hour(12, 0);
        d = Date(17, 9, 1999);
    }

};

TEST_F(BankAccountTests, loadTransactionListTest) {

    bank.loadTransactionList();
    bank.printTransactionsList();


}

TEST_F(BankAccountTests, deleteTransactionTest) {
    bank.loadTransactionList();
    t = Transaction("test", -1000, "test", d, h);
    int oldSize = bank.getTransactionListSize();
    bank.addTransaction(t);
    bank.deleteTransaction(t.getDescription());
    EXPECT_EQ(oldSize, bank.getTransactionListSize());
}

