#include <stdio.h>
void print(int a)
{
    switch(a)
    {
        case 1:
        printf("Source Tower");
        break;
        case 2:
        printf("Mid Tower");
        break;
        case 3:
        printf("Destination Tower");
    }
}
void hanoi(int n,int source,int mid,int dest,int *count)
{
    if(n==1)
    {
        printf("From ");
        print(source);
        printf(" to ");
        print(dest);
        printf("\n");
        *count+=1;
        return;
    }    
    else
    {
        *count+=1;
        hanoi(n-1,source,dest,mid,count);
        printf("From ");
        print(source);
        printf("to ");
        print(dest);
        printf("\n");
        hanoi(n-1,mid,source,dest,count);
    }
}
void main()
{
    printf("Enter number of disks.\n");
    int n;
    scanf("%d",&n);
    int count=0;
    hanoi(n,1,2,3,&count);
    printf("%d number of steps required.\n",count);
}