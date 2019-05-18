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
int LInsert(List *plist, ElementType new_element)
{
    plist->cur = plist->head;
    plist->before = plist->head;
    Node * new = (Node *) malloc(sizeof(Node)); 
    new->element = new_element;
    new->next = NULL;

    if (plist->head == NULL) {
        plist->head = new;
        return TRUE;
    }

    while (plist->cur != NULL) {
        if (plist->cur->element.key == new_element.key) {
            printf("Data is already exists.\n");
            return FALSE;
        }
        plist->before =plist->cur;
        plist->cur = plist->cur->next;
    }
    plist->before->next = new;
    return TRUE;
}

// 6
int LDelete(List *plist, Key key)
{
    if (FindNode(plist, key)) {
        if (plist->cur == plist->head) {
            plist->head = plist->cur->next;
            free(plist->cur);
            return TRUE;
        }
        else {
            plist->before->next = plist->cur->next;
            free(plist->cur);
            return TRUE;
        }
    }
    return FALSE;
}

// 3
void PrintList(List *plist)
{
    if (plist->head == NULL) {
        return;
    }

    plist->cur = plist->head;
    while (plist->cur != NULL) {
        printf("-> %d ", plist->cur->element);
        plist->cur = plist->cur->next;
    }
}

// 4
int FindNode(List *plist, Key key)
{
    plist->cur = plist->head;
    plist->before = plist->head;

    while (plist->cur != NULL) {
        if (plist->cur->element.key == key) {
            return TRUE;
        }
        plist->before = plist->cur;
        plist->cur = plist->cur->next;
    }
    return FALSE;
}

// 2
int IsEmpty(List *plist)
{
    if (plist->head == NULL) {
        return TRUE;
    }
    return FALSE;
}