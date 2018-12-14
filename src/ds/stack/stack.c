#include "stack.h"

int initializeStack(Stack* stack) {
    return initializeList(stack);
}
int push(Stack* stack, void* data) {
    return addHead(stack, data);
}
void* pop(Stack* stack) {
    return removeFirst(stack);
}

void* peek(const Stack* stack) {
    if (stack == NULL) {
        return NULL;
    }

    LinkedList* list = (LinkedList*)stack;
    if (list->head != NULL) {
        return list->head->data;
    }
    return NULL;
}

int isStackEmpty(const Stack* stack) {
    return isListEmpty(stack);
}

int getStackLen(const Stack* stack) {
    return getLinkedListCount(stack);
}

int displayStack(const Stack* stack, void(*display)(const void* data)) {
    printf("%s() start\n", __func__);
    int ret = displayLinkedList(stack, display);
    printf("%s() end\n\n", __func__);
    return ret;
}

int destroyStack(Stack* stack) {
    return destroyLinkedList(stack);
}
