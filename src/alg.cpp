// Copyright 2021 NNTU-CS
#include <iostream>

void SortArr(int arr[], int len) {
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
    //SortArr(arr, len);
    int ch;
    for (int left1 = 0; left1 < len-1; ++left1) {
        ch = value - arr[left1];
        count += cbinsearch(arr, left1, len, ch);
    }
    return count;
}
