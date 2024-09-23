#include <bits/stdc++.h>
#include "ljw.h"

using namespace std;

// 在有序数组中查找值为value的位置, 若不存在返回-1, 若有多个返回任意一个即可
int searchValue(int array[], int size, int value) {
    int l = 0, r = size - 1, m;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (array[m] == value) return m;
        if (array[m] > value) r = m - 1;
        else l = m + 1;
    }
    return -1;
}

int main() {
//    int size = 30;
//    int array[size];
//    generateArrayData(array, size, true);
//    sort(array, array + size);
//    printArray(array, size);
//    cout << searchValue(array, size, 55);

    cout << isPrime(23);
    return 0;
}
