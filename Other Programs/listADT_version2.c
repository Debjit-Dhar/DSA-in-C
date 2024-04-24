#include <stdio.h>
#define MAX 100
//List without using sentinel
struct list
{
    int n;
};
void read(struct list a[])
{
    for(int i=1;i<=a[0].n;i++)
        printf("%d\n",a[i].n);
}
struct list retrieve(struct list a[],int i)
{
    return a[i];
}
void store(struct list a[],int i)
{
    printf("Enter value.\n");
    scanf("%d",&a[i].n);
    a[0].n++;
}
void insert(struct list a[],int i)
{
    int j;
    if(i>a[0].n)
        printf("Outside list.\n");
    else
    {
        a[0].n+=1;
        for(j=a[0].n;j>i;j--)
            a[j].n=a[j-1].n;
        printf("Enter number.\n");
        scanf("%d",&a[j].n);
    }
}
void delete(struct list a[],int i)
{
    if(i>a[0].n)
        printf("Outside list.\n");
    else
    {
        a[0].n-=1;
        for(;i<=a[0].n;i++)
            a[i].n=a[i+1].n;
    }
}
int search(struct list a[],int num)
{
    for(int i=1;i<=a[0].n;i++)
    if(a[i].n==num)
        return i;
    return -1;
}
void sort(struct list a[])
{
    struct list temp;
    for(int i=a[0].n;i>0;i--)
    {
        for(int j=1;j<=i;j++)
        if(a[j].n>a[j+1].n)
        {
            temp=a[j];
            a[j]=a[j+1];
            a[j+1]=temp;
        }
    }
    read(a);
}
void main()
{
    struct list a[MAX],temp;
    int ch,i;
    a[0].n=0;
    while(1)
    {
        printf("1.length 2.read 3.retrieve 4.store new 5.insert 6.delete 7.search 8.sort any other to exit.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Length of list= %d\n",a[0]);
            break;
            case 2:
            if(a[0].n==0)
                printf("Empty List.\n");
            else   
                read(a);
            break;
            case 3:
            if(a[0].n==0)
                printf("Empty List.\n");
            else
            {
                printf("Enter the value of i.\n");
                scanf("%d",&i);
                if(i>a[0].n)
                    printf("%d th element does not exist.\n",i);
                else
                    {temp=retrieve(a,i);printf("%d\n",temp.n);}
            }
            break;
            case 4:
            i=a[0].n+1;
            store(a,i);
            break;
            case 5:
            printf("Enter the position.\n");
            scanf("%d",&i);
            insert(a,i);
            break;
            case 6:
            printf("Enter the position.\n");
            scanf("%d",&i);
            delete(a,i);
            break;
            case 7:
            if(a[0].n==0)
                printf("Empty List.\n");
            else
            {
                printf("Enter the value to be searched.\n");
                scanf("%d",&i);
                if(search(a,i)!=-1)
                    printf("Found at %d\n",search(a,i));
                else
                    printf("Not Found.\n");
            }
            break;
            case 8:
            if(a[0].n==0)
                printf("Empty List.\n");
            else
                sort(a);
            break;
            default:
            return;
        }
    }
}