#define MY_MEMWATCH 1

#include "../common/common.h"
#include "../memwatch/my_memwatch.h"

int test_my_memwatch() {
    printf("%s() start\n", __func__);
    char* p = (char*)malloc(10);

    if (p == NULL) {
        return -1;
    }

    strcpy(p, "hello");
    printf("%s() p=%s\n", __func__, p);

    if (p != NULL) {
        free(p);
    }
    printf("%s() end\n\n", __func__);
    return 0;
}
