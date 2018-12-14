#ifndef _DS_H
#define _DS_H 1

#include "../common/common.h"
#include "linkedlist/linkedlist_test.h"

typedef void (*fptrDispayData)(const void* data);
typedef int (*fptrCompareData)(const void* d1, const void* d2);

// struct for test
typedef struct _data {
    char name[32];
    int id;
} Data;

// compare data
int compareData(const Data* d1, const Data* d2);

void printData(const Data* d);
#endif // _DS_H
