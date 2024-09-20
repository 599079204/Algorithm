//
// Created by Administrator on 2024/9/19.
//

#ifndef ZUOSHEN_LJW_H
#define ZUOSHEN_LJW_H

#include <bits/stdc++.h>

using namespace std;

/**
 * 打印整型数组, 可指定每个元素的宽度和每行的数字等
 */
void printArray(int array[], int size, int w = 0, int lineCount = 30) {
    for (int i = 0; i < size; ++i) {
        cout << setw(w) << array[i] << " ";
        if ((i + 1) % lineCount == 0) cout << endl;
    }
}

/**
 * 随机生成一些整型数据到数组中, 可指定是否打印以及数据的范围等
 */
void generateArrayData(int array[], int size,
                       bool print = false, int minV = 0, int maxV = 99) {
    srand(time(0));
    int modV = maxV - minV + 1;
    for (int i = 0; i < size; ++i) array[i] = minV + rand() % modV;
    if (print) printArray(array, size);
}

#endif //ZUOSHEN_LJW_H
