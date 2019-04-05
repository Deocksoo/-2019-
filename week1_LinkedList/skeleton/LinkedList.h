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
} LinkedList;

typedef LinkedList List;

void InitList(List *plist);
int IsEmpty(List *plist);
void LInsert(List *plist, ElementType new_element, ElementType key);
void LDelete(List *plist, ElementType key);
void PrintList(List *plist);
void PrintPreviousKeyOf(List *plist, ElementType key);

#endif