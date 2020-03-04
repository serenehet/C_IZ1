//
// Created by Sergei Alexeev on 03.03.2020.
//

#include "../include/dz.h"
#include <stdio.h>

const unsigned int maxLengthIntStr = 12; // максимальная длина int в строковом типе + последний символ \0
const unsigned int maxLengthFloatStr = 25; // максимальная длина int в строковом типе + последний символ \0
const unsigned int numberOfVertices = 3; // у треугольника 3 вершины :)

int getInt() {
    unsigned int maxLength = maxLengthIntStr;
    char * buffer = calloc(maxLength, sizeof(char));
    if (buffer == NULL) { return 0; }

    char temp;
    int i = 0;
    while (((temp = (char)getchar()) != '\n') && temp != ' ') {
        if (i >= maxLength) { i = 0; break; }
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
    unsigned int maxLength = maxLengthFloatStr;
    char * buffer = calloc(maxLength, sizeof(char));
    if (buffer == NULL) { return 0.0; }

    char temp;
    int i = 0;
    while (((temp = getchar()) != '\n') && temp != ' ') {
        if (i >= maxLength) { i = 0; break; }
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

int fillPoints(Points * points) {
    size_t size  = getInt();
    if (size < 3) { return  0; }
    points->xArray = (float **)calloc(size, sizeof(float *));
    points->yArray = (float **)calloc(size, sizeof(float *));

    for (size_t i = 0; i < size; ++i) {
        points->xArray[i] = (float *)malloc(sizeof(float));
        points->yArray[i] = (float *)malloc(sizeof(float));
        if (points->xArray[i] == NULL || points->yArray == NULL) { freePoints((Points *) &points, size); return 0; }

        points->xArray[i][0] = getFloat();
        points->yArray[i][0] = getFloat();
    }

    return size;
}

float getAreaTriangle(const float x1, const float x2, const float x3, const float y1, const float y2, const float y3) {
    // не используем корни, они не влияют
    float size1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    float midx12 = (x1 + x2) / 2;
    float midy12 = (y1 + y2) / 2;
    float size2 = (x3 - midx12) * (x3 - midx12) + (y3 - midy12) * (y3 - midy12);
    return size1 * size2;
}


int **getIndexOfMaxAreaTriangle(float ** xArray, float ** yArray, size_t n) {
    if (n < 3) { return NULL; }
    float maxArea = getAreaTriangle(*xArray[0], *xArray[1], *xArray[2], *yArray[0], *yArray[1], *yArray[2]);
    unsigned int i1 = 0, i2 = 1, i3 = 2;    // берем первые три элемента для начального максимальной площади
    for (size_t i = 0; i < n - 2; ++i) {
        for (size_t j = i + 1; j < n -1; ++j) {
            for (size_t t = j + 1; t < n; ++t) {
                float temp = (getAreaTriangle(*xArray[i], *xArray[j], *xArray[t], *yArray[i], *yArray[j], *yArray[t]));
                if (temp > maxArea) {
                    i1 = i;
                    i2 = j;
                    i3 = t;
                    maxArea = temp;
                }
            }
        }
    }

    if (maxArea <= 0.0) { return NULL; }


    int ** res = (int **)calloc(numberOfVertices, sizeof(int *));
    if (res == NULL) { return  NULL;}
    for (size_t i = 0 ; i < numberOfVertices; ++i) {
        res[i] = (int *)malloc(sizeof(int));
        if (res[i] == NULL) {
            for (int j = 0; j <= i; ++j) {
                free(res[j]);
            }
            free(res);
            return NULL;
        }
    }
    res[0][0] = i1; res[1][0] = i2; res[2][0] = i3;
    return res;
}

void printPtrArray(int ** indexArray, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", *indexArray[i]);
    }
}

void freeIndexArray(int *** indexArray, size_t size) {
    for (size_t i = 0; i < size; i++) {
        free(indexArray[0][i]);
    }
    free(indexArray[0]);
}

void freePoints(Points * points, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        free(points->xArray[i]);
        free(points->yArray[i]);
    }
    free(points->xArray);
    free(points->yArray);
}
