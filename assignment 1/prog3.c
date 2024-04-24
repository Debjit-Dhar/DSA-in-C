#include <stdio.h>
#include <string.h>
struct data
{
    int a[100];
    float b[100];
    char c[100][100];
};
int lsearch_int(struct data dat,int key,int n)
{
    for(int i=0;i<n;i++)
        if(dat.a[i]==key)
            return i;
    return -1;
}
int lsearch_float(struct data dat,float key,int n)
{
    for(int i=0;i<n;i++)
        if(dat.b[i]==key)
            return i;
    return -1;
}
int lsearch_word(struct data dat,char key[100],int n)
{
    for(int i=0;i<n;i++)
        if(strcmp(dat.c[i],key)==0)
            return i;
    return -1;
}
int bsearch_int(struct data dat,int key,int n)
{
    int start=0,end=n-1;
    while(start<end)
    {
        int mid=(start+end)/2;
        if(dat.a[mid]==key)
            return mid;
        else if(dat.a[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    if(dat.a[start]==key)
        return start;
    return -1;
}
int bsearch_float(struct data dat,float key,int n)
{
    int start=0,end=n-1;
    while(start<end)
    {
        int mid=(start+end)/2;
        if(dat.b[mid]==key)
            return mid;
        else if(dat.b[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    if(dat.b[start]==key)
        return start;
    return -1;
}
int bsearch_word(struct data dat,char key[100],int n)
{
    int start=0,end=n-1;
    while(start<end)
    {
        int mid=(start+end)/2;
        if(strcmp(dat.c[mid],key)==0)
            return mid;
        else if(dat.c[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    if(strcmp(dat.c[start],key)==0)
        return start;
    return -1;
}
void main()
{
    struct data dat;
    int n;
    printf("Enter number of data.\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("Enter integer.\n");
        scanf("%d",&dat.a[i]);
        printf("Enter float.\n");
        scanf("%f",&dat.b[i]);
        printf("Enter word.\n");
        scanf("%s",dat.c[i]);
    }
    printf("Enter int to be searched.\n");
    int n1;float n2;char s[100];
    scanf("%d",&n1);
    printf("Enter float to be searched.\n");
    scanf("%f",&n2);
    printf("Enter word to be searched.\n");
    scanf("%s",s);

    printf("Linear Search\n");

    if(lsearch_int(dat,n1,n)!=-1)
        printf("Found at %d\n",lsearch_int(dat,n1,n));
    else
        printf("Not Found.\n");
    if(lsearch_float(dat,n2,n)!=-1)
        printf("Found at %d\n",lsearch_float(dat,n2,n));
    else
        printf("Not Found.\n");
    if(lsearch_word(dat,s,n)!=-1)
        printf("Found at %d\n",lsearch_word(dat,s,n));
    else
        printf("Not Found.\n");

    printf("Binary Search\n");


    if(bsearch_int(dat,n1,n)!=-1)
        printf("Found at %d\n",bsearch_int(dat,n1,n));
    else
        printf("Not Found.\n");
    if(bsearch_float(dat,n2,n)!=-1)
        printf("Found at %d\n",bsearch_float(dat,n2,n));
    else
        printf("Not Found.\n");
    if(bsearch_word(dat,s,n)!=-1)
        printf("Found at %d\n",bsearch_word(dat,s,n));
    else
        printf("Not Found.\n");    
                            
}