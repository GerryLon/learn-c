#include "common.h"
#include "common_test.h"

int test_safeFree() {
    int *pi;
    pi = (int*)malloc(sizeof(int));
    *pi = 5;

    // printf("test_safeFree(), before: *p=%p\n", pi);
    safeFree(pi);
    // printf("test_safeFree(), after: *p=%p\n", pi);
    if (pi == NULL) {
        printf("test_safeFree() #1 ok\n");
    } else {
        printf("test_safeFree() #1 err\n");
    }
    safeFree(pi);

    if (pi == NULL) {
        printf("test_safeFree() #2 ok\n");
    } else {
        printf("test_safeFree() #2 err\n");
    }
    return 0;
}

int test_getLine() {
    printf("please input \"abc\": ");
    char* line = getLine();
    printf("what you input is: %s\n", line);

    // input abc
    if (strcmp(line, "abc") != 0) {
        printf("test_getLine() err\n");
        return -1;
    } else {
        printf("test_getLine() ok\n");
    }

    safeFree(line);
    return 0;
}

int test_common() {
    printf("------- %s() start -------\n", __func__);
    test_safeFree();
    printf("------- %s() end -------\n\n", __func__);
    // test_getLine();
    return 0;
}
