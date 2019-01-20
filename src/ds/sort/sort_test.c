#include "../../common/common.h"
#include "../../ds/sort/sort.h"

int test_mergesort() {
    int tobeSorted[] = {33, 2, 5, 8, 9, 10, 77, 99};
    int expected[] = {2, 5, 8, 9, 10, 33, 77, 99};
    int i = 0;
    int len = sizeof(tobeSorted) / sizeof(int);

    assert(sizeof(tobeSorted) == sizeof(expected));

    mergesort(tobeSorted, 0, len - 1);

    for (i = 0; i < len; i++) {
        // printf("msort: %d\n", tobeSorted[i]);
        assert(tobeSorted[i] == expected[i]);
    }

    return 0;
}

int test_ds_sort() {
    test_mergesort();
    return 0;
}
