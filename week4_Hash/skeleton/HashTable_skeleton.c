#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"
#include "LinkedList.h"

//1
void TBLInit(Table *ptable, int hash_size, HashFunc *f, float constant_a) {
    ptable->hash_size = hash_size;
    ptable->hf = f;
    ptable->constant_a = constant_a;
    ptable->tbl = (List **) malloc(sizeof(List *) * hash_size);

    for(int i = 0; i < hash_size; i++) {
        ptable->tbl[i] = (List *)malloc(sizeof(List));
        InitList(ptable->tbl[i]);
    }
}

// 3
void TBLInsert(Table *ptable, Key key, Value value) {
    int hashedKey = ptable->hf(key, ptable->constant_a, ptable->hash_size);

    if (FindNode(ptable->tbl[hashedKey], key) ) {
        printf("이미 존재하는 값입니다.\n");
        return;
    }

    Slot newSlot = {key, value};
    LInsert(ptable->tbl[hashedKey], newSlot);
    printf("inserted : %d in node %d\n", value, hashedKey);
}

// 4
void TBLDelete(Table *ptable, Key key) {
    int hashedKey = ptable->hf(key, ptable->constant_a, ptable->hash_size);

    if ( LDelete(ptable->tbl[hashedKey], key) ) {
        printf("delete : %d in node %d\n", key, hashedKey);
    } else {
        printf("존재하지 않는 값입니다.\n");
    }

}

// 5 
Slot TBLFind(Table *ptable, Key key) {
    Slot slot;

    int hashedKey = ptable->hf(key, ptable->constant_a, ptable->hash_size);

    if (FindNode(ptable->tbl[hashedKey], key) ) {
        slot = ptable->tbl[hashedKey]->cur->element;
        printf("found %d : node %d\n", slot.val, hashedKey);
    } else {
        printf("NULL\n");
    }

    return slot;
}

// 2
void TBLPrint(Table *ptable) {
    for (int i =0; i < ptable->hash_size; i++) {
        printf("node %d", i);
        PrintList(ptable->tbl[i]);
        printf("\n");
    }
}