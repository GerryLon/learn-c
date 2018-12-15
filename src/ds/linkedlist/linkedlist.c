#include "../../ds/linkedlist/linkedlist.h"

int initializeList(LinkedList* l) {
    l->head = NULL;
    l->tail = NULL;
    return 0;
}

//
int addHead(LinkedList* l, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("%s() malloc() err\n", __func__);
        return -1;
    }
    node->data = data;

    // 如果head为空
    if (l->head == NULL) {
        l->tail = node; // 尾节点也是node
        node->next = NULL;
    } else {
        node->next = l->head;
    }

    // 无论如何, head都指向node
    l->head = node;

    return 0;
}

int addTail(LinkedList* l, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        printf("%s() malloc() err\n", __func__);
        return -1;
    }
    node->data = data;
    node->next = NULL; // node作为尾节点，next是NULL

    if (l->head == NULL) {
        l->head = node;
    } else {
        l->tail->next = node;
    }

    // 无论如何, tail都指向node
    l->tail = node;
    return 0;
}

int deleteNode(LinkedList* l, Node* node) {
    if (l == NULL || l->head == NULL) {
        printf("%s() list is empty!\n", __func__);
        safeFree(node);
        return 0;
    }

    if (node == NULL) {
        return 0;
    }

    if (node == l->head) {
        if (l->head->next == NULL) { // list目前只有一个有效节点， head和tail都指向它
            l->head = l->tail = NULL;
        } else {
            l->head = l->head->next; // head移到下一个,即删除head
        }
    } else {
        Node* tmpNode = l->head;

        // 这样写,直接跳过head节点,进行比较
        while(tmpNode != NULL && tmpNode->next != node) {
            tmpNode = tmpNode->next;
        }

        // 找到了和node指向相同的节点, 也就是 tmpNode->next == node成立
        if (tmpNode != NULL) {
            tmpNode->next = node->next;
        }
    }

    // 释放被删除的节点对应的内存
    safeFree(node);
    return 0;
}

void* removeFirst(LinkedList* l) {
    if (l == NULL || l->head == NULL) {
        return NULL;
    }

    Node* tmpNode = l->head; // 保存头节点
    l->head = l->head->next; // 重置头节点
    Data* tmpData = (Data*)tmpNode->data;
    safeFree(tmpNode);
    return tmpData;
}

int getLinkedListCount(const LinkedList* l) {
    int count = 0;
    if (l == NULL || l->head == NULL) {
        return 0;
    }

    // 头节点也包含有效数据
    Node* tmpNode = l->head;

    while (tmpNode != NULL) {
        count++;
        tmpNode = tmpNode->next;
    }

    return count;
}

int isListEmpty(const LinkedList* l) {
    if (l == NULL || l->head == NULL) {
        return 1; // empty
    }
    return 0;
}

Node* getNode(LinkedList* l, int (*compare)(const void* data1, const void* data2), const void* data) {
    if (l == NULL) {
        return NULL;
    }

    Node* tmpNode = l->head;
    while (tmpNode != NULL) {
        if (compare(tmpNode->data, data) == 0) {
            return tmpNode;
        }
        tmpNode = tmpNode->next;
    }

    return NULL;
}

int displayLinkedList(const LinkedList* l, void (*display)(const void* data)) {
    printf("%s() start\n", __func__);
    if (l == NULL) {
        printf("%s() list is empty!\n", __func__);
        return NULL;
    }

    Node* tmpNode = l->head;
    while(tmpNode != NULL) {
        display(tmpNode->data);
        tmpNode = tmpNode->next;
    }
    printf("%s() end\n\n", __func__);
    return 0;
}

int destroyLinkedList(LinkedList* l) {
    if (l == NULL) {
        return 0;
    }

    Node* tmpNode;

    // 不断释放head节点
    while(l->head != NULL) {
        tmpNode = l->head;
        l->head = l->head->next;
        safeFree(tmpNode);
    }
    return 0;
}
