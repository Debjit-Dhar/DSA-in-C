#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int cd(int n)
{
    int c=0;
    while(n>0)
    {
        c++;
        n/=10;
    }
    return c;
}
int z(int n)
{
    int c=0;
    while(n>0)
    {
        if(n%10==0)
            c++;
        n/=10;
    }
    return c;
}
int iscontain(int a[],int len,int n)
{
    for(int j=0;j<len;j++)
        if(a[j]==n)
            return 1;
    return 0;        
}
void main()
{
    int MAX=11;
    srand(time(NULL));
    int i=0,n,a[MAX];
    for(;i<MAX;i++)
    {
        do
        {
            n=rand()%MAX+1;
        }while(iscontain(a,i,n)==1); 
        a[i]=n; 
    }
    for(i=0;i<MAX;i++)
        printf("%d ",a[i]);
    FILE*fp;
    fp=fopen("Dat.txt","w+");
    if(!fp)
    {
        printf("File cannot open.\n");
        return;
    }
    for(i=0;i<MAX;i++)
    {
        int c=cd(a[i]),p=pow(10,c-1),zero=z(a[i]);
        while(a[i]!=0)
        {
            char ch=(char)(a[i]/p+48);
            fflush(stdin);
            fputc(ch,fp);
            a[i]%=p;
            p/=10;                
        }
        for(int j=1;j<=zero;j++)
        {
            char ch='0';
            fflush(stdin);
            fputc(ch,fp);
        }
        if(i!=MAX-1)
            fputc('\n',fp);
    }
    fclose(fp);
}