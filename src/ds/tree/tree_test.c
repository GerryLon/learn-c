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
        printf("%s() insertNode() err, id=%d\n", __func__, d1.id);
        return ret;
    }

    Data d2 = {
        .name = "java",
        .id = 10
    };
    if ((ret = insertNode(&bstTree, compareFn, &d2)) != 0) {
        printf("%s() insertNode() err, id=%d\n", __func__, d2.id);
        return ret;
    }

    Data d3 = {
        .name = "php",
        .id = 3
    };
    if ((ret = insertNode(&bstTree, compareFn, &d3)) != 0) {
        printf("%s() insertNode() err, id=%d\n", __func__, d3.id);
        return ret;
    }

    Data d4 = {
        .name = "c",
        .id = 8
    };
    if ((ret = insertNode(&bstTree, compareFn, &d4)) != 0) {
        printf("%s() insertNode() err, id=%d\n", __func__, d4.id);
        return ret;
    }
printf("/*\n\
        5\n\
       / \\\n\
      3   10\n\
          /\n\
         8\n\
      preOrder: 5, 3, 10, 8\n\
      inOrder:  3, 5, 8, 10\n\
      postOrder:3, 8, 10, 5\n\
*/\n");

    printf("%s() preOrderTraverse() start\n", __func__);
    preOrderTraverse(bstTree, displayFn);
    printf("%s() preOrderTraverse() end\n\n", __func__);

    printf("%s() inOrderTraverse() start\n", __func__);
    inOrderTraverse(bstTree, displayFn);
    printf("%s() inOrderTraverse() end\n\n", __func__);

    printf("%s() postOrderTraverse() start\n", __func__);
    postOrderTraverse(bstTree, displayFn);
    printf("%s() postOrderTraverse() end\n\n", __func__);

    printf("------- %s() end -------\n", __func__);
    return 0;
}
