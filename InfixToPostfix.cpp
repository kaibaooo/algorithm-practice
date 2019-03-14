#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
int priority(char);

int main() {
    char infix[100] = { '\0' };
    char postfix[100] = { '\0' };
    char stack[100] = { '\0' };
    int top = 0;
    int idx = 0;
    printf("Input infix : ");
    scanf("%s", infix);
    for (int i = 0; infix[i] != '\0'; i++) {
        switch (infix[i]) {
        case '(':
            stack[top++] = infix[i];
            break;
        case ')':
            while (stack[--top] != '(') {
                postfix[idx++] = stack[top];
            }
            stack[top] = '\0'; //不輸出'('
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            while (priority(infix[i]) <= priority(stack[top])) {
                postfix[idx++] = stack[top--];
            }
            stack[top++] = infix[i];
            break;
        default:
            postfix[idx++] = infix[i];
            break;
        }
    }
    while (top > 0) {
        postfix[idx++] = stack[--top];
    }
    printf("postfix : %s", postfix);
    return 0;
}
int priority(char opc) {
    return opc == '+' || opc == '-' ? 1 : opc == '*' || opc == '/' ? 2 : 0;
}
