#include "../../ds/queue/queue_test.h"

int test_ds_queue() {
    printf("------- %s() start -------\n", __func__);

    Queue queue;
    Data* tmpData;
    initializeQueue(&queue);

    if (!isQueueEmpty(&queue)) {
        printf("%s() isQueueEmpty() err\n", __func__);
        return -1;
    }

    Data d1 = {
        .name = "hello",
        .id = 1
    };
    enqueue(&queue, &d1);

    if (isQueueEmpty(&queue)) {
        printf("%s() isQueueEmpty() err\n", __func__);
        return -1;
    }

    Data d2 = {
        .name = "world",
        .id = 2
    };
    enqueue(&queue, &d2);

    Data d3 = {
        .name = "china",
        .id = 3
    };
    enqueue(&queue, &d3);

    displayQueue(&queue, (fptrDispayData)printData);

    Data d4 = {
        .name = "us",
        .id = 4
    };
    enqueue(&queue, &d4);

    if (getQueueLen(&queue) != 4) {
        printf("%s() getQueueLen() err\n", __func__);
        return -1;
    }

    displayQueue(&queue, (fptrDispayData)printData);

    while ((tmpData = (Data*)dequeue(&queue))) {
        printf("%s() dequeue, name=%s, id=%d\n", __func__, tmpData->name, tmpData->id);
    }

    if (!isQueueEmpty(&queue)) {
        printf("%s() isQueueEmpty err\n", __func__);
    }

    printf("------- %s() end -------\n\n", __func__);

    destroyQueue(&queue);
    return 0;
}
