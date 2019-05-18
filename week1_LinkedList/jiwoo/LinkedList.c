#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void InitList(List *plist) {
    plist->head = NULL;
}

Node *FindNode(List *plist, ElementType key) {
    Node *cur = plist->head;
    while(cur){
        if (cur->element == key) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

Node* FindPrevNode(List *plist, ElementType key) {
    Node *cur = plist->head;
    if (IsEmpty(plist)) {
        return NULL;
    }
    
    if (plist->head->element == key) {
        return NULL;
    }

    while (cur->next) {
        if (cur->next->element == key) {
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}

void LInsert(List *plist, ElementType new_element, ElementType key) {
    Node *new = (Node *)malloc(sizeof(Node));
    Node *found;
    new->element = new_element;
    new->next = NULL;

    if (FindNode(plist, new_element)) {
        printf("element is already in the list\n");
        return;
    }

    if (key == -1) {
        if (IsEmpty(plist)) {
            plist->head = new;
        }
        else {
            new->next = plist->head;
            plist->head = new;            
        }
    }
    else {
        if (!FindNode(plist, key)) {
        printf("key is not in the list\n");
        return;
        }
        if (FindNode(plist, key)) {
            found = FindNode(plist, key);
            new->next = found->next;
            found->next = new;
        }
    }
}

void LDelete(List *plist, ElementType key) {
    Node *temp;
    Node *prev;
    
    if (IsEmpty(plist)) {
        printf("list is empty\n");
        return;
    }
    if (key == -1) {
        printf("header can't be deleted\n");
        return;
    }
    if (plist->head->element == key) {
        temp = plist->head;
        plist->head = temp->next;
        free(temp);
        return;
    }
    if (FindNode(plist, key)) {
        temp = FindNode(plist, key);
        prev = FindPrevNode(plist, key);
        prev->next = temp->next;
        free(temp);
        return;
    }
    printf("key is not in the list\n");
}

void PrintList(List *plist) {
    Node *cur;

    if (IsEmpty(plist)) {
        printf("List is empty\n");
        return;
    }
    
    cur = plist->head;
    while(cur) {
        printf("key: %d\t", cur->element);
        cur = cur->next;
    }
    printf("\n");
}

void PrintPreviousKeyOf(List *plist, ElementType key) {
    FindPrevNode(plist, key);
}

int IsEmpty(List *plist) {
    if (plist->head == NULL) {
        return TRUE;
    }
    return FALSE;
}