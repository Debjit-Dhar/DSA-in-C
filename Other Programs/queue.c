#include <stdio.h>
int rear=0,soq=5;
struct data
{
    int n;
};
struct queue
{
    struct data d;
};
int enqueue(struct data dat,struct queue q[])
{
    if(rear==soq)
        return 0;
    else
    {
        q[rear++].d=dat; 
        return 1;           
    }
}
int dequeue(struct queue q[])
{
    if(rear==0)
        return 0;
    else
    {
        struct data a=q[0].d;
        for(int i=0;i<rear-1;i++)
            q[i]=q[i+1];
        q[rear].d=a;
        rear--;
        return 1;
    }
}
int print(struct queue q[])
{
    if(rear==0)
        return 0;
    else
    {
        for(int i=0;i<rear;i++)
            printf("%d\t",q[i]);
        printf("\n");
        return 1;
    }
}
void main()
{
    struct queue q[soq];
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
            enqueue(dat,q)==1?printf("Enqueing %d\n",dat.n):printf("Queue Overflow.\n");
            break;
            case 2:
            dequeue(q)==1?printf("Dequeing %d\n",(q[rear+1].d).n):printf("Queue Underflow.\n");
            break;
            case 3:
            if(print(q)==0)
                printf("Queue Empty.\n");
            break;
            default:
            return;
        }
    }
}