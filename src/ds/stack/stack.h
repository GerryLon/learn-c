#ifndef _DS__STACK_H
#define _DS__STACK_H 1

#include "../../common/common.h"
#include "../ds.h"
#include "../linkedlist/linkedlist.h"

typedef LinkedList Stack;

int initializeStack(Stack* stack);
int push(Stack* stack, void* data);
void* pop(Stack* stack); // ≥ˆ’ª£¨ ∑µªÿdata÷∏’Î
void* peek(const Stack* stack);
int isStackEmpty(const Stack* stack);
int getStackLen(const Stack* stack);
int displayStack(const Stack* stack, void(*display)(const void* data));
int destroyStack(Stack* stack);

#endif // _DS__STACK_H
