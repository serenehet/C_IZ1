/*
 * Составить программу нахождения треугольника с максимальной площадью среди всех,
 * которые можно построить, соединив произвольные три точки из заданного массива. Алгоритм оформить в виде функции,
 * получающей на вход два массива указателей на X — и Y-координаты точек.
 * На выход функция должна вернуть массив указателей из трех элементов на номера точек,
 * образующих найденный треугольник.
 *
 * Несколько проверочных тестов:
 *
 *  ---
 *  Ввод:
 *      0
 *  Ввывод:
 *
 *  ---
 *  Ввод:
 *      3
 *      1.0 2.0
 *      0.0 0.0
 *      3.3 3.3
 *  Вывод:
 *      0 1 2
 *  ---
 *  Ввод:
 *      дляпроверки
 *  Вывод:
 *
 *  ---
 *  Ввод:
 *      2
 *      1.0 2.0
 *      0.0 0.0
 *  Вывод:
 *
 *  ---
 *  Ввод:
 *  4
 *  0.0 6.7
    12.56 8.9
    0.0 0.0
    6.1 90.0
    Вывод:
    1 2 3
    ---
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Points{
    float **xArray;
    float **yArray;
} Points;


int fillPoints(Points * points);
float getAreaTriangle(float x1, float x2, float x3, float y1, float y2, float y3);
int **getIndexOfMaxAreaTriangle(float ** xArray, float ** yArray, size_t n);
void printPtrArray(int ** indexArray, size_t size);
void freeIndexArray(int *** indexArray, size_t size);
void freePoints(Points * points, size_t size);

const unsigned int numberOfVertices = 3; // у треугольника 3 вершины :)
const unsigned int maxLengthIntStr = 12; // максимальная длина int в строковом типе + последний символ \0
const unsigned int maxLengthFloatStr = 25; // максимальная длина int в строковом типе + последний символ \0

int main() {
    Points points;
    points.xArray = NULL;
    points.yArray = NULL;

    size_t size = fillPoints(&points);
    if (size == 0) { return 0; }

    int ** indexArray = getIndexOfMaxAreaTriangle(points.xArray, points.yArray, size);
    if (indexArray == NULL) { freePoints(&points, size); return 0; }

    printPtrArray(indexArray, numberOfVertices);

    freeIndexArray(&indexArray, numberOfVertices);   //изменить
    freePoints(&points, size);
    return 0;
}

int fillPoints(Points * points) {
    unsigned int maxLength = maxLengthIntStr;
    char * buffer = calloc(maxLength, sizeof(char));
    if (buffer == NULL) { return 0; }
    char temp;

    int i = 0;
    while (((temp = getchar()) != '\n') && temp != ' ') {
        if (i >= maxLength) { i = 0; break; }
        buffer[i++] = temp;
    }

    buffer[i] = '\0';
    unsigned int size  = 0;

    if (i != 0) {
        size = atoi(buffer);
    } else {
        size = 0;
    }

    maxLength = maxLengthFloatStr;
    if (size < numberOfVertices) { return 0; }
    points->xArray = (float **)calloc(size, sizeof(float *));
    points->yArray = (float **)calloc(size, sizeof(float *));

    for (size_t i = 0; i < size; ++i) {
        points->xArray[i] = (float *)malloc(sizeof(float));
        points->yArray[i] = (float *)malloc(sizeof(float));
        if (points->xArray[i] == NULL || points->yArray == NULL) { freePoints(&points, size); return 0; }
        free(buffer);
        buffer = calloc(maxLength, sizeof(char));
        if (buffer == NULL) { freePoints(&points, size); return 0; }
        int j = 0;
        while (((temp = getchar()) != '\n') && temp != ' ') {
            buffer[j++] = temp;
        }
        buffer[j] = '\0';
        points->xArray[i][0] = atof(buffer);
        j = 0;
        free(buffer);
        buffer = calloc(maxLength, sizeof(char));
        if (buffer == NULL) { freePoints(&points, size); return 0; }
        while (((temp = getchar()) != '\n') && temp != ' ') {
            buffer[j++] = temp;
        }
        buffer[j] = '\0';
        points->yArray[i][0] = atof(buffer);
    }

    free(buffer);

    return size;
}

float getAreaTriangle(float x1, float x2, float x3, float y1, float y2, float y3) {
    float point1 = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    float point2 = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
    float point3 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    float halfPerimetr = (point1 + point2 + point3) / 2;
    return sqrtf(halfPerimetr * (halfPerimetr - point1) * (halfPerimetr - point2) * (halfPerimetr - point3));   //формула Герона для выч. площади
}


int **getIndexOfMaxAreaTriangle(float ** xArray, float ** yArray, size_t n) {
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

