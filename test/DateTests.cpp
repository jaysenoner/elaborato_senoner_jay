//
// Created by jayse on 08/07/2022.
//

#include "gtest/gtest.h"

#include "../Date.h"


TEST(DateTest, TestIsValidDate) {

    ASSERT_EQ(true, Date::isValidDate(17, 9, 1999));
    EXPECT_EQ(false, Date::isValidDate(35, -3, 1859));
    EXPECT_EQ(false, Date::isValidDate(17, -3, 1999));
    EXPECT_EQ(false, Date::isValidDate(35, 3, 1999));
    EXPECT_EQ(false, Date::isValidDate(1, 3, 1000));

}


