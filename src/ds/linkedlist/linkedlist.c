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

    // ���headΪ��
    if (l->head == NULL) {
        l->tail = node; // β�ڵ�Ҳ��node
        node->next = NULL;
    } else {
        node->next = l->head;
    }

    // �������, head��ָ��node
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
    node->next = NULL; // node��Ϊβ�ڵ㣬next��NULL

    if (l->head == NULL) {
        l->head = node;
    } else {
        l->tail->next = node;
    }

    // �������, tail��ָ��node
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
        if (l->head->next == NULL) { // listĿǰֻ��һ����Ч�ڵ㣬 head��tail��ָ����
            l->head = l->tail = NULL;
        } else {
            l->head = l->head->next; // head�Ƶ���һ��,��ɾ��head
        }
    } else {
        Node* tmpNode = l->head;

        // ����д,ֱ������head�ڵ�,���бȽ�
        while(tmpNode != NULL && tmpNode->next != node) {
            tmpNode = tmpNode->next;
        }

        // �ҵ��˺�nodeָ����ͬ�Ľڵ�, Ҳ���� tmpNode->next == node����
        if (tmpNode != NULL) {
            tmpNode->next = node->next;
        }
    }

    // �ͷű�ɾ���Ľڵ��Ӧ���ڴ�
    safeFree(node);
    return 0;
}

void* removeFirst(LinkedList* l) {
    if (l == NULL || l->head == NULL) {
        return NULL;
    }

    Node* tmpNode = l->head; // ����ͷ�ڵ�
    l->head = l->head->next; // ����ͷ�ڵ�
    Data* tmpData = (Data*)tmpNode->data;
    safeFree(tmpNode);
    return tmpData;
}

int getLinkedListCount(const LinkedList* l) {
    int count = 0;
    if (l == NULL || l->head == NULL) {
        return 0;
    }

    // ͷ�ڵ�Ҳ������Ч����
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

    // �����ͷ�head�ڵ�
    while(l->head != NULL) {
        tmpNode = l->head;
        l->head = l->head->next;
        safeFree(tmpNode);
    }
    return 0;
}
