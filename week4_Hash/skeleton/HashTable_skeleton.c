#include <stdio.h>
#include <stdlib.h>

#include "HashTable.h"
#include "LinkedList.h"

//1
void TBLInit(Table *ptable, int hash_size, HashFunc *f, float constant_a) {
    ptable->hash_size = hash_size;
    ptable->hf = f;
    ptable->constant_a = constant_a;
    
    ptable->tbl = (List *) malloc(sizeof(List) * hash_size);

    for (int i = 0; i < hash_size; i++) {
        InitList(&(ptable->tbl[i]));
    }
}

// 3
void TBLInsert(Table *ptable, Key key, Value value) {
    int hashed_key = ptable->hf(key, ptable->constant_a, ptable->hash_size);
    Slot slot;
    slot.key = key;
    slot.val = value;
    if (LInsert(&ptable->tbl[hashed_key], slot)) {
        printf("inserted : %d in Node %d\n", value, hashed_key);
    }
}

// 4
void TBLDelete(Table *ptable, Key key) {
    int hashed_key = ptable->hf(key, ptable->constant_a, ptable->hash_size);
    if (LDelete(&ptable->tbl[hashed_key], key)) {
        printf("deleted : %d in Node %d\n", key, hashed_key);
    }
}

// 5 
Slot TBLFind(Table *ptable, Key key) {
    Slot slot;
    int hashed_key = ptable->hf(key, ptable->constant_a, ptable->hash_size);
    if (FindNode(&ptable->tbl[hashed_key], key)) {
        printf("found %d : %d\n", key, hashed_key);
    } else {
        printf("data doesn't exist.\n");
    }

    return slot;
}

// 2
void TBLPrint(Table *ptable) {
    for (int i = 0; i < ptable->hash_size; i++) {
        printf("Node[%d] ", i);
        PrintList(&ptable->tbl[i]);
        printf("\n");
    }
}