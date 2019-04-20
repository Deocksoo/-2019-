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
    if (pstack->head == NULL) return TRUE;
    return FALSE;
}

// 3
void SPush(Stack * pstack, Data data)
{
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = data;
    new->next = pstack->head;
    pstack->head = new;
}

// 4
Data SPop(Stack * pstack)
{
    if (SIsEmpty(pstack)) {
        printf("stack is empty.");
        exit(-1);
    }
    Data poped_data = pstack->head->data;
    Node *poped_node = pstack->head;
    pstack->head = pstack->head->next;
    free(poped_node);
    return poped_data;
}

// 5
Data SPeek(Stack * pstack)
{
    if (SIsEmpty(pstack)) {
        printf("stack is empty.");
        exit(-1);
    }
    return pstack->head->data;
}

// 6
void PrintStack(Stack *pstack)
{
    Node *temp = pstack->head;
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}