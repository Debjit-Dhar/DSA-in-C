#include <stdio.h>
#include <stdlib.h>
typedef struct list* listPointer;
struct data{
    int n;
};
struct list{
    struct data d;
    listPointer link;
};
listPointer init_l()
{
    return NULL;
}
int empty_l(listPointer head)
{
    return(head==NULL);//return 1 if head=NULL else return 0
}
int atend_l(listPointer cur)
{
    /*if(cur==NULL)//if list is empty return 0 or due to some reason some node is accessed ie not part of linked list or outside
        return 0;
    else*/
        return ((cur->link)==NULL);//return 1 if cur is last node else return 0
}
void insert_front(listPointer target,listPointer *head)
{
    target->link=*head;//link of target store the location of previous head
    *head=target;//new headpointer=location of target
}
void insert_after(listPointer target,listPointer prev)
{
    /*listPointer cur;
    cur = prev -> link;
    target -> link = cur;
    prev -> link = target;*/
    prev->link=target;
    target->link=init_l();
}
void delete_front(listPointer *head)
{
    listPointer cur=*head;
    *head=(*head)->link;
    free(cur);
}
void delete_after(listPointer prev)
{
    listPointer cur;
    if(!atend_l(prev))
    {
        cur=prev->link;
        prev->link=cur->link;
        free(cur);
    }
}
//END OF UTILITY FUNCTIONS
void print_l(listPointer head)
{
    if(!empty_l(head))
    {
        while(!atend_l(head))
        {
            printf("%d\t",(head->d).n);
            head=head->link;
        }      
        printf("%d",(head->d).n);
        printf("\n"); 
    }
    else
        printf("Empty List.\n");
}
/*
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
}*/
void main()
{
    listPointer head=(listPointer)malloc(sizeof(*head)),prev,target;
    head=init_l();
    target=init_l();
    prev=init_l();
    int ch,r;
    while(1)
    {
        printf("Enter choice 1 to insert 2 to display in order.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            target=(listPointer)malloc(sizeof(*target));
            printf("Enter data.\n");
            scanf("%d",&((target->d).n));
            if(empty_l(head))
            {
                insert_front(target,&head);
                prev=head;
            }
            else
            {
                insert_after(target,prev);
                prev=target;
            }
            break;
            case 2:
            print_l(head);
            /*printf("Enter roll of record to be deleted.\n");
            scanf("%d",&r);
            delete(&first,r);*/
            break;
            case 3:
            break;
            default:
            free(head);
            return;
        }
    }
}