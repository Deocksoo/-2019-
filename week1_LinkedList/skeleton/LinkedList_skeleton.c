#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void InitList(List *plist) {

}

void LInsert(List *plist, ElementType new_element, ElementType key) {

}

void LDelete(List *plist, ElementType key) {

}

void PrintList(List *plist) {

}

Node* FindNode(List *plist, ElementType key_element) {
    // key값을 element로 하는 node를 찾는다
    // 해당하는 node가 없으면 NULL을 return하도록 한다.
    return 0;
}

Node* FindPrevNode(List *plist, ElementType key) {
    // key값을 element로 하는 node의 previous node를 찾는다.
    // 해당하는 key가 없으면 NULL을 return하도록 한다.
    return 0;
}

void PrintPreviousKeyOf(List *plist, ElementType key) {
    // key값을 element로 하는 node의 previous node element값을 출력한다.
    // key값이 list에 없으면 에러 메시지를 출력한다.
}

int IsEmpty(List *plist) {
    // list가 비어있으면 TRUE를, 비어있지 않으면 FALSE을 return 한다.
    return 0;
}