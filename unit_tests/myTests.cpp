//
// Created by Sergei Alexeev on 03.03.2020.
//

#include "gtest/gtest.h"
extern "C" {
#include "dz.h"
#include "tests.h"
}

TEST(testAreaComparison, test1) {
    ASSERT_EQ(test1AreaComparison(), true);
}

TEST(testDecision, test1) {
    ASSERT_EQ(test1Decision(), true);
}

TEST(testDecision, test2) {
    ASSERT_EQ(test2Decision(), true);
}

TEST(testDecision, test3) {
    ASSERT_EQ(test3Decision(), true);
}

TEST(testDecision, test4) {
    ASSERT_EQ(test4Decision(), true);
}

TEST(testDecision, test5) {
    ASSERT_EQ(test5Decision(), true);
}
