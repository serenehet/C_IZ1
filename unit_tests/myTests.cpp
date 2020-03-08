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
    size_t size = 0;
    float **xArray = NULL;
    float **yArray = NULL;

    int ** testRes = getIndexOfMaxAreaTriangle(xArray, yArray, size);
    ASSERT_EQ(NULL, testRes);

}

TEST(testDecision, test2) {
    size_t size = 2;
    float **xArray = NULL;
    float **yArray = NULL;

    int ** testRes = getIndexOfMaxAreaTriangle(xArray, yArray, size);
    ASSERT_EQ(NULL, testRes);
}


TEST(testDecision, test3) {
    size_t size = 4;
    float ** pointsArray = (float **)calloc(2, sizeof(float *));
    pointsArray[0] = (float *)calloc(size, sizeof(float));
    pointsArray[1] = (float *)calloc(size, sizeof(float));
    pointsArray[0][0] = 0;
    pointsArray[1][0] = 0;
    pointsArray[0][1] = 2;
    pointsArray[1][1] = 2;
    pointsArray[0][2] = 9;
    pointsArray[1][2] = 0;
    pointsArray[0][3] = 0;
    pointsArray[1][3] = 9;

    int ** res = getIndexOfMaxAreaTriangle(&(pointsArray[0]), &(pointsArray[1]), size);
    ASSERT_EQ(0, res[0][0]);
    ASSERT_EQ(2, res[1][0]);
    ASSERT_EQ(3, res[2][0]);

    freePointsArray(&pointsArray, 2);
    freeIndexArray(&res, 3);
}
