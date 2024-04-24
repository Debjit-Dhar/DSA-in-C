#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct listNode*listPointer;
struct listNode{
    int data;
    listPointer link;
};
listPointer insert(listPointer *first,listPointer x,int n)
{
    listPointer temp=(listPointer)malloc(sizeof(*temp));
    temp->data=n;
    if(*first)
    {
        temp->link=x->link;
        x->link=temp;
    }
    else
    {
        temp->link=NULL;
        *first=temp;
    }
    return temp;
}
void delete(listPointer *first,int num)//trail is the node preceding x,x is the node that is to be deleted.
{
    listPointer trail,x;
    listPointer *first1=first;
    if((*first)->data==num)
    {
        trail=NULL;
        x=*first;
    }
    else{
    for(;(*first)->link;*first=(*first)->link)
        if(((*first)->link)->data==num)
        {
            trail=*first;
            x=(*first)->link;
        }
    }
    if(trail)
        trail->link=x->link;
    else
        {*first=(*first)->link;printf("Hello.\n");}
    first=first1;
    free(x);
}
void printList(listPointer first)
{
    if(!first)
    {
        printf("Linked List is Empty.\n");
        return;
    }
    printf("The Linked List is:\t");
    for(;first;first=first->link)
        printf("%d\t",first->data);
    printf("\n");
}
void main()
{
    listPointer first=NULL,next;
    first=(listPointer)malloc(sizeof(*first));
    first->data=0;
    first->link=NULL;
    next=first;
    int ch,num;
    while(1)
    {
        printf("Enter choice 1 to insert 2 to delete 3 to print and any other to exit.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter number.\n");
            scanf("%d",&num);
            next=insert(&first,next,num);
            break;
            case 2:
            printf("Enter data to be deleted.\n");
            scanf("%d",&num);
            delete(&first,num);
            break;
            case 3:
            printList(first);
            break;
            default:
            printf("Exiting...\n");
            free(first);
            return;
        }
    }
}