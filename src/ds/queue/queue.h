#ifndef _DS__QUEUE_H
#define _DS__QUEUE_H

#include "../../common/common.h"
#include "../ds.h"
#include "../linkedlist/linkedlist.h"

// ��������ʵ�ֶ���
typedef LinkedList Queue;

int initializeQueue(Queue* q);

// ���, ��ӵ�����β��
int enqueue(Queue* q, void* data);

// ����, ɾ��ͷ�����������е�����
void* dequeue(Queue* q);

int isQueueEmpty(const Queue* q);
int getQueueLen(const Queue* q);

int displayQueue(const Queue* q, void (*display)(const void* data));
int destroyQueue(Queue* q);
#endif // _DS__QUEUE_H
