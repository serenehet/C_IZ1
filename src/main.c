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
 *      5
 *      0.0 0.0
 *      5.0 5.0
 *      90.3 90.3
 *      -90.4 - 90.5
 *      5 5.8
 *  Вывод:
 *      2 3 4
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
#include "../include/dz.h"

extern unsigned int numberOfVertices;

int main() {
    Points points;
    points.xArray = NULL;
    points.yArray = NULL;

    size_t size = 0;
    size = fillPoints(&points);
    if (size == 0) { return 0; }

    int ** indexArray = getIndexOfMaxAreaTriangle(points.xArray, points.yArray, size);
    if (indexArray == NULL) { freePoints(&points, size); return 0; }

    printPtrArray(indexArray, numberOfVertices);

    freeIndexArray(&indexArray, numberOfVertices);
    freePoints(&points, size);
    return 0;
}
