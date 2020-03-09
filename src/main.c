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
 *      2 2
 *      3 3
 *      0 0
 *      90 0
 *      0 90
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
#include "../include/tests.h"
#include <stdbool.h>

extern unsigned int numberOfVertices;

int mainForUser();
int mainForTravis();

int main() {
    return mainForTravis(); // закоментировать для работы с юзером
//    return mainForUser(); // закоментировать для прохождения travis
}

int mainForTravis() {
    return testAll();
}

int mainForUser() {
    // выделяем память
    Points points;
    points.xArray = NULL;
    points.yArray = NULL;
    //заполняем массивы из стандартного ввода
    size_t size = fillPoints(&points); //закоментировать для travis
    if (size < 3) { return 0; }
    //получаем решение
    int ** indexArray = getIndexMaxAreaTriangle(points.xArray, points.yArray, size);
    if (indexArray == NULL) { return 0; }
    //печатаем решение
    printPtrArray((const int **) indexArray, numberOfVertices);
    //освобождаем память
    freeIndexArray(&indexArray, numberOfVertices);
    freePoints(&points);
}