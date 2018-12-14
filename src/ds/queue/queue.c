#include "../../ds/queue/queue.h"

int initializeQueue(Queue* q) {
    return initializeList(q);
}

// ���, ��ӵ�����β��
int enqueue(Queue* q, void* data) {
    return addTail(q, data);
}

// ����, ɾ��ͷ�����������е�����
void* dequeue(Queue* q) {
    return removeFirst(q);
}

int isQueueEmpty(const Queue* q) {
    return isListEmpty(q);
}

int getQueueLen(const Queue* q) {
    return getLinkedListCount(q);
}

int displayQueue(const Queue* q, void (*display)(const void* data)) {
    printf("%s() start\n", __func__);
    int ret = displayLinkedList(q, display);
    printf("%s() end\n\n", __func__);
    return ret;
}

int destroyQueue(Queue* q) {
    return destroyLinkedList(q);
}
