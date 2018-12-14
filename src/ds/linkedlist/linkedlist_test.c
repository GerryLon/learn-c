#include "../../ds/linkedlist/linkedlist_test.h"

int test_ds_linkedlist() {
    printf("------- %s() start -------\n", __func__);

    LinkedList list;
    Node* tmpNode;
    Data* tmpData;
    initializeList(&list);

    Data d1 = {
        .name = "hello",
        .id = 1
    };
    addTail(&list, &d1);

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
    addHead(&list, &d5);
    displayLinkedList(&list, (fptrDispayData)printData);

    destroyLinkedList(&list);
    printf("------- %s() end -------\n\n", __func__);
    return 0;
}
