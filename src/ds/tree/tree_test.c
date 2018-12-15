#include "../../ds/tree/tree_test.h"

int test_ds_tree() {
    printf("------- %s() start -------\n", __func__);

    TreeNode* bstTree = NULL;
    fptrCompareData compareFn = (fptrCompareData)compareData;
    fptrDispayData displayFn = (fptrDispayData)printData;
    int ret;

    Data d1 = {
        .name = "hello",
        .id = 5
    };
    if ((ret = insertNode(&bstTree, compareFn, &d1)) != 0) {
        return ret;
    }

    Data d2 = {
        .name = "java",
        .id = 2
    };
    if ((ret = insertNode(&bstTree, compareFn, &d2)) != 0) {
        return ret;
    }

    Data d3 = {
        .name = "php",
        .id = 3
    };
    if ((ret = insertNode(&bstTree, compareFn, &d3)) != 0) {
        return ret;
    }

    Data d4 = {
        .name = "c",
        .id = 8
    };
    if ((ret = insertNode(&bstTree, compareFn, &d4)) != 0) {
        return ret;
    }

    printf("%s() preOrderTraverse() start\n", __func__);
    preOrderTraverse(bstTree, displayFn);
    printf("%s() preOrderTraverse() end\n", __func__);

    printf("------- %s() end -------\n", __func__);
    return 0;
}
