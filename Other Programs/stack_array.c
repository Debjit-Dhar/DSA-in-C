#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct data
{
    int n;
};
struct stack_type
{
    int top;
    struct data dat[MAX];
};
struct stack_type *s;
void s_create()
{
    s=(struct stack_type*)malloc(sizeof(struct stack_type));
    if(s==NULL)
        perror("Malloc Error.\n");
    s->top=-1;
}
void dispose()
{
    free(s);
}
int s_empty()
{
    return(s->top==-1);
}
int s_full()
{
    return (s->top==MAX-1);
}
void push(struct data d)
{
    if(!s_full())
    {
        s->dat[++(s->top)]=d;
    }
    else
        printf("Stack Overflow.\n");
}
void pop()
{
    if(!s_empty())
    {
        printf("%d\n",(s->dat[s->top]).n);
        s->top--;
    }
    else
        printf("Stack Underflow.\n");
}

int main() {
    struct data d1, d2, d3; // Sample data elements
    d1.n = 10;
    d2.n = 20;
    d3.n = 30;

    s_create(); // Initializing the stack

    printf("Is stack empty? %d\n", s_empty()); // Check if stack is empty

    // Pushing elements onto the stack
    push(d1);
    push(d2);
    push(d3);

    printf("Is stack full? %d\n", s_full()); // Check if stack is full

    // Popping elements from the stack
    printf("Popping elements from the stack:\n");
    pop();
    pop();
    pop();

    printf("Is stack empty? %d\n", s_empty()); // Check if stack is empty

    dispose(); // Freeing memory

    return 0;
}

