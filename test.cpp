#include <bits/stdc++.h>

using namespace std;

bool binarySearch(int array[], int size, int value) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (array[mid] == value) return true;
        else if (array[mid] > value) right = mid - 1;
        else left = mid + 1;
    }
    return false;
}

int main() {
    int n, nums[7], result[7] = {};
    cin >> n;
    for (int i = 0; i < 7; ++i) cin >> nums[i];
    sort(nums, nums + 7);

    for (int i = 0, count, temp; i < n; ++i) {
        count = 0;
        for (int j = 0; j < 7; ++j) {
            cin >> temp;
            if (binarySearch(nums, 7, temp)) count++;
        }
        result[count - 1]++;
    }

    for (int i = 6; i >= 0; --i) cout << result[i] << " ";
    return 0;
}