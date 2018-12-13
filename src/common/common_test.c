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

int test_common() {
    test_safeFree();
    return 0;
}
