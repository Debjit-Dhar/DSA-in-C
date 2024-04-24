#include <stdio.h>
#include <stdlib.h>
#define MAX  5 /* Maximum size of the queue*/
#define INV -100000
struct queue_type{
    int front;
    int rear;
    int count;
    int arr[MAX];
};
typedef  struct queue_type* Queue;
Queue q_create()
{
    Queue q=(Queue)(malloc(sizeof(struct queue_type)));
    if(q==NULL)
        printf("Memory not allocated\n");
    else{
        for(int i=0;i<MAX;i++)
            q->arr[i]=0;
    q->front=0;
    q->rear=0;
    q->count = 0 ;
    }
    return q;
}
void q_dispose(Queue q)
{
    if(!q)
        free(q);
}
int q_isempty(Queue q)
{
    return q->count==0;
}
int q_isfull(Queue q)
{
    return  q->count == MAX;
}
int enqueue(Queue q,int x)
{
    if(q_isfull(q))
        return 0;
    else{
        q->arr[q->rear]=x;
        q->rear= (q->rear+1)%MAX;
        q->count++;
        return 1;
    }
}
int dequeue(Queue q)
{
    if(q_isempty(q)){
        return INV;
    }
    else
    {
        int x=q->arr[q->front];
        q->arr[q->front]=0;
        q->front=(q->front +1)%MAX;
        q->count--;
        return x;
    }
}
int priority_enqueue(Queue q,int x, int(*cmp)(int,int))
{
    int a[MAX],y,i=0;
    if(q_isfull(q))
        return 0;
    else{
        while(!q_isempty(q))
        {
            y=dequeue(q);
            a[i++]=y;
            if(cmp(y,x)<=0) break;
        }
        for(y=i-1;y>=0;y--)
            enqueue(q,a[y]);
        enqueue(q,x);
        return 1;
    }
}
int cmp(int y,int x)
{
    return y-x;
}

int main() 
{
    Queue q = q_create(); // Initialize the queue

    int ch;
    int dat;
    int(*compare)(int,int);
    compare=cmp;
    while(1)
    {
        printf("Enter choice.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter data.\n");
                scanf("%d",&(dat));
                priority_enqueue(q,dat,compare)==1?printf("Enqueing %d\n",dat):printf("Queue Overflow.\n");
                break;
            case 2:
                dat=dequeue(q);
                dat!=INV?printf("Dequeueing %d\n",dat):printf("Queue Underflow.\n");
                break;
            case 3:
                for(int i=0;i<MAX;i++)
                    printf(" %d ",q->arr[i]);
                printf("\n");
                break;
            default:
            return 0;
        }
    }
    q_dispose(q); // Clean up the queue memory

    return 0;
}