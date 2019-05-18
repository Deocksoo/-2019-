#ifndef __HASH_TABLE__
#define __HASH_TABLE__

#include "LinkedList.h"
#include "Slot.h"

typedef int HashFunc(Key key, float constant_a, int m);

typedef struct _table
{
    int hash_size;
    List *tbl;
    HashFunc *hf;
    float constant_a;
} Table;

void TBLInit(Table *ptable, int hash_size, HashFunc *f, float constant_a);
void TBLInsert(Table *ptable, Key key, Value value);
void TBLDelete(Table *ptable, Key key);
Slot TBLFind(Table *ptable, Key key);
void TBLPrint(Table *ptable);

#endif