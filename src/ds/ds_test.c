#include "../ds/ds_test.h"

int test_ds() {
    printf("------- %s() start -------\n", __func__);
    test_ds_linkedlist();
    test_ds_queue();
    test_ds_stack();
    printf("------- %s() end -------\n", __func__);
    return 0;
}
