#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

// 1
void InitList(List *plist)
{

}

// 6
void LInsert(List *plist, ElementType new_element, ElementType key)
{

}

// 7
void LDelete(List *plist, ElementType key)
{

}

// 3
void PrintList(List *plist)
{

}

// 4
int FindNode(List *plist, ElementType key_element)
{
    // key값을 element로 하는 node를 찾는다
    // 해당 node가 존재하면 plist->cur 포인터가 찾은 node를 가리키도록 하고, 1을 return 한다.
    // 해당 node가 존재하지 않으면, 0을 return한다.
    return 0;
}

// 5
int FindPrevNode(List *plist, ElementType key)
{
    // key값을 element로 하는 node의 앞의 node를 찾는다.
    return 0;
}

// 2
int IsEmpty(List *plist)
{
    // list가 비어있으면 1을, 비어있지 않으면 0을 return 한다.
    return 0;
}