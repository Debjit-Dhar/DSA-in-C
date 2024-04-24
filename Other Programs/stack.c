#include <stdio.h>
int TOS=-1,sos=5;
struct data
{
    int n;
};
struct stack
{
    struct data d;
};
int push(struct data dat,struct stack s[])
{
    if(TOS==sos-1)
        return 0;
    else
    {
        s[++TOS].d=dat; 
        return 1;           
    }
}
int pop(struct stack s[])
{
    if(TOS==-1)
        return 0;
    else
    {
        TOS--;
        return 1;
    }
}
int print(struct stack s[])
{
    if(TOS==-1)
        return 0;
    else
    {
        for(int i=0;i<=TOS;i++)
            printf("%d\t",s[i]);
        printf("\n");
        return 1;
    }
}
void main()
{
    struct stack s[sos];
    int ch;
    struct data dat;
    while(1)
    {
        printf("Enter choice.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter data.\n");
            scanf("%d",&(dat.n));
            push(dat,s)==1?printf("Pushing %d\n",dat.n):printf("Stack Overflow.\n");
            break;
            case 2:
            pop(s)==1?printf("Popping %d\n",(s[TOS+1].d).n):printf("Stack Underflow.\n");
            break;
            case 3:
            if(print(s)==0)
                printf("Stack Empty.\n");
            break;
            default:
            return;
        }
    }
}