#ifndef _DS__LINKEDLIST_H
#define _DS__LINKEDLIST_H 1
#include "../../common/common.h"
#include "../ds.h"

// ��������

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
void* removeFirst(LinkedList* l); // ɾ����һ���ڵ㣬 �������е�����
int getLinkedListCount(const LinkedList* l); // ��ȡ������Ч�ڵ㣨����ʵ�����ݽڵ㣩�ĸ���
int isListEmpty(const LinkedList* l); // ������Ч�ڵ��Ƿ�Ϊ0��

// ��l��Ѱ�Һ�������data�Ľڵ㣬 �Ƿ������compare���� Ϊ0����ȣ� ���򲻵�
Node* getNode(LinkedList* l, int (*compare)(const void* data1, const void* data2), const void* data);

// ����������� ��display����������
int displayLinkedList(const LinkedList* l, void (*display)(const void* data));
int destroyLinkedList(LinkedList* l);

// �����������
#endif // _DS__LINKEDLIST_H
