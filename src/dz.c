//
// Created by Sergei Alexeev on 03.03.2020.
//

#include "../include/dz.h"
#include <stdio.h>

const unsigned int maxLengthIntStr = 12; // максимальная длина int в строковом типе + последний символ \0
const unsigned int maxLengthFloatStr = 25; // максимальная длина float в строковом типе + последний символ \0
const unsigned int numberOfVertices = 3; // у треугольника 3 вершины :)
const unsigned nCoordinates = 2;

int getInt() {
    char * buffer = calloc(maxLengthIntStr, sizeof(char));
    if (buffer == NULL) { return 0; }

    char temp;
    int i = 0;
    while (((temp = (char)getchar()) != '\n') && temp != ' ') {
        if (i >= maxLengthIntStr) { i = 0; break; }
        buffer[i++] = temp;
    }
    buffer[i] = '\0';

    int number  = 0;
    if (i != 0) {
        number = atoi(buffer);
    }

    free(buffer);
    return number;
}

float getFloat() {
    char * buffer = calloc(maxLengthFloatStr, sizeof(char));
    if (buffer == NULL) { return 0.0f; }

    char temp;
    int i = 0;
    while (((temp = getchar()) != '\n') && temp != ' ') {
        if (i >= maxLengthFloatStr) { i = 0; break; }
        buffer[i++] = temp;
    }
    buffer[i] = '\0';

    float number = 0.0f;

    if (i != 0) {
        number = atof(buffer);
    }

    free(buffer);
    return number;
}

size_t fillPoints(Points * points) {
    //получаем колво точек
    size_t size = (size_t)getInt();
    if (points == NULL || size < 3 ) { return 0; }

    //выделяем память под x координаты
    if (points->xArray != NULL) { free(points->xArray); }
    points->xArray = (float *)calloc(size, sizeof(float));
    if (points->xArray == NULL) { return 0; }

    //выделяем память под у координаты
    if (points->yArray != NULL) { free(points->yArray); }
    points->yArray = (float *)calloc(size, sizeof(float));
    if (points->yArray == NULL) { freePoints(points); return 0; }
    for (size_t i = 0; i < size; ++i) {
        points->xArray[i] = getFloat();
        points->yArray[i] = getFloat();
    }
    return size;
}

float getAreaTriangle(float x1, float x2, float x3, float y1, float y2, float y3) {
    // не используем корни, они не влияют на результат сравнения площадей
    float size1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    float midx12 = (x1 + x2) / 2;
    float midy12 = (y1 + y2) / 2;
    float size2 = (x3 - midx12) * (x3 - midx12) + (y3 - midy12) * (y3 - midy12);
    return size1 * size2;
}

int **getIndexMaxAreaTriangle(const float * xArray, const float * yArray, size_t size) {
    if (size < numberOfVertices || xArray == NULL || yArray == NULL) { return NULL; }

    int ** res = (int **)calloc(numberOfVertices, sizeof(int *));
    if (res == NULL) { return  NULL;}
    for (size_t i = 0 ; i < numberOfVertices; ++i) {
        res[i] = (int *)malloc(sizeof(int));
        if (res[i] == NULL) {
            freeIndexArray(&res, i);
        }
    }
    // перебираем тройки решений
    float maxArea = 0.0f;
    for (size_t i = 0; i < size - 2; ++i) {
        for (size_t j = i + 1; j < size -1; ++j) {
            for (size_t t = j + 1; t < size; ++t) {
                float temp = (getAreaTriangle(xArray[i], xArray[j], xArray[t], yArray[i], yArray[j], yArray[t]));
                if (temp > maxArea) {
                    *(res[0]) = i;
                    *(res[1]) = j;
                    *(res[2]) = t;
                    maxArea = temp;
                }
            }
        }
    }

    if (maxArea <= 0.0f) { freeIndexArray(&res, numberOfVertices); return NULL; }
    return res;
}

void printPtrArray(const int ** indexArray, size_t size) {
    if (indexArray == NULL) { return; }

    for (size_t i = 0; i < size; ++i) {
        printf("%d ", *indexArray[i]);
    }
}

void freeIndexArray(int *** indexArray, size_t size) {
    if (indexArray == NULL) { return; }

    for (size_t i = 0; i < size; i++) {
        free(indexArray[0][i]);
    }
    free(indexArray[0]);
}

void freePoints(Points * points) {
    free(points->xArray);
    free(points->yArray);
}
