//
// Created by jayse on 13/07/2022.
//

#include "gtest/gtest.h"
#include "../Hour.h"


class HourTests : public ::testing::Test {

protected:
    Hour h{};
     void SetUp() override {
            h.setHour(12);
            h.setMin(0);
    }




};


TEST_F(HourTests,HourConstructor){
    EXPECT_EQ(h,Hour(12,0));
}

TEST_F(HourTests,HourToString){
    EXPECT_EQ("12:00", Hour(12,0).hourToString());
    EXPECT_EQ("09:00", Hour(9,0).hourToString());
    EXPECT_EQ("15:09", Hour(15,9).hourToString());
    EXPECT_EQ("12:34", Hour(12,34).hourToString());
}


TEST_F(HourTests,HourMinSetter){
    EXPECT_EQ(true,h.setMin(10));
    EXPECT_EQ(true,h.setMin(20));
    EXPECT_EQ(true,h.setMin(30));
    EXPECT_EQ(true,h.setMin(40));
    EXPECT_EQ(false,h.setMin(90));

}
TEST_F(HourTests,HourHSetter){
    EXPECT_EQ(true,h.setHour(0));
    EXPECT_EQ(true,h.setHour(10));
    EXPECT_EQ(true,h.setHour(5));
    EXPECT_EQ(true,h.setHour(2));
    EXPECT_EQ(false,h.setHour(70));

}