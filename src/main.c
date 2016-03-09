#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>

int main (int argc, const char * argv[]) {
	
	stackNode *myStack;
	
	char lineBuffer[100];
	FILE *inputFile = NULL;
	char *strPtr;
	int counter = 0;
	
	myStack = createStack();
	
    if (argc != 2) {
		printf ("Usage Error: please  path/to/executable path/to/input/file\n");
		exit(1);
	}
    /* open the file for reading */
	inputFile = fopen (argv[1], "r");

	if (inputFile == NULL) {
		printf ( "Error. Input file does not exist!\n");
		exit(1);
	}
	/* this code will read the lines of the file in one at a time.
	it is up to you to add in the code to make it work with your stack */
	else {
		while (fgets (lineBuffer, 10, inputFile) != NULL) {
		    counter++;
		    lineBuffer[strlen(lineBuffer)-1] = '\0';
		    if (strlen(lineBuffer) > 1) {
			    strPtr = &lineBuffer[2];
			    if (lineBuffer[0] == 'P') {
			        push(myStack, strPtr);
		        }
		    }
		    else if (strlen(lineBuffer) == 1) {
		        if (lineBuffer[0] == 'O') {
		            printf("popped: %s\n", pop(myStack));
		        }
		        else if (lineBuffer[0] == 'K') {
		             printf("peeked: %s\n", peek(myStack));
		        }
		        else if (lineBuffer[0] == '$') {
		            printf("current stack: ");
		            printStack(myStack);
		            printf("\n");
		        }
		        else {
		            printf("%s:%d error: unknown symbol '%c'.\n", argv[1], counter, lineBuffer[0]);
		        }
		    }
		    else {
		        printf("%s:%d error: unknown string.\n", argv[1], counter);
		    }
		}
		fclose(inputFile);
	}
	
	destroyStack(myStack);
	
	return 0;
}
