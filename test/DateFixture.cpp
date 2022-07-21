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

TEST_F(DateTests,DateConstructor){

    EXPECT_EQ(Date(17,9,1999),d);
}

TEST_F(DateTests,DateDaySetter){
    EXPECT_EQ(true,d.setDay(10));
    EXPECT_EQ(true,d.setDay(20));
    EXPECT_EQ(true,d.setDay(30));
    EXPECT_EQ(false,d.setDay(40));
}
TEST_F(DateTests,DateMonthSetter){
    EXPECT_EQ(true,d.setMonth(1));
    EXPECT_EQ(true,d.setMonth(2));
    EXPECT_EQ(true,d.setMonth(3));
    EXPECT_EQ(false,d.setMonth(40));
}
TEST_F(DateTests,DateYearSetter){
    EXPECT_EQ(true,d.setYear(2000));
    EXPECT_EQ(true,d.setYear(2001));
    EXPECT_EQ(true,d.setYear(2002));
    EXPECT_EQ(false,d.setYear(-100));
}

