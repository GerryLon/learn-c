#ifndef _DS__LINKEDLIST_H
#define _DS__LINKEDLIST_H 1
#include "../../common/common.h"
#include "../ds.h"

// 单链表定义

typedef struct _node {
    void* data;
    struct _node* next;
} Node;

typedef struct _linkedlist {
    Node* head;
    Node* tail;
    Node* curr;
} LinkedList;

int initializeList(LinkedList* l);
int addHead(LinkedList* l, void* data);
int addTail(LinkedList* l, void* data);
int deleteNode(LinkedList* l, Node* pNode);

// 在l中寻找含有数据data的节点， 是否相等由compare计算 为0则相等， 否则不等
Node* getNode(LinkedList* l, int (*compare)(const void* data1, const void* data2), const void* data);

// 输出整个链表， 由display决定如何输出
int displayLinkedList(const LinkedList* l, void (*display)(const void* data));
int destroyLinkedList(LinkedList* l);

// 单链表定义结束
#endif // _DS__LINKEDLIST_H
