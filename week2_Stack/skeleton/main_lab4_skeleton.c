#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"

#define MAX_BUFFER_SIZE  100

int isDigit(char c)
{
    return '0'<= c && c <= '9';
}

int ReturnPriority(char op)
{
    switch (op) {
        
        case '*':
        case '/':
        case '%':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;
        default: 
            return 0;
    }
}

int StackTopIsPrior(Data new, Data stackTop) {
    
    return ReturnPriority(new) <= ReturnPriority(stackTop);

}


char *InfixToPostfix(char *infix)
{
    printf("우리 시작한다\n");
    Stack stack;
    StackInit(&stack);
    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));  // length + 1 for end zero
    memset(postfix, 0, sizeof(char) * (strlen(infix) + 1));

    char curChar;
    int curidx = 0;
    for (int i = 0; i < strlen(infix); i++) {
        curChar = infix[i];
        
        if (isDigit(curChar)) {
            postfix[curidx++] = curChar;
            continue;
        }

        switch(curChar) {
            
            case '(':
                SPush(&stack, curChar);
                break;
            case ')':
                while(SPeek(&stack) != '(') {
                    postfix[curidx++] = SPop(&stack);
                }
                SPop(&stack);
                break;

            case '+': case '-':
            case '*': case '/':
            case '%':
                while(!SIsEmpty(&stack) && StackTopIsPrior(curChar, SPeek(&stack)) ) {
                    postfix[curidx++] = SPop(&stack);
                }

            SPush(&stack, curChar);

        }

    }
    while(!SIsEmpty(&stack)){
        postfix[curidx++] = SPop(&stack);
    }


    return postfix;
}

int main(int argc, char const *argv[])
{
    
    char buffer[MAX_BUFFER_SIZE];
    char *postfix;

    FILE *fp = fopen(argv[1], "r");
    while (1) {
        if (fgets(buffer, sizeof(buffer), fp) == NULL) break;
        printf("original infix form : %s\n", buffer);
        postfix = InfixToPostfix(buffer);
        printf("converted postfix form: %s\n", postfix);
    }

    // Stack stack;
    // StackInit(&stack);
    // SPush(&stack, '3');
    // SPush(&stack, '5');
    // SPush(&stack, '1');
    // PrintStack(&stack);


    // printf("Peeked : %c", SPeek(&stack));
    // printf("Poped : %c\n", SPop(&stack));
    // PrintStack(&stack);
    // printf("Peeked : %c", SPeek(&stack));
    // printf("Poped : %c\n", SPop(&stack));
    // PrintStack(&stack);
    // printf("Peeked : %c", SPeek(&stack));
    // printf("Poped : %c\n", SPop(&stack));

    // SPeek(&stack);
    return 0;
}
