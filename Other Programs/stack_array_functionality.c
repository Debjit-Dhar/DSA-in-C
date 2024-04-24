#include <stdio.h>
#include <stdlib.h>

#define MAX 10

struct data {
    int n;
};

struct stack_type {
    int top;
    struct data dat[MAX];
};

void s_create(struct stack_type**s)
{    
    *s=(struct stack_type*)malloc(sizeof(struct stack_type));
    if(s==NULL)
        perror("Malloc Error.\n");
    (*s)->top=-1;
}

int s_empty(struct stack_type* s) {
    return (s->top == -1);
}

int s_full(struct stack_type* s) {
    return (s->top == MAX - 1);
}

void push(struct stack_type* s, struct data d) {
    if (!s_full(s)) {
        s->dat[++(s->top)] = d;
    } else {
        printf("Stack Overflow.\n");
    }
}

struct data pop(struct stack_type* s) {
    struct data d = (s->dat[s->top]);
    s->top--;
    return d;
}

int duplicate_top(struct stack_type* s) {
    struct data d;
    if (!s_empty(s) && !s_full(s)) {
        d = pop(s);
        push(s, d);
        push(s, d);
        return 1;
    } else {
        return 0;
    }
}

void dispose(struct stack_type* s) {
    free(s);
}

int print(struct stack_type* s) {
    struct stack_type *scopy;
    struct data d;
    s_create(&scopy); // Initialize the scopy stack

    if (!s_empty(s)) {
        while (!s_empty(s)) {
            d = pop(s);
            printf("%d\n", d.n);
            push(scopy, d);
        }

        while (!s_empty(scopy)) {
            d = pop(scopy);
            push(s, d);
        }
        return 1;
    }
    return 0;
}

int main() {
    struct stack_type *s1, *s2;
    struct data d1, d2, d3; // Sample data elements
    d1.n = 10;
    d2.n = 20;
    d3.n = 30;

    s_create(&s1); // Initializing the stack
    s_create(&s2);

    // Pushing elements onto the stack
    push(s1, d1);
    push(s1, d2);
    push(s1, d3);
    duplicate_top(s1);
    print(s1);

    return 0;
}
