#include "../../ds/linkedlist/linkedlist.h"

int initializeList(LinkedList* l) {
    Node* node = calloc(1, sizeof(Node));
    l->tail = node;
    l->tail->next = NULL;

    node = calloc(1, sizeof(Node));
    l->head = node;
    l->head->next = l->tail;

    l->length = 0;
    return 0;
}

//
int addHead(LinkedList* l, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    assert(node != NULL);
    node->data = data;

    node->next = l->head->next;
    l->head->next = node;
    l->length++;
    return 0;
}

int addTail(LinkedList* l, void* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    assert(node != NULL);

    node->data = data;
    node->next = l->tail; // node��Ϊβ�ڵ㣬next��l->tail

    // prior of tail
    Node* tmp = getNodeByIndex(l, getLinkedListCount(l) - 1);
    if (tmp != NULL) {
        tmp->next = node;
    } else { // list empty
        l->head->next = node;
    }
    l->length++;
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
    assert(l != NULL);

    if (isListEmpty(l)) {
        return NULL;
    }

    Node* first = l->head->next;
    Data* tmpData = (Data*)first->data;

    l->head->next = first->next;
    l->length--;
    safeFree(first);
    return tmpData;
}

int reverseLinkedList(LinkedList* list) {
    Node* curr = list->head->next;
    Node* prev = list->head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next; // ���浱ǰ��nextֵ
        curr->next = prev; // ��ǰnextָ��ǰһ��, ����ת

        prev = curr;
        curr = next;
    }

    list->tail = list->head;
    list->tail->next = NULL;

    list->head = prev;

    return 0;
}

int getLinkedListCount(const LinkedList* l) {
    return l->length;
}

int isListEmpty(const LinkedList* l) {
    return getLinkedListCount(l) == 0 ? 1 : 0;
}

Node* getNode(LinkedList* l, int (*compare)(const void* data1, const void* data2), const void* data) {
    if (l == NULL) {
        return NULL;
    }

    Node* tmpNode = l->head->next;
    while (tmpNode != l->tail) {
        if (compare(tmpNode->data, data) == 0) {
            return tmpNode;
        }
        tmpNode = tmpNode->next;
    }

    return NULL;
}

Node* getNodeByIndex(const LinkedList* const list, int index) {
    int len = getLinkedListCount(list);
    if (index < 0 || index >= len) {
        return NULL;
    }
    int i;
    Node* tmp;
    for (i = 0, tmp = list->head->next; i < index; tmp = tmp->next, i++) {
        ;
    }

    return tmp;
}

int displayLinkedList(const LinkedList* l, void (*display)(const void* data)) {
    printf("%s() start\n", __func__);
    assert(l != NULL);

    Node* tmpNode = l->head->next;
    while(tmpNode != l->tail) {
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
