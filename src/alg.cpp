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
    //SortArr(arr[], len);
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
    //SortArr(arr[], len);
    for (int i = len-1; i >=0; --i) {
        for (int j = len - 1; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                count += 1;
            }
        }
    }
    return count;
}

int cbinsearch(int* arr, int left1, int len, int ch) {
    int count = 0;
    int left2 = left1;
    int middle = 0;
    int right = len;
    while (left2 < right-1) {
        if (arr[middle] == ch) {
            count++;
            int el = middle + 1;
            while ((arr[el] == ch) && (el < right)) {
                count += 1;
                el += 1;
            }
            el = middle - 1;
            while ((arr[el] == ch) && (el > left2)) {
                count += 1;
                el -= 1;
            }
            break;
        } else if (arr[middle] > ch) {
            right = middle;
        } else {
            left2 = middle;
        }
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    SortArr(arr, len);
    int ch;
    for (int left1 = 0; left1 < len-1; ++left1) {
        ch = value - arr[left1];
        count += cbinsearch(arr, left1, len, ch);
    }
    return count;
}
