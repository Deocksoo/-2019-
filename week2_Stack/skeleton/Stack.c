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
    return pstack->head == NULL;
}

// 3
void SPush(Stack * pstack, Data data)
{
    Node * new = (Node *) malloc(sizeof(Node));
    new->data = data;
    new->next = pstack->head;
    pstack->head = new;
}

// 4
Data SPop(Stack * pstack)
{
    if(SIsEmpty(pstack)){
        printf("야 이노마 비어있어");
        exit(1);
    }

    Data dataTmp;
    Node * nodeTmp;

    nodeTmp = pstack->head;
    pstack->head = pstack->head->next;
    
    dataTmp = nodeTmp->data;
    free(nodeTmp);

    return dataTmp;
}

// 5
Data SPeek(Stack * pstack)
{
    if(SIsEmpty(pstack)){
        printf("야 이노마 비어있어");
        exit(1);
    }

    return pstack->head->data;
}

// 6
void PrintStack(Stack *pstack)
{
    Node * tmp;
    tmp = pstack->head;
    while(1) {
        if (tmp == NULL) break;
        printf("%c\n", tmp->data);
        tmp = tmp->next;
    }
}