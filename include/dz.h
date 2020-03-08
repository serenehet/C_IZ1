//
// Created by Sergei Alexeev on 03.03.2020.
//

#ifndef IZ1_DZ_H
#define IZ1_DZ_H

#include <stdio.h>
#include <stdlib.h>

int getInt();
float getFloat();
size_t fillPointsArray(float ** pointsArray);
float getAreaTriangle(float x1, float x2, float x3, float y1, float y2, float y3);
int **getIndexOfMaxAreaTriangle(float ** xArray, float ** yArray, size_t n);
void printPtrArray(const int ** indexArray, size_t size);
void freeIndexArray(int *** indexArray, size_t size);
void freePointsArray(float *** pointsArray, size_t numberCoordinate);

#endif //IZ1_DZ_H
