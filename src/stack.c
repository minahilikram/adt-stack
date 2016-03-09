#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

stackNode * createStack() {

    stackNode * myStack;
    myStack = malloc(sizeof(stackNode));
    myStack->head = createList();
    
    return myStack;
}

void destroyStack(stackNode * myStack) {

    destroy(myStack->head);
    free(myStack);

}

void push(stackNode * myStack, char *elem) {

    addFront(myStack->head, elem);

}

char *pop(stackNode * myStack) {

    char *i;
    i = removeFront(myStack->head);

    return i;
}

char *peek(stackNode * myStack) {
    
    char *i;
    i = getFront(myStack->head);

    return i;
}

void printStack(stackNode *myStack){
    printList(myStack->head);
}
