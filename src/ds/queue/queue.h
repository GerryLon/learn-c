#ifndef _DS__QUEUE_H
#define _DS__QUEUE_H

#include "../../common/common.h"
#include "../ds.h"
#include "../linkedlist/linkedlist.h"

// 用链表来实现队列
typedef LinkedList Queue;

int initializeQueue(Queue* q);

// 入队, 添加到队列尾部
int enqueue(Queue* q, void* data);

// 出队, 删除头部并返回其中的数据
void* dequeue(Queue* q);

int isQueueEmpty(const Queue* q);
int getQueueLen(const Queue* q);

int displayQueue(const Queue* q, void (*display)(const void* data));
int destroyQueue(Queue* q);
#endif // _DS__QUEUE_H
