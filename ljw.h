//
// Created by Administrator on 2024/9/19.
//

#ifndef ZUOSHEN_LJW_H
#define ZUOSHEN_LJW_H

#include <bits/stdc++.h>
#include <windows.h>
#include <wincrypt.h>

using namespace std;

/*********************************** 随机数相关 **********************************/
class WinRandom {
    HCRYPTPROV handle;
public:
    WinRandom() {
        handle = NULL;
        CryptAcquireContext(
                (HCRYPTPROV *) &handle, NULL, NULL,
                PROV_RSA_FULL, 0
        );
    }

    ~WinRandom() {
        if (handle != NULL) CryptReleaseContext(handle, 0);
    }

    bool randBuf(void *dest, int len) {
        if (handle == NULL) return false;
        return CryptGenRandom(handle, len, (BYTE *) dest);
    }

#   define _(func, typ) \
    typ func() { \
        typ ret = 0; \
        assert(randBuf((void *)&ret, sizeof(ret))); \
        return ret; \
    }

    _(randInt, int)

    _(randLong, long long)

    _(randUnsigned, unsigned)

    _(randUnsignedLong, unsigned long long)

    _(randShort, short)

    _(randUnsignedShort, unsigned short)

    _(randChar, char)

    _(randUnsignedChar, unsigned char)

    _(randSignedChar, signed char)
};

WinRandom random;

/*********************************** 随机数相关 **********************************/

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
    int modV = maxV - minV + 1;
    for (int i = 0; i < size; ++i) array[i] = minV + random.randInt() % modV;
    if (print) printArray(array, size);
}

/**
 * 判断输入的整数是否为素数
 */
bool isPrime(int value) {
    if (value < 2) return false;
    if (value == 2) return true;
    if (value % 2 == 0) return false;
    for (int i = 3, temp = sqrt(value); i <= temp; i += 2) {
        if (value % i == 0) return false;
    }
    return true;
}

/**
 * 二分查找有序数组中是否存在指定的数值. 若存在(可存在多个), 返回其下标(任意数下标均可), 否则返回-1
 */
int binarySearch1(int array[], int size, int value) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (array[mid] == value) return mid;
        if (array[mid] > value) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

/**
 * 二分查找有序(升序)数组中是否存在指定的数值. 若存在, 返回该数值在数组中最右侧的下标, 否则返回-1
 */
int binarySearch2(int array[], int size, int value) {
    int left = 0, right = size - 1, mid, answer = -1;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (array[mid] == value) {
            answer = mid;
            left = mid + 1;
        } else if (array[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return answer;
}

#endif //ZUOSHEN_LJW_H
