#include "linkedList.h"

typedef struct stack {
	node * head;
} stackNode;

/* Preconditions: None.
Postconditions: A stack is created and initialized to empty. */
stackNode * createStack();

/* Preconditions: An initialized stack exists.
Postconditions: An initialized stack exists. */
void destroyStack(stackNode * myStack);

/* Preconditions: The stack is not full.
Postconditions: An element is added to the stack, the length is increased by one,  the top of the stack points to the newly added element. */
void push(stackNode * myStack, char *i);

/* Preconditions: The stack is not empty.
Postconditions: The first (top) element of the stack is removed and returned to the caller. The top of the stack is set to the successor of the removed element, the length of the stack is decremented by one. */
char *pop(stackNode * myStack);

/* Preconditions: The stack is not empty.
Postconditions: Returns the element that is at the top of the stack but does not remove that element from the stack. */
char *peek(stackNode * myStack);

void printStack(stackNode *myStack);
