#include <stdio.h>
int sod(int n)
{
    int s=0;
    for(int i=1;i<=n/2;i++)
     if(n%i==0)
      s+=i;
    return s;
}
void conchar(int n)
{
    char a[100];
    int i=0;
    while(n>0)
    {
        a[i]=(char)(n%10+97);
        i+=1;
        n/=10;
    }
    for(n=i-1;n>=0;n--)
     printf("%c",a[n]);
}
void main()
{
    printf("Enter number.\n");
    int n;
    scanf("%d",&n);
    if(n>0)
    {
        if(sod(n)==n)
        {
            printf("Perfect.\n");
            conchar(n);
        }
        else
         printf("Imperfect.\n");
    }
    else
     printf("Invalid Input.\n");
}