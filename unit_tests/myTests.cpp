//
// Created by Sergei Alexeev on 03.03.2020.
//

#include "gtest/gtest.h"
extern "C" {
#include "dz.h"
}

TEST(testAreaComparison, test1) {
    float area1 = getAreaTriangle(0, 9, 0, 0, 9, 9);
    float area2 = getAreaTriangle(2, 3, 4, 4, 3, 2);
    ASSERT_EQ(area1 > area2, true);
}

TEST(testDecision, test1) {
    Points points;
    size_t size = 3;
    points.xArray = (float *)calloc(size, sizeof(float));
    points.yArray = (float *)calloc(size, sizeof(float));

    points.xArray[0] = 0; points.yArray[0] = 0;
    points.xArray[1] = 0; points.yArray[1] = 1;
    points.xArray[2] = 1; points.yArray[2] = 0;

    int ** testRes = getIndexMaxAreaTriangle(points.xArray, points.yArray, size);

    ASSERT_EQ(0, testRes[0][0]);
    ASSERT_EQ(1, testRes[1][0]);
    ASSERT_EQ(2, testRes[2][0]);

    freeIndexArray(&testRes, 3);
    freePoints(&points);
}

TEST(testDecision, test2) {
    int ** testRes = getIndexMaxAreaTriangle(NULL, NULL, 0);

    ASSERT_EQ(NULL, testRes);
}

TEST(testDecision, test3) {
    int ** testRes = getIndexMaxAreaTriangle(NULL, NULL, 2);

    ASSERT_EQ(NULL, testRes);
}

TEST(testDecision, test4) {
    int ** testRes = getIndexMaxAreaTriangle(NULL, NULL, 4);

    ASSERT_EQ(NULL, testRes);
}

TEST(testDecision, test5) {
    Points points;
    size_t size = 4;
    points.xArray = (float *)calloc(size, sizeof(float));
    points.yArray = (float *)calloc(size, sizeof(float));

    points.xArray[0] = 0; points.yArray[0] = 0;
    points.xArray[1] = 2; points.yArray[1] = 2;
    points.xArray[2] = 9; points.yArray[2] = 0;
    points.xArray[3] = 0; points.yArray[3] = 9;

    int ** testRes = getIndexMaxAreaTriangle(points.xArray, points.yArray, size);

    ASSERT_EQ(0, testRes[0][0]);
    ASSERT_EQ(2, testRes[1][0]);
    ASSERT_EQ(3, testRes[2][0]);

    freeIndexArray(&testRes, 3);
    freePoints(&points);
}
