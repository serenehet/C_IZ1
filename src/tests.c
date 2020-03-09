//
// Created by Sergei Alexeev on 09.03.2020.
//

#include "../include/tests.h"
#include "dz.h"

int testAll() {
    test1AreaComparison();
    test1Decision();
    test2Decision();
    test3Decision();
    test4Decision();
    test5Decision();
    return 0;
}

int test1AreaComparison() {
    float area1 = getAreaTriangle(0, 9, 0, 0, 9, 9);
    float area2 = getAreaTriangle(2, 3, 4, 4, 3, 2);
    return area1 > area2;
}

int test1Decision() {
    Points points;
    size_t size = 3;
    points.xArray = (float *)calloc(size, sizeof(float));
    points.yArray = (float *)calloc(size, sizeof(float));

    points.xArray[0] = 0; points.yArray[0] = 0;
    points.xArray[1] = 0; points.yArray[1] = 1;
    points.xArray[2] = 1; points.yArray[2] = 0;

    int ** testRes = getIndexMaxAreaTriangle(points.xArray, points.yArray, size);

    int key = (0 == testRes[0][0]);
    key = (key && (1 == testRes[1][0]));
    key = (key && (2 == testRes[2][0]));

    freeIndexArray(&testRes, 3);
    freePoints(&points);
    return key;
}

int test2Decision() {
    int ** testRes = getIndexMaxAreaTriangle(NULL, NULL, 0);
    return testRes == NULL;
}

int test3Decision() {
    int ** testRes = getIndexMaxAreaTriangle(NULL, NULL, 2);
    return testRes == NULL;
}

int test4Decision() {
    int ** testRes = getIndexMaxAreaTriangle(NULL, NULL, 4);
    return testRes == NULL;
}

int test5Decision() {
    Points points;
    size_t size = 4;
    points.xArray = (float *)calloc(size, sizeof(float));
    points.yArray = (float *)calloc(size, sizeof(float));

    points.xArray[0] = 0; points.yArray[0] = 0;
    points.xArray[1] = 2; points.yArray[1] = 2;
    points.xArray[2] = 9; points.yArray[2] = 0;
    points.xArray[3] = 0; points.yArray[3] = 9;

    int ** testRes = getIndexMaxAreaTriangle(points.xArray, points.yArray, size);

    int key = (0 == testRes[0][0]);
    key = (key && (2 == testRes[1][0]));
    key = (key && (3 == testRes[2][0]));

    freeIndexArray(&testRes, 3);
    freePoints(&points);
    return key;
}