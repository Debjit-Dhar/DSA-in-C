#include <stdio.h>
#include <stdlib.h>

#define MAX 3
#define INV -1000

struct data {
    int n;
};
typedef struct
{
    int front;
    int rear;
    int count;
    struct data dat[MAX];
}queue_type;
typedef queue_type* queue;
queue init_q()
{
    queue q=(queue)malloc(sizeof(queue_type));
    if(!q)
        perror("Malloc Error");
    q->front=0;
    q->rear=-1;
    q->count=0;
    return q;
}
void dispose_q(queue q)
{
    if(!q)
        free(q);
}
int empty_q(queue q)
{
    return (q->count==0);
}
int full_q(queue q)
{
    return(q->count==MAX);
}
int enqueue(queue q,struct data d)
{
    if(!full_q(q))
    {
        q->rear=(q->rear+1)%MAX;
        q->dat[q->rear]=d;
        (q->count)++;
        return 1;
    }
    else
        return 0;
}
int dequeue(queue q)
{
    if(!empty_q(q))
    {
        struct data d;
        d=q->dat[q->front];
        q->front=(q->front+1)%MAX;
        (q->count)--;
        return d.n;
    }
    else
        return 0;
}
int main() 
{
    queue q = init_q(); // Initialize the queue

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
                enqueue(q,dat)==1?printf("Enqueing %d\n",dat.n):printf("Queue Overflow.\n");
                break;
            case 2:
                dat.n=dequeue(q);
                dat.n!=0?printf("Dequeueing %d\n",dat.n):printf("Queue Underflow.\n");
                break;
            default:
            return 0;
        }
    }
    dispose_q(q); // Clean up the queue memory

    return 0;
}