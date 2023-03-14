#include <iostream>

#include "gtest/gtest.h"

#import "length.h"

TEST(Units, InitMeters) {
    Length l1 = Length::create_from_meters(1.0);
    ASSERT_EQ(1.0, l1.value_in_meters());
}

TEST(Units, Addition) {
    Length l1(Length::create_from_meters(1.0));
    Length l2(Length::create_from_meters(2.0));

    ASSERT_EQ(3.0, (l1+l2).value_in_meters());
}

