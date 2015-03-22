#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int top, S[1000];

void push(int x) {
    S[top++] = x;
}

int pop() {
    top--;
    return S[top+1];
}

int main() {
    int a, b;
    top = 0;

    char s[100];

    while (scanf("%s", s) != EOF) {
        switch(s[0]) {
            case '+':
                a = pop();
                b = pop();
                push(a + b);
                break;
            case '-':
                a = pop();
                b = pop();
                push(a - b);
                break;
            case '*':
                a = pop();
                b = pop();
                push(a * b);
                break;
            default:
                push(atoi(s));
        }
    }

    printf("%d\n", pop());
    return 0;
}
