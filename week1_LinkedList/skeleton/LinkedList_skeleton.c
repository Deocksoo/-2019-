#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

Node* FindNode(List *plist, ElementType key_element);
Node* FindPrevNode(List *plist, ElementType key);

void InitList(List *plist) {
    plist->head = NULL;
}

void LInsert(List *plist, ElementType new_element, ElementType key) {
    if (FindNode(plist, new_element) != NULL){
        printf("Insertion(%d) Failed : already exists in the list\n", new_element );
        return;
    }
    
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->element = new_element;
    
    if (key == -1 ){
        newNode->next = plist->head;
        plist->head = newNode;
        return;
    }

    Node *keyNode = FindNode(plist, key);
    if ( keyNode == NULL){
        printf("Insertion(%d) Failed : element %d is not in the list\n", new_element, key );
        free(newNode);
        return;
    }
    
    newNode->next = keyNode->next;
    keyNode->next = newNode;

}

void LDelete(List *plist, ElementType key) {
    if ( plist->head->element == key ){
        Node * tmpNode = plist->head;
        plist->head = plist->head->next;
        free(tmpNode);
        return;
    }

    Node * prevNode = FindPrevNode(plist, key);
    if ( prevNode == NULL ) {
        printf("Deletion failed : element %d is not in the list\n", key);
        return;
    }

    Node * tmpNode = prevNode->next;
    prevNode->next = prevNode->next->next;
    free(tmpNode);
}

void PrintList(List *plist) {
    if ( plist->head == NULL ){
        printf("List is empty.\n");
        return;
    }

    Node *curNode = plist->head;
    while(curNode != NULL){
        printf("key : %d\t", curNode->element);
        curNode = curNode->next;
    }
    printf("\n");
}

Node* FindNode(List *plist, ElementType key_element) {
    // key값을 element로 하는 node를 찾는다
    // 해당하는 node가 없으면 NULL을 return하도록 한다.
    Node *curNode = plist->head;
    while(curNode != NULL){
        if ( curNode-> element == key_element) {
            return curNode;
        }
        curNode = curNode->next;
    }
    return curNode;
}

Node* FindPrevNode(List *plist, ElementType key) {
    // key값을 element로 하는 node의 previous node를 찾는다.
    // 해당하는 key가 없으면 NULL을 return하도록 한다.
    
    if (plist->head->element == key){
        return NULL;
    }

    Node * curNode = plist->head;
    while(curNode->next != NULL){
        if ( curNode->next->element == key){
            return curNode;
        }
        curNode = curNode->next;
    }
    return NULL;
}

void PrintPreviousKeyOf(List *plist, ElementType key) {
    // key값을 element로 하는 node의 previous node element값을 출력한다.
    // key값이 list에 없으면 에러 메시지를 출력한다.
    Node * prevNode = FindPrevNode(plist, key);
    if ( plist->head->element == key ){
        printf("key of the previous node of %d is header\n", key);
        return;
    }
    
    if ( prevNode == NULL ){
        printf("Could not find %d in the list\n", key);
        return;
    }
    
    printf("key of the previous node of %d is %d \n", key, prevNode->element);
}

int IsEmpty(List *plist) {
    // list가 비어있으면 TRUE를, 비어있지 않으면 FALSE을 return 한다.
    if (plist-> head == NULL ) {
        return TRUE;
    }
    return FALSE;
}