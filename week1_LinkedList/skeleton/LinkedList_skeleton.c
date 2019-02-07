#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// 1
void InitList(List *plist)
{

}

// 5
void LInsert(List *plist, ElementType new_element, ElementType key_element)
{
    // Insert 함수
    // key 값과 new element 값을 받아 온다
    // key값의 뒤에 new element를 data로 하는 node를 하나 Insert 한다!
    // 만약 key값을 찾지 못하면 error 메시지를 띄운다.

}

// 6
void LDelete(List *plist, ElementType key_element)
{
    // Delete 함수
    // key값을 넘겨받는다
    // key값을 가진 node를 지운다.
    // 만약 key값을 가진 node가 없으면 error 메시지를 띄운다.

}

// 7
void DeleteList(List *plist)
{
    // list의 모든 node들을 지우고, list를 초기화한다.
}

// 3
void PrintList(List *plist)
{
    // list의 모든 node들의 element를 앞에서부터 하나씩 출력한다.
}

// 4
int FindNode(List *plist, ElementType key_element)
{
    // key값을 element로 하는 node를 찾는다
    // 해당 node가 존재하면 plist->cur 포인터가 찾은 node를 가리키도록 하고, 1을 return 한다.
    // 해당 node가 존재하지 않으면, 0을 return한다.
}

int LCount(List *plist)
{
    // list에 저장된 node의 갯수를 return해준다.
}

// 2
int IsEmpty(List *plist)
{
    // list가 비어있으면 1을, 비어있지 않으면 0을 출력해준다.
}