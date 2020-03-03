//
// Created by Sergei Alexeev on 03.03.2020.
//

#ifndef IZ1_DZ_H
#define IZ1_DZ_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Points{
    float **xArray;
    float **yArray;
} Points;

int getInt();
float getFloat();
int fillPoints(Points * points);
float getAreaTriangle(float x1, float x2, float x3, float y1, float y2, float y3);
int **getIndexOfMaxAreaTriangle(float ** xArray, float ** yArray, size_t n);
void printPtrArray(int ** indexArray, size_t size);
void freeIndexArray(int *** indexArray, size_t size);
void freePoints(Points * points, size_t size);


#endif //IZ1_DZ_H
