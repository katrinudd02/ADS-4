// Copyright 2021 NNTU-CS
#include <iostream>

void SortArr(int* arr, int len) {
    int i, j;
    int temp;
    for (i = 1; i < len; i++) {
        j = i;
        temp = arr[i];
        while (j > 0 && temp < arr[j-1]) {
            arr[j] = arr[j-1];
            j--;
        }
        arr[j] = temp;
    }
}

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    //SortArr(arr, N);
    for (int i = len-1; i >=0; --i) {
        if (arr[i] <= value) {
            for (int j = len - 1; j > i; j--) {
                if (arr[i] + arr[j] == value) {
                    count += 1;
                }
            }
        }
    }
    return count;
}

int cbinsearch(int* arr, int left, int len, int value) {
    int count = 0;
    int x = left;
    int y = len;
    int middle = 0;
    while (x < y) {
        middle = x + (y - x) / 2;
        if (arr[middle] == value && middle != left) {
            count++;
            int el1 = middle;
            int el2 = middle;
            while (arr[++el1] == value) {
                count += 1;
            }
            while (arr[--el2] == value && el2 > left) {
                count += 1;
            }
            break;
        } else if (arr[middle] > value) {
            y = middle;
        } else {
            x = middle+1;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    //SortArr(arr, len);
    for (int x = 0; x < len; x++) {
        count += cbinsearch(arr, x, len, value - arr[x]);
    }
    return count;
}
