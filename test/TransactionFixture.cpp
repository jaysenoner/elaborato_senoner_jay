//
// Created by jayse on 17/07/2022.
//
#include "gtest/gtest.h"
#include "../Transaction.h"

class TransactionTests : public ::testing::Test {

protected:
    Transaction t;
    Hour h{};
    Date d{};
    void SetUp() override {
        h = Hour(12,0);
        d = Date(17,9,1999);

    }

};

TEST_F(TransactionTests,TransactionConstructor){
    t = Transaction("test",-1000,"test",d,h);
    EXPECT_EQ(true,t.isACharge1());
}
