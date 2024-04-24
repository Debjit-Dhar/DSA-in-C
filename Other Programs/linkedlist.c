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
    if(cur==NULL)//if list is empty return 0 or due to some reason some node is accessed ie not part of linked list or outside
        return 0;
    else
        return ((cur->link)==NULL);//return 1 if cur is last node else return 0
}
void insert_front(listPointer target,listPointer *head)
{
    target->link=*head;//link of target store the location of previous head
    *head=target;//new headpointer=location of target
}
void insert_after(listPointer target,listPointer prev)
{
    target->link=prev->link;
    prev->link=target;    
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
void printr_l(listPointer head)
{
    if(atend_l(head))
    {
        printf("%d\t",(head->d).n);
        return;
    }
    else
    {
        printr_l(head->link);
        printf("%d\t",(head->d).n);
    }
}
listPointer searchunord_l(listPointer *head,struct data dat)
{
    listPointer cur;
    if(((*head)->d).n==dat.n)
    {
        cur=*head;
        delete_front(head);
        return cur;
    }
    while(!atend_l(cur))
    {
        cur=(*head)->link;
        if((cur->d).n==dat.n)
        {
            delete_after(*head);
            return cur;
        }
        (*head)=(*head)->link;
    }
    return NULL;
}
listPointer searchord_l(listPointer *head,struct data dat)
{
    listPointer cur;
    if(((*head)->d).n==dat.n)
    {
        cur=*head;
        delete_front(head);
        return cur;
    }
    while(!atend_l(cur)&&dat.n>=((*head)->d).n)
    {
        cur=(*head)->link;
        if((cur->d).n==dat.n)
        {
            delete_after(*head);
            return cur;
        }
        (*head)=(*head)->link;
    }
    return NULL;
}
int size(listPointer head)
{
    int c=1;
    while(!atend_l(head))
    {
        c++;
        head=head->link;
    }
    return c;
}
int sorted_l(listPointer head)
{
    listPointer cur;
    while(!atend_l(head))
    {
        cur=head->link;
        if((cur->d).n<(head->d).n)
            return 0;
        head=head->link;
    }
    return 1;
}
void del_l(listPointer head)
{
    listPointer cur;
    while(!atend_l(head))
    {
        cur=head;
        head=head->link;
        free(cur);
    }
    free(cur);
}
void reverse_l(listPointer head)
{
    listPointer ptr=head; 
    int i,j,n=size(head);
    for(i=n-1;i>0;i--)
    {
        head=ptr;
        for(j=0;j<i;j++)
        {
            struct data dat=head->d;
            head->d=(head->link)->d;
            (head->link)->d=dat;
            head=head->link;
        }
    } 
}
void bubble_sort(listPointer head) //Bubble Sort
{ 
    listPointer ptr=head; 
    int i,j,n=size(head);
    for(i=n-1;i>0;i--)
    {
        head=ptr;
        for(j=0;j<i;j++)
        {
            if((head->d).n>((head->link)->d).n)
            {
                struct data dat=head->d;
                head->d=(head->link)->d;
                (head->link)->d=dat;
            }
            head=head->link;
        }
    } 
}
void selection_sort(listPointer head)// Selection Sort
{
    int i,j,n=size(head);
    struct data temp;
    listPointer ptr,small=head;
    for(i=0;i<n;i++)
    {
        ptr=small->link;
        for(j=i+1;j<n;j++)
        {
            if((small->d).n>(ptr->d).n)
                small=ptr;
            if(!atend_l(ptr))ptr=ptr->link;
        }
        temp=small->d;
        small->d=head->d;
        head->d=temp;
        head=head->link;
        small=head;
    }
}
void insertion_sort(listPointer head)//Insertion Sort
{

}
void merge(listPointer head,int l,int m,int r)
{
    int n1=m-l+1,n2=r-m,i,j,k;
    listPointer Lhead=(listPointer)malloc(sizeof(*head)),Rhead=(listPointer)malloc(sizeof(*head)),c1=head,c2=Lhead,c3=Rhead;
    for(i=0;i<n1;i++)
    {
        for(j=1;j<=l;j++)
            head=head->link;
        Lhead->d=head->d;
        Lhead->link=(listPointer)malloc(sizeof(*head));
        Lhead=Lhead->link;
    }
    for(i=0;i<n1;i++)
    {
        for(j=1;j<=m+1;j++)
            head=head->link;
        Rhead->d=head->d;
        Rhead->link=(listPointer)malloc(sizeof(*head));
        Rhead=Lhead->link;
    }
    head=c1;Lhead=c2;Rhead=c3;
    i=0;j=0;
    for(k=1;k<=l;k++)
        head=head->link;
    while(i<n1&&j<n2)
    {
        if((Lhead->d).n<=(Rhead->d).n)
        {
            head->d=Lhead->d;
            Lhead=Lhead->link;
            head=head->link;
            i++;
        }
        else
        {
            head->d=Rhead->d;
            Rhead=Rhead->link;
            head=head->link;
            j++;
        }
    }
    while(i<n1)
    {
        head->d=Lhead->d;
        Lhead=Lhead->link;
        head=head->link;
        i++;
    }
    while(j<n2)
    {
        head->d=Rhead->d;
        Rhead=Rhead->link;
        head=head->link;
        j++;
    }
}
void merge_sort(listPointer head,int l,int r)//Merge Sort
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(head,l,m);
        merge_sort(head,m+1,r);
        merge(head,l,m,r);
    }
}
void quick_sort(listPointer head)//Quick Sort
{

}

