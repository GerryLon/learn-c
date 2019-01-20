#include "../../ds/sort/sort.h"

// @merge sort

static void merge(int arr[], int tmpArr[], int start, int middle, int end) {
    int i = start; // [start, middle]
    int j = middle + 1; // [middle + 1, end]
    int k = 0;

    while (i <= middle && j <= end) {
        if (arr[i] < arr[j]) {
            tmpArr[k++] = arr[i++];
        } else {
            tmpArr[k++] = arr[j++];
        }
    }

    while (i <= middle) {
        tmpArr[k++] = arr[i++];
    }

    while (j <= end) {
        tmpArr[k++] = arr[j++];
    }

    // copy tmpArr to arr
    for (i = 0; i < k; i++) {
        arr[start + i] = tmpArr[i];
    }
}

// start = 0, end = len - 1
void mergesort(int arr[], int start, int end) {
    const int len = end - start + 1;
    if (!arr || len < 2) {
        return;
    }

    int middle = (start + end) / 2;
    int tmpArr[len];

    mergesort(arr, start, middle);
    mergesort(arr, middle + 1, end);
    merge(arr, tmpArr, start, middle, end);
}

// @@merge sort

