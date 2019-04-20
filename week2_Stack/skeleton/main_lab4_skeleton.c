#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Stack.h"

#define MAX_BUFFER_SIZE  100

int ReturnPriority(char op)
{
    switch (op) {
        case '(':
            return 3;
        case '*':
        case '/':
        case '%':
            return 2;
        case '+':
        case '-':
            return 1;
        default: 
            return 0;
    }
}

int comparePriorityOfOperator(char op1, char op2) {
    if (op1 == '(') {
        return -1;
    }

    int priorityOfOp1 = ReturnPriority(op1);
    int priorityOfOp2 = ReturnPriority(op2);

    if (priorityOfOp1 > priorityOfOp2) {
        return 1;
    }
    else if (priorityOfOp1 == priorityOfOp2) {
        return 0;
    }
    else {
        return -1;
    }
}

char *InfixToPostfix(char *infix)
{
    Stack stack;
    StackInit(&stack);
    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));  // length + 1 for end zero
    memset(postfix, 0, sizeof(char) * (strlen(infix) + 1));

    int lastIdx = 0;
    for(int i = 0; i < strlen(infix); i++) {
        if( infix[i] >= '0' && infix[i] <= '9' ) {
            postfix[lastIdx++] = infix[i];
            continue;
        }

        if (infix[i] == ')') {
            while(SPeek(&stack) != '(') {
                postfix[lastIdx++] = SPop(&stack);
            }
            SPop(&stack);
            continue;
        }

        while(SIsEmpty(&stack) == FALSE && comparePriorityOfOperator(SPeek(&stack), infix[i]) >= 0) {
            postfix[lastIdx++] = SPop(&stack);
        }
        if (SIsEmpty(&stack) == TRUE || comparePriorityOfOperator(SPeek(&stack), infix[i]) == -1){
            SPush(&stack, infix[i]);
            continue;            
        }
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
    return 0;
}
