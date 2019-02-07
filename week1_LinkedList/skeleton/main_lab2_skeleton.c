#include <stdio.h>
#include "LinkedList.h"

void ExecuteListOp(List *plist, char *buffer)
{
    char command;
    int new_element;
    int key;
    command = buffer[0];

    switch (command) {
        case 'i':
            // key값과 new element값을 받아 온다
            // Insert 함수를 실행시키고 plist와 key, new element를 넘겨준다.

            // Insert 함수
            // key 값과 new element 값을 받아 온다
            // key값의 뒤에 new element를 data로 하는 node를 하나 Insert 한다!
            // 만약 key값을 찾지 못하면 error 메시지를 띄운다.
            break;
        case 'd':
            // key 값을 받아온다.
            // Delete 함수를 실행시키고, plist와 key값을 넘겨준다.

            // Delete 함수
            // key값을 넘겨받는다
            // key값을 가진 node를 지운다.
            // 만약 key값을 가진 node가 없으면 error 메시지를 띄운다.
            break;
        case 'f':
            // key값을 받아온다
            // FindPrevNode 함수를 호출하여 메시지 띄운다!

            // FindePrevElement 함수
            // key값을 넘겨받는다
            // key값에 따라 메시지를 띄운다.
            // key값이 없는 경우 에러 메시지를 띄운다
            break;
        case 'p':
            // list를 넘겨주고 출력시킨다.
            break;
        default:
            printf("Wrong instruction.\n");
    }

    printf("%s", buffer);
}

int main(int argc, const char *argv[])
{
    List list;
    char buffer[10];

    InitList(&list);

    FILE *fp = fopen(argv[1],"r");
    while(1){
        if(fgets(buffer, sizeof(buffer), fp) == NULL) break;
        
        ExecuteListOp(&list, buffer);
    }
    fclose(fp);

    return 0;
}