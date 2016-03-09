/*********************************
Minahil Ikram       0721370
CIS*2520            Lab 5
October 08, 2012
*********************************/

#include <stdio.h>
#include "linkedList.h"
#include <stdlib.h>
#include <string.h>

/*Initalizes list*/
node * createList() {
    node * dummyNode;
    dummyNode = malloc(sizeof(node));
    dummyNode->cmd = NULL;
    
    return dummyNode;
}

/*Adds a node to the front of the list*/
void addFront(node * head, char *elem) {
    node * newNode;
    newNode = initNode(elem);
    newNode->next = head->next;
    head->next = newNode;

}


/*Gets the value stored in the node at the front of the list*/
char *getFront(node * head) {
    
    return head->next->cmd;
}

/*Removes the first node in the list*/
char *removeFront(node * head) {
    node * tempPtr = head->next;
    char *nodeCmd = malloc(strlen(tempPtr->cmd));
    strncpy(nodeCmd, tempPtr->cmd, strlen(tempPtr->cmd));
    head->next = head->next->next;
    free(tempPtr->cmd);
    free(tempPtr);
    
    return nodeCmd;
}

/*Prints the list*/
void printList(node * head) {
    node * N;
    N = head;
    N = N->next;
    while (N != NULL) {
        printf("%s ", N->cmd);
        N = N->next;
    }
}

/*Initializes a new node to add to the list*/
node * initNode(char *elem) {
    node * newNode;
    newNode = malloc(sizeof(node));
    newNode->cmd = NULL;
    newNode->cmd = malloc(sizeof(elem));
    strncpy(newNode->cmd, elem, sizeof(elem));
    newNode->next = NULL;
    return newNode;

}

/*Destroys the list*/
void destroy(node * head) {
    node * temp = head;
    while (temp != NULL) {
        temp = temp->next;
        free(head->cmd);
        free(head);
        head = temp;
    }
}
