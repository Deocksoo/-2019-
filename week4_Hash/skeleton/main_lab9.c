#include <stdio.h>
#include "HashTable.h"

#define MAX_BUFFER_SIZE 10

int hashFunc(Value value, float constant_a, int m) {
    return (int) (m * ((value * constant_a) - (int) (value * constant_a)));
}

void ExecuteHashingOp(Table *ptable, char *buffer)
{
    char command = buffer[0];
    int table_size;
    float constant_a = 0;
    int data;

    switch (command){
        case 'n':
            sscanf(buffer, "%c %d %f", &command, &table_size, &constant_a);
            TBLInit(ptable, table_size, hashFunc, constant_a);
            break;
        case 'i':
            sscanf(buffer, "%c %d", &command, &data);
            TBLInsert(ptable, data, data);
            break;
        case 'd':
            sscanf(buffer, "%c %d", &command, &data);
            TBLDelete(ptable, data);
            break;
        case 'f':
            sscanf(buffer, "%c %d", &command, &data);
            TBLFind(ptable, data);
            break;
        case 'p':
            TBLPrint(ptable);
            break;
    }
}

int main(int argc, char const *argv[])
{
    Table table;
    char buffer[MAX_BUFFER_SIZE];
 
    while (1) {
        if (fgets(buffer, sizeof(buffer), stdin) == NULL) break;
        
        ExecuteHashingOp(&table, buffer);
    }

    return 0;
}