#include <bits/stdc++.h>
#include "ljw.h"

using namespace std;

// 选择排序
void selectionSort(int array[], int size) {
    for (int i = 0, maxIndex, temp; i < size; ++i) {
        maxIndex = 0;
        for (int j = 1; j < size - i; ++j) {
            if (array[j] > array[maxIndex]) maxIndex = j;
        }
        temp = array[maxIndex];
        array[maxIndex] = array[size - 1 - i];
        array[size - 1 - i] = temp;
    }
}

// 冒泡排序
void bubblingSort(int array[], int size) {
    bool isSwap;
    for (int i = 0, temp; i < size; ++i) {
        isSwap = false;
        for (int j = 0; j < size - 1 - i; ++j) {
            if (array[j] > array[j + 1]) {
                isSwap = true;
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        if (!isSwap) break;
    }
}

// 插入排序
void insertSort(int array[], int size) {
    int j, insertValue;
    for (int i = 1; i < size; ++i) {
        for (insertValue = array[i], j = i - 1; j >= 0 && array[j] > insertValue; j--) {
            array[j + 1] = array[j];
        }
        array[j + 1] = insertValue;
    }
}

int main() {
    int size = 30;
    int array[size];
    generateArrayData(array, size, true);

    // 选择排序
    //selectionSort(array, size);

    // 冒泡排序
    bubblingSort(array, size);
    printArray(array, size);

    // 插入排序
    insertSort(array, size);
    printArray(array, size);

    sort(array, array + size);

    return 0;
}
