#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

// 1    ->  구현 순서
void StackInit(Stack * pstack)
{
    pstack->head = NULL;
}

// 2
int SIsEmpty(Stack * pstack)
{
    if (pstack->head == NULL){
        return TRUE;
    } 
    return FALSE;
}

// 3
void SPush(Stack * pstack, Data data)
{
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = pstack->head;
    pstack->head = newNode;
}

// 4
Data SPop(Stack * pstack)
{
    if (SIsEmpty(pstack)) {
        printf("Stack is empty!\n");
        exit(-1);
    }
    Node * nodeToPop = pstack->head;
    pstack->head = pstack->head->next;
    Data dataToPop = nodeToPop->data;
    free(nodeToPop);
    return dataToPop;
}

// 5
Data SPeek(Stack * pstack)
{
    if (SIsEmpty(pstack)) {
        printf("Stack is empty!\n");
        exit(-1);
    }
    return pstack->head->data;
}

// 6
void PrintStack(Stack *pstack)
{
    Node * iter = pstack->head;
    while(iter != NULL) {
        printf("%c ", iter->data);
        iter = iter->next;
    }
    printf("\n");
}