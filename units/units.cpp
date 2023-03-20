#include <iostream>

#include "gtest/gtest.h"

#include "length.h"


/*
 * Documentation and primer: https://github.com/google/googletest/blob/main/docs/primer.md
 */

TEST(Units, InitMeters) {
    Length l1 = Length::create_from_meters(1.0);
    ASSERT_DOUBLE_EQ(1.0, l1.value_in_meters());
}

TEST(Units, Addition) {
    Length l1(Length::create_from_meters(1.0));
    Length l2(Length::create_from_meters(2.0));

    ASSERT_DOUBLE_EQ(3.0, (l1+l2).value_in_meters());
}

TEST(Units, InitFeet) {
    Length l1(Length::create_from_feet(10.0));

    ASSERT_DOUBLE_EQ(3.048, l1.value_in_meters());
}