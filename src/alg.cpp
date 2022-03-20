// Copyright 2021 NNTU-CS
#include <iostream>

void swap(int *a, int *b) {
    a = b;
    b = a;
}

void SortArr(int arr[], int len) {
    int i, j, index;
    for (i = 0; i < len - 1; i++) {
        index = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[index]) {
                index = j;
            }
        }
        swap(&arr[i], & arr[index]);
    }
}

int countPairs1(int* arr, int len, int value) {
    int count = 0;
    bool flag = false;
    SortArr(arr[], len);
    for (int i = 0; i < len-1; i++) {
        for (int j = 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                flag = true;
                count += 1;
            }
        }
    }
    if (flag == true) {
        return count;
    } else {
        return 0;
    }
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    SortArr(arr[], len);
    for (int i = 0; i < len - 1; i++) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    return count;
}

int cbinsearch(int* arr, int size, int value) {
    int count = 0;
    int left = 0;
    int right = size - 1;
    while (left < right) {
        if (arr[left] == value) {
            count++;
        }
        if (arr[right] == value) {
            count++;
        }
        left++;
        right--;
    }
    if (left == right) {
        if (arr[left] == value) {
            count++;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    //SortArr(int arr[], int len);
    for (int i = 0; i < len; i++) {
        if (arr[i] <= value - arr[i]) {
            count += cbinsearch(arr, size, value);
        }
    }
    return count;
}
