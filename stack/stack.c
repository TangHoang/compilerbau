#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void elemInit(StackElem *elem, int value) {
    elem->value = value;
    elem->next = NULL;
    elem->prev = NULL;
}

int stackInit(IntStack *self) {
    self->first = NULL;
    return 0;
}

void stackPush(IntStack *self, int i) {
    // init new element that gets pushed
    StackElem *elem = (StackElem*) malloc(sizeof(StackElem));
    elemInit(elem, i);

    if(self->first == NULL) {
        self->first = elem;
    } else{
        elem->next = self->first;
        elem->prev = self->first->prev;
        self->first = elem;
    }
}

int stackPop(IntStack *self) {
    if(stackIsEmpty(self)) {
        fprintf(stderr, "Stack is empty, cannot pop!\n");
        return 0;
    }
    StackElem *targetElem = self->first;
    int targetValue = targetElem->value;

    if(targetElem->next == NULL) {
        self->first = NULL;
    }else {
        self->first = targetElem->next;
        self->first->prev = NULL;
    }
  
    free(targetElem);
    return targetValue;
}

void stackRelease(IntStack *self) {
    while(!stackIsEmpty(self)) {
        stackPop(self);
    }
}

int stackTop(const IntStack *self) {
    if(stackIsEmpty(self)){
        fprintf(stderr, "Stack is empty!\n");
        return 0;
    }
    return self->first->value;
}

int stackIsEmpty(const IntStack *self) {
    return self->first == NULL;
}





