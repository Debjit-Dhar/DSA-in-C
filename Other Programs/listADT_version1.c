#include <stdio.h>
//List using sentinel
#define MAX 100
struct data
{
    int n;
};
struct data list[MAX];
int len()
{
    for(int i=0;i<MAX;i++)
        if(list[i].n==-1)
            return i;
}
void read()
{
    int i=0;
    while(list[i].n!=-1)
    {
        printf("%d\n",list[i].n);
        i++;        
    }
}
struct data retrieve(int i)
{
    return list[i];
}
int store(int i)
{
    printf("Enter positive data.\n");
    scanf("%d",&list[i].n);
    list[++i].n=-1;
}
void insert(int i)
{
    int j,l;
    if(i>=len())
        printf("Outside list.\n");
    else
    {
        l=len();
        for(j=l;j>i;j--)
            list[j].n=list[j-1].n;
        printf("Enter number.\n");
        scanf("%d",&list[j].n);
        list[l+1].n=-1;
        
    }
}
void delete(int i)
{
    if(i>=len())
        printf("Outside list.\n");
    else
    {
        for(;i<=len();i++)
            list[i].n=list[i+1].n;
    }
}
int search(int num)
{
    for(int i=0;i<len();i++)
    if(list[i].n==num)
        return i;
    return -1;
}
void sort()
{
    struct data temp;
    for(int i=len()-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        if(list[j].n>list[j+1].n)
        {
            temp=list[j];
            list[j]=list[j+1];
            list[j+1]=temp;
        }
    }
    read();
}
void main()
{
    struct data temp;
    int ch,i;
    list[0].n=-1;
    while(1)
    {
        printf("1.length 2.read 3.retrieve 4.store new 5.insert 6.delete 7.search 8.sort any other to exit.\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Length of list= %d\n",len());
            break;
            case 2:
            if(list[0].n==-1)
                printf("Empty List.\n");
            else   
                read();
            break;
            case 3:
            if(list[0].n==-1)
                printf("Empty List.\n");
            else
            {
                printf("Enter the value of i.\n");
                scanf("%d",&i);
                if(i>=len())
                    printf("%d th element does not exist.\n",i);
                else
                    {temp=retrieve(i);printf("%d\n",temp.n);}
            }
            break;
            case 4:
            store(len());
            break;
            case 5:
            printf("Enter the position.\n");
            scanf("%d",&i);
            insert(i);
            break;
            case 6:
            printf("Enter the position.\n");
            scanf("%d",&i);
            delete(i);
            break;
            case 7:
            if(list[0].n==-1)
                printf("Empty List.\n");
            else
            {
                printf("Enter the value to be searched.\n");
                scanf("%d",&i);
                if(search(i)!=-1)
                    printf("Found at %d\n",search(i));
                else
                    printf("Not Found.\n");
            }
            break;
            case 8:
            if(list[0].n==-1)
                printf("Empty List.\n");
            else
                sort();
            break;
            default:
            return;
        }
    }
}