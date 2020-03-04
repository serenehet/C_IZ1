//
// Created by Sergei Alexeev on 03.03.2020.
//

#include "gtest/gtest.h"
extern "C" {
#include "dz.h"
}

TEST(testMainFunc, test1) {
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
    Points points;
    points.xArray = xArray;
    points.yArray = yArray;
    freePoints(&points, size);
}