#include "../secure/secure_test.h"

static int test_printfWithTime() {
    printfWithTime("printfWithTime()\n", __func__);
    return 0;
}

int test_secure() {
    printf("%s() start\n", __func__);
    test_printfWithTime();
    printf("%s() end\n", __func__);
    return 0;
}
