#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 10
struct data
{
    char n;
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
char pop()
{
    if(!s_empty())
    {
        return (s->dat[s->top]).n;
        s->top--;
    }
    else
        return 0;
}
int less(char op1, struct stack_type* s) {
    if (s_empty()) {
        return 1; // If stack is empty, return true
    } else {
        char op2 = (s->dat[s->top]).n;
        
        // Assigning precedence values to operators
        int prec1, prec2;
        switch (op1) {
            case '+':
            case '-':
                prec1 = 1;
                break;
            case '*':
            case '/':
                prec1 = 2;
                break;
            default:
                prec1 = 0;
        }

        switch (op2) {
            case '+':
            case '-':
                prec2 = 1;
                break;
            case '*':
            case '/':
                prec2 = 2;
                break;
            default:
                prec2 = 0;
        }

        return (prec1 <= prec2); // Return true if precedence of op1 is less than or equal to op2
    }
}
int main()
{
    char infix[100];
    scanf("%s",infix);
    printf("%s\n",infix);
    char postfix[100];
    int i=0,j=0;
    while(infix[i]!='$')
    {
        if(isalpha(infix[i]))
            postfix[j++]=infix[i];
        else
        {
            struct data d;
            d.n=infix[i];
            if(less(d.n,s))
            {
                while(!s_empty())
                    postfix[j++]=pop();
            }
            else
                push(d);
        }
        i++;
    }
    printf("%s\n",postfix);
    return 0;
}