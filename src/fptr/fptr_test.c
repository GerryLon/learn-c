#include "fptr.h"
#include "fprt_test.h"

#define CASE_NUM 4

int test_calc() {
    operation op = add;

    double result = calc(op, 1, 2);
    int i = 0;
    if ((int)result != 3) {
        printf("test_calc() add() err\n");
        return -1;
    } else {
        printf("test_calc() add() ok\n");
    }

    operations ops = {add, minus, multiply, divide, NULL};

    // 测试需要的数据
    // num1 op num2 = result
    double arr[CASE_NUM][3] = {
        {1, 1, 2}, // 1+1=2
        {10, 9, 1},
        {3, 7, 21},
        {8, 4, 2},
    };

    for (i = 0; i < CASE_NUM; i++) {
        op = ops[i]; // get op on position i, like add, minus etc.
        if ((int)op(arr[i][0], arr[i][1]) != (int)arr[i][2]) {
            printf("test_calc() loop test op err, i=%d\n", i);
            return -1;
        }
    }
    printf("test_calc() loop test op ok\n");

    return 0;
}

int test_fptr() {
    test_calc();
    return 0;
}