void main()
{
    listPointer head=(listPointer)malloc(sizeof(*head)),prev,target;
    head=init_l();
    target=init_l();
    prev=init_l();
    int ch,choi;
    struct data dat;
    int c=0;
    while(1)
    {
        printf("Enter choice:\n1 to insert\n2 to display in order\n3 to display in reverse order\n4 to search in an unordered list\n5 to search in an ordered list\n6 to print length of list\n7 to check if list is sorted\n8 to insert a target before a specified node\n9 to delete a list\n10 to reverse a list\n11 to sort a list\nany other to exit\n");
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
                if(c==0)
                {
                    prev->link=init_l();
                    c++;
                }
            }
            else
            {
                insert_after(target,prev);
                prev=target;
            }
            break;
            case 2:
            print_l(head);
            break;
            case 3:
            if(!empty_l(head))
            {
                printr_l(head);
                printf("\n");
            }
            else
                printf("Empty List.\n");            
            break;
            case 4:
            if(empty_l(head))
            {
                printf("Empty list.\n");
                break;
            }
            printf("Enter key.\n");
            scanf("%d",&(dat.n));
            target=searchunord_l(&head,dat);
            if(target)
                printf("Key found.\n");
            else
                printf("Key not found.\n");
            break;
            case 5:
            if(empty_l(head))
            {
                printf("Empty list.\n");
                break;
            }
            printf("Enter key.\n");
            scanf("%d",&(dat.n));
            target=searchord_l(&head,dat);
            if(target)
                printf("Key found.\n");
            else
                printf("Key not found.\n");
            break;
            case 6:
            if(empty_l(head))
            {
                printf("Empty list.\n");
                break;
            }
            printf("Current size of list=%d\n",size(head));
            break;
            case 7:
            if(empty_l(head))
            {
                printf("Empty list is sorted.\n");
                break;
            }
            if(sorted_l(head))
                printf("List is sorted.\n");
            else
                printf("List is unsorted.\n");
            break;
            case 8:
            break;
            case 9:
            del_l(head);
            printf("List Deleted.\n");
            exit(1);
            break;
            case 10:
            reverse_l(head);
            break;
            case 11:
            printf("Enter choice\n1 for bubble sort\n2 for selection sort\n3 for insertion sort\n4 for merge sort\n5 for quick sort.\n");
            scanf("%d",&choi);
            switch(choi)
            {
                case 1:
                bubble_sort(head);
                break;
                case 2:
                selection_sort(head);
                break;
                case 3:
                insertion_sort(head);
                break;
                case 4:
                merge_sort(head,0,size(head)-1);
                break;
                case 5:
                quick_sort(head);
                break;
                default:
                printf("Wrong Choice.\n");
            }
            break;
            default:
            free(head);
            return;
        }
    }
}