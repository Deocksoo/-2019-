#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "stack.h"

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

char *InfixToPostfix(char *infix)
{
    Stack stack;
    StackInit(&stack);
    char *postfix = (char *)malloc(sizeof(char) * (strlen(infix) + 1));  // length + 1 for end zero
    memset(postfix, 0, sizeof(char) * (strlen(infix) + 1));

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
