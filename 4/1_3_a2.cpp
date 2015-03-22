#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define MAX 200
 
int sp = MAX;
int stack[MAX];
 
static void push(int a) {
    if (sp > 0) {
        stack[--sp] = a;
    } else {
        fprintf(stderr, "push error\n");
    }
}
 
static int pop() {
    if (sp < MAX) {
        return stack[sp++];
    } else {
        return 0;
    }
}
 
 
int main() {
    char s[MAX];
    int x = 0, y = 0;
 
    while (scanf("%s", s) != EOF) {
        if (s[0] == '+') {
            push(pop() + pop());
        } else if (s[0] == '-') {
            y = pop();
            x = pop();
            push(x - y);
        } else if (s[0] == '*') {
            push(pop() * pop());
        } else {
            push(atoi(s));
        }
    }
 
    printf("%d\n", pop());
 
    return 0;
}
