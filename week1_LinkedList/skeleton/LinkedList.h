#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#define TRUE    1
#define FALSE   0

typedef int ElementType;

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
int FindNode(List *plist, ElementType key);
int FindPrevNode(List *plist, ElementType key);
void LInsert(List *plist, ElementType new_element, ElementType key);
void LDelete(List *plist, ElementType key);
void PrintList(List *plist);

#endif