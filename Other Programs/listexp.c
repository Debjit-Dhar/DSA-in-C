#include <stdio.h>
#include <stdlib.h>
typedef struct list* listPointer;
struct Student{
    int roll;
    char name[100];
    float score;
};
struct list{
    struct Student s;
    listPointer link;
};
listPointer insert(listPointer* first,listPointer x)
{
    listPointer temp=(listPointer)malloc(sizeof(*temp));
    printf("Enter roll.\n");
    scanf("%d",&((temp->s).roll));
    printf("Enter name.\n");
    scanf("%s",(temp->s).name);
    printf("Enter score.\n");
    scanf("%f",&((temp->s).score));
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
void delete(listPointer*first,int r)
{
    listPointer trail,x;
    if(*first==NULL)
        printf("No List.\n");
    else
    {
        if(((*first)->s).roll==r)
        {
            x=*first;
            *first=x->link;
            free(x);
        }
        else
        {
            trail=*first;
            x=(*first)->link;
            while(x!=NULL)
            {
                if((x->s).roll==r)
                {
                    trail->link=x->link;
                    free(x);
                    break;
                }
                else
                {
                    trail=x;
                    x=x->link;
                }
            }
        }
        if(x==NULL)
            printf("Target not found.\n");
    }
}
void print(listPointer first)
{
    if(!first)
    {
        printf("List is empty.\n");
        return;
    }
    printf("ROLL\tNAME\tSCORE\n");
    for(;first;first=first->link)
        printf("%d\t%s\t%f\n",(first->s).roll,(first->s).name,(first->s).score);
}
void sort(listPointer *first)
{
    listPointer next=(*first)->link,temp;
    listPointer*start;
    int i,j,n=0;
    while(first)
    {
        *first=(*first)->link;
        n++;
    }
    for(i=n-1;i>=0;i--)
    {
        first=start;
        for(j=0;j<i;j++)
        {
            next=(*first)->link;
            if(((*first)->s).roll>(next->s).roll)
            {
                temp=*first;
                *first=next;
                next=temp;
            }
            *first=next;
        }
    }
}
void main()
{
    listPointer first=(listPointer)malloc(sizeof(*first)),next;
    first=NULL;
    next=first;
    int ch,r;
    while(1)
    {
        printf("Enter choice 1 to insert 2 to delete 3 to display 4 to search 5 to sort.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            next=insert(&first,next);
            break;
            case 2:
            printf("Enter roll of record to be deleted.\n");
            scanf("%d",&r);
            delete(&first,r);
            break;
            case 3:
            print(first);
            break;
            case 4:
            break;
            case 5:
            sort(&first);
            print(first);
            break;
            default:
            free(first);
            return;
        }
    }
}