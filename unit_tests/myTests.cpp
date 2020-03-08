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
    size_t size = 3;
    float ** xArray = (float **)calloc(3, sizeof(float *));
    float ** yArray = (float **)calloc(3, sizeof(float *));
    int ** res = (int **)calloc(3, sizeof(int *));
    for (int i = 0; i < size; ++i) {
        xArray[i] = (float *)malloc(sizeof(float));
        yArray[i] = (float *)malloc(sizeof(float));
        res[i] = (int *)malloc(sizeof(int));
    }

    xArray[0][0] = 0; yArray[0][0] = 0;
    xArray[1][0] = 0; yArray[1][0] = 9;
    xArray[2][0] = 9; yArray[2][0] = 0;

    res[0][0] = 0; res[1][0] = 1; res[2][0] = 2;

    int ** testRes = getIndexOfMaxAreaTriangle(xArray, yArray, size);
    ASSERT_EQ(res[0][0], testRes[0][0]);
    ASSERT_EQ(res[1][0], testRes[1][0]);
    ASSERT_EQ(res[2][0], testRes[2][0]);

    freeIndexArray(&testRes, 3);
    freeIndexArray(&res, 3);
    float ** pointsArray = (float **)calloc(2, sizeof(float *));
    pointsArray[0] = *xArray;
    pointsArray[1] = *yArray;
    freePointsArray(&pointsArray, 2);
    free(xArray);
    free(yArray);
}

TEST(testDecision, test2) {
    size_t size = 0;
    float **xArray = NULL;
    float **yArray = NULL;

    int ** testRes = getIndexOfMaxAreaTriangle(xArray, yArray, size);
    ASSERT_EQ(NULL, testRes);

}

TEST(testDecision, test3) {
    size_t size = 2;
    float **xArray = NULL;
    float **yArray = NULL;

    int ** testRes = getIndexOfMaxAreaTriangle(xArray, yArray, size);
    ASSERT_EQ(NULL, testRes);
}


TEST(testDecision, test4) {
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
