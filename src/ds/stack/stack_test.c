#include "../../ds/stack/stack_test.h"

int test_ds_stack() {
    printf("------- %s() start -------\n", __func__);
    Stack stack;
    Data* tmpData;
    initializeStack(&stack);

    if (!isStackEmpty(&stack)) {
        printf("%s() isStackEmpty err\n", __func__);
        return -1;
    }

    Data d1 = {
        .name = "hello",
        .id = 1
    };
    push(&stack, &d1);

    if (isStackEmpty(&stack)) {
        printf("%s() isStackEmpty() err\n", __func__);
        return -1;
    }

    Data d2 = {
        .name = "world",
        .id = 2
    };
    push(&stack, &d2);

    Data d3 = {
        .name = "china",
        .id = 3
    };
    push(&stack, &d3);

    displayStack(&stack, (fptrDispayData)printData);

    Data d4 = {
        .name = "us",
        .id = 4
    };
    push(&stack, &d4);

    if (getStackLen(&stack) != 4) {
        printf("%s() getStackLen() err\n", __func__);
        return -1;
    }

    displayStack(&stack, (fptrDispayData)printData);

    tmpData = peek(&stack);
    if (tmpData == NULL) {
        printf("%s() peek() err\n", __func__);
    } else {
        printf("%s() peek(), name=%s, id=%d\n\n", __func__, tmpData->name, tmpData->id);
    }

    while ((tmpData = (Data*)pop(&stack))) {
        printf("%s() pop(), name=%s, id=%d\n", __func__, tmpData->name, tmpData->id);
    }

    if (!isStackEmpty(&stack)) {
        printf("%s() isStackEmpty err\n", __func__);
    }

    printf("------- %s() end -------\n\n", __func__);
    destroyStack(&stack);
    return 0;
}
