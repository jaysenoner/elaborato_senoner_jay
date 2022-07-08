//
// Created by jayse on 08/07/2022.
//

#include "gtest/gtest.h"
#include "../Date.h"

class DateTests : public ::testing::Test {


protected:
    Date d{};



protected:
    void SetUp() override {
        d.setDay(17);
        d.setMonth(9);
        d.setYear(1999);

    }





};

TEST_F(DateTests,TestConstructor){

    EXPECT_EQ(Date(17,9,1999),d);
}

