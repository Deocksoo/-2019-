#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "Slot.h"

#define TRUE    1
#define FALSE   0

typedef Slot ElementType;

typedef struct _node
{
    ElementType element;
    struct _node *next;
} Node;

typedef struct _linkedList
{
    Node *head;
    Node *cur;
    Node *before;
    int numOfData;
} LinkedList;

typedef LinkedList List;

void InitList(List *plist);
int IsEmpty(List *plist);
int FindNode(List *plist, Key key);
int LInsert(List *plist, ElementType new_element);
int LDelete(List *plist, Key key);
void PrintList(List *plist);

#endif