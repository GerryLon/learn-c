#include "common.h"
#include "common_test.h"

static int test_safeFree() {
    int *pi;
    pi = (int*)malloc(sizeof(int));
    *pi = 5;

    // printf("test_safeFree(), before: *p=%p\n", pi);
    safeFree(pi);
    // printf("test_safeFree(), after: *p=%p\n", pi);
//    if (pi == NULL) {
//        printf("test_safeFree() #1 ok\n");
//    } else {
//        printf("test_safeFree() #1 err\n");
//    }
    assert(pi == NULL);
    safeFree(pi);

//    if (pi == NULL) {
//        printf("test_safeFree() #2 ok\n");
//    } else {
//        printf("test_safeFree() #2 err\n");
//    }
    safeFree(pi);
    return 0;
}

// skip means just skip test
static int test_getLine(int skip) {
    if (skip) {
        return 0;
    }
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

static int test_getTimeLocal() {
    char buf[32];
    getTimeLocal(buf);
    printf("%s(), now is: %s\n", __func__, buf);
    return 0;
}

int test_common() {
    printf("------- %s() start -------\n", __func__);
    test_safeFree();
    test_getTimeLocal();
    printf("------- %s() end -------\n\n", __func__);
    test_getLine(1);
    return 0;
}
