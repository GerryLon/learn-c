#include "fptr.h"
#include "fptr_test.h"

#define CASE_NUM 4

static int test_calc() {
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
    double arr[OPS_LEN][3] = {
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

    // set arr with +-*/
    // char* symbols = "+-*/";
    int symbols[] = {'+', '-', '*', '/'};

    arr[symbols[0]][0] = 1;
    arr[symbols[0]][1] = 1;
    arr[symbols[0]][2] = 2;

    arr[symbols[1]][0] = 13;
    arr[symbols[1]][1] = 4;
    arr[symbols[1]][2] = 9;

    arr[symbols[2]][0] = 13;
    arr[symbols[2]][1] = 2;
    arr[symbols[2]][2] = 26;

    arr[symbols[3]][0] = 12;
    arr[symbols[3]][1] = 3;
    arr[symbols[3]][2] = 4;

    for (i = 0; i < CASE_NUM; i++) {
        int code = symbols[i];
        if ((int)calcBySymbol(code, arr[code][0], arr[code][1]) != (int)arr[code][2]) {
            printf("test_calc() calcBySymbol() loop test op err, when %f%c%f\n",
                   arr[code][0], code, arr[code][1]);
            return -1;
        }
    }
    printf("test_calc() calcBySymbol() loop test op ok\n");

    return 0;
}

int test_fptr() {
    printf("------- %s() start -------\n", __func__);
    test_calc();
    printf("------- %s() end -------\n\n", __func__);
    return 0;
}
