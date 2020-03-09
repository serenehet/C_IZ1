//
// Created by Sergei Alexeev on 03.03.2020.
//

#ifndef IZ1_DZ_H
#define IZ1_DZ_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Points{ float *xArray; float *yArray; } Points;

int getInt();
float getFloat();
size_t fillPoints(Points * points);
float getAreaTriangle(float x1, float x2, float x3, float y1, float y2, float y3);
int **getIndexMaxAreaTriangle(const float * xArray, const float * yArray, size_t size);
void printPtrArray(const int ** indexArray, size_t size);
void freeIndexArray(int *** indexArray, size_t size);
void freePoints(Points * points);

#endif //IZ1_DZ_H
