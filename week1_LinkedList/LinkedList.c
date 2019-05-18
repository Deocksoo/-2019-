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
void LInsert(List *plist, ElementType new_element, ElementType key)
{
    Node * new = (Node *) malloc(sizeof(Node)); 
    new->element = new_element;
    new->next = NULL;

    if (key == -1) {
        new->next = plist->head;
        plist->head = new;
    }
    else if (FindNode(plist, key)) {
        new->next = plist->cur->next;
        plist->cur->next = new;
    }
    else {
        printf("Insertion(%d) Failed: element %d is not in the list.\n", new_element, key);
    }
}

// 6
void LDelete(List *plist, ElementType key)
{
    if (FindNode(plist, key)) {
        if (plist->cur == plist->head) {
            plist->head = plist->cur->next;
            free(plist->cur);
        }
        else {
            plist->before->next = plist->cur->next;
            free(plist->cur);
        }
    }
    else {
        printf("Deletion failed : element %d is not in the list.\n", key);
    }
}

// 9
void DeleteList(List *plist)
{
    if (plist->head == NULL) {
        printf("There is no data in the list.");
    }
    else {
        plist->cur = plist->head->next;
        plist->before = plist->head;

        do {
            free(plist->before);
            plist->head = NULL;
            plist->before = plist->cur;
            plist->cur = plist->cur->next;
        } while(plist->cur != NULL);
    }
}

// 3
void PrintList(List *plist)
{
    if (plist->head == NULL) {
        printf("List is Empty.\n");
    }

    plist->cur = plist->head;
    while (plist->cur != NULL) {
        printf("key:%d\t", plist->cur->element);
        plist->cur = plist->cur->next;
    }
    printf("\n");
}

// 4
int FindNode(List *plist, ElementType key)
{
    plist->cur = plist->head;
    plist->before = plist->head;

    while (plist->cur != NULL) {
        if (plist->cur->element == key) {
            return TRUE;
        }
        plist->before = plist->cur;
        plist->cur = plist->cur->next;
    }
    return FALSE;
}

// 7
int FindPrevNode(List *plist, ElementType key)
{
    if (FindNode(plist, key)) {
        if (plist->cur == plist->head) {
            printf("%d is header Node.\n");
            plist->cur = plist->head;
        }
        else {
            printf("Key of the previous node of %d is %d\n", plist->cur->element, plist->before->element);
            plist->cur = plist->before;
        }
        return TRUE;
    }
    else {
        printf("Could not find %d in the list\n", key);
        return FALSE;
    }
}

// 8
int LCount(List *plist)
{
    return plist->numOfData;
}

// 2
int IsEmpty(List *plist)
{
    if (plist->head == NULL) {
        return TRUE;
    }
    return FALSE;
}