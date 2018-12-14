#include "../ds/ds_test.h"

int test_ds() {
    printf("------- %s() start -------\n", __func__);
    test_ds_linkedlist();
    printf("------- %s() end -------\n", __func__);
    return 0;
}
