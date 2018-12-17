#include "../secure/secure_test.h"

static int test_printfWithTime() {
    printfWithTime("printfWithTime()\n", __func__);
    return 0;
}

static void add(int size, int* restrict arr1, const int* restrict arr2) {
    int i = 0;
    for (i = 0; i < size; i++) {
        arr1[i] += arr2[i];
    }
}

static int test_restrict_add() {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {5, 6, 7, 8}; // 6, 8, 10, 12
    // int* arr2 = arr1; // 2, 4, 6, 8
    int i = 0;
    int len = sizeof(arr1) / sizeof(int);
    add(len, arr1, arr2);

    for (i = 0; i < len; i++) {
        // printf("%d\n", arr1[i]);
    }
    return 0;
}

int test_secure() {
    printf("%s() start\n", __func__);
    test_printfWithTime();
    test_restrict_add();
    printf("%s() end\n\n", __func__);
    return 0;
}
