#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// 1   -->   구현 순서
void InitList(List *plist)
{
    plist->head = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

// 5
void LInsert(List *plist, ElementType new_element, ElementType key_element)
{
    Node * new = (Node *) malloc(sizeof(Node)); 
    new->element = new_element;
    new->next = NULL;

    if (key_element == -1) {
        new->next = plist->head;
        plist->head = new;
    }
    else if (FindNode(plist, key_element)) {
        new->next = plist->cur->next;
        plist->cur->next = new;
    }
    else {
        printf("Insertion(%d) Failed: element %d is not in the list.\n", new_element, key_element);
    }
}

// 6
void LDelete(List *plist, ElementType key_element)
{

}

void DeleteList(List *plist)
{

}

// 3
void PrintList(List *plist)
{
    if (plist->head == NULL) {
        printf("List is Empty.");
    }

    plist->cur = plist->head;
    while(plist->cur != NULL) {
        printf("key:%d\t", plist->cur->element);
        plist->cur = plist->cur->next;
    }
}

// 4
int FindNode(List *plist, ElementType key_element)
{
    plist->cur = plist->head;
    while(plist->cur != NULL) {
        if (plist->cur->element == key_element) {
            return TRUE;
        }
        plist->before = plist->cur;
        plist->cur = plist->cur->next;
    }
    return FALSE;
}

int LCount(List *plist)
{

}

// 2
int IsEmpty(List *plist)
{
    if (plist->head == NULL) {
        return TRUE;
    }
    return FALSE;
}