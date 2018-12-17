#include "../../ds/linkedlist/linkedlist_test.h"

static void printDataIdOnly(const Data* d) {
    if (d != NULL) {
        printf("%d ", d->id);
    }
}

int test_ds_linkedlist() {
    printf("------- %s() start -------\n", __func__);

    LinkedList list;
    Node* tmpNode;
    Data* tmpData;
    initializeList(&list);

    if (!isListEmpty(&list)) {
        printf("%s() isListEmpty() err\n", __func__);
        return -1;
    }

    Data d1 = {
        .name = "hello",
        .id = 1
    };
    addTail(&list, &d1);

    if (isListEmpty(&list)) {
        printf("%s() isListEmpty() err\n", __func__);
        return -1;
    }

    Data d2 = {
        .name = "world",
        .id = 2
    };
    addTail(&list, &d2);

    Data d3 = {
        .name = "china",
        .id = 3
    };
    addTail(&list, &d3);

    displayLinkedList(&list, (fptrDispayData)printData);

    Data d4 = {
        .name = "us",
        .id = 4
    };
    addTail(&list, &d4);

    if (getLinkedListCount(&list) != 4) {
        printf("%s() getLinkedListCount() err\n", __func__);
        return -1;
    }

    displayLinkedList(&list, (fptrDispayData)printData);

    tmpNode = getNode(&list, (fptrCompareData)compareData, &d2);
    if (tmpNode == NULL) {
        printf("%s() getNode() err\n", __func__);
        return -1;
    }
    tmpData = (Data*)tmpNode->data;
    if (tmpData->id == 2) {
        printf("%s() getNode() ok\n", __func__);
    } else {
        printf("%s() getNode() err\n", __func__);
        return -1;
    }

    // ---------------------- test delete -------------------
    printf("start delete node: name=%s, id=%d\n", tmpData->name, tmpData->id);

    deleteNode(&list, tmpNode);
    printf("end delete node: name=%s, id=%d\n", tmpData->name, tmpData->id);
    displayLinkedList(&list, (fptrDispayData)printData);
    // -----------------------------------------

    Data d5 = {
        .name = "uk",
        .id = 0
    };
    printf("%s() addHead()\n", __func__);
    addHead(&list, &d5);
    // now data is 0, 1, 3, 4
    displayLinkedList(&list, (fptrDispayData)printData);

    printf("%s() before reverseLinkedList()\n", __func__);
    reverseLinkedList(&list);
    displayLinkedList(&list, (fptrDispayData)printDataIdOnly);
    printf("\n");
    printf("%s() after reverseLinkedList()\n", __func__);

    destroyLinkedList(&list);
    printf("------- %s() end -------\n\n", __func__);
    return 0;
}
