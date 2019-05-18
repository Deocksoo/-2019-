#include <stdio.h>
#include "LinkedList.h"

void ExecuteListOp(List* plist, char* buffer)
{
    char command;
    int new_element;
    int key;
    command = buffer[0];

    switch (command) {
        case 'i':
            sscanf(buffer, "%c %d %d", &command, &new_element, &key);
            LInsert(plist, new_element, key);
            break;
        case 'd':
            sscanf(buffer, "%c %d", &command, &key);
            LDelete(plist, key);
            break;
        case 'f':
            sscanf(buffer, "%c %d", &command, &key);
            PrintPreviousKeyOf(plist, key);
            break;
        case 'p':
            PrintList(plist);
            break;
        default:
            printf("Wrong instruction.\n");
    }
}

int main(int argc, const char *argv[])
{
    List list;
    char buffer[10];

    InitList(&list);
    IsEmpty(&list);

    while(1){
        if(fgets(buffer, sizeof(buffer), stdin) == NULL) break;
        
        ExecuteListOp(&list, buffer);
    }

    return 0;
}