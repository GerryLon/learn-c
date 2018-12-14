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
    addHead(&list, &d1);

    Data d2 = {
        .name = "world",
        .id = 2
    };
    addHead(&list, &d2);

    Data d3 = {
        .name = "china",
        .id = 3
    };
    addHead(&list, &d3);

    displayLinkedList(&list, (fprtDispayData)printData);

    Data d4 = {
        .name = "us",
        .id = 4
    };
    addHead(&list, &d4);
    displayLinkedList(&list, (fprtDispayData)printData);

    tmpNode = getNode(&list, (fprtCompareData)compareData, &d2);
    if (tmpNode == NULL) {
        printf("%s() getNode() err\n", __func__);
        return -1;
    }
    tmpData = (Data*)tmpNode->data;

    // ---------------------- test delete -------------------
    printf("start delete node: name=%s, id=%d\n", tmpData->name, tmpData->id);

    deleteNode(&list, tmpNode);
    printf("end delete node: name=%s, id=%d\n", tmpData->name, tmpData->id);
    displayLinkedList(&list, (fprtDispayData)printData);
    // -----------------------------------------

    destroyLinkedList(&list);
    printf("------- %s() end -------\n\n", __func__);
    return 0;
}
