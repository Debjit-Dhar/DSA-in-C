#include <stdio.h>
#include <math.h>
void main()
{
    long long int a;
    int n;
    printf("Enter number of consecutive achilles numbers to print.\n");
    scanf("%d",&n);
    for(a=1;n>0;n,a++)
     if(ispowerful(a)==1 && isperfectpower(a)!=1 && ispowerful(a+1)==1 && isperfectpower(a+1)!=1 )
     {printf("%lld and %lld\n",a,a+1);
      n--;
     }      
}
int isperfectpower(long long int n)
{
   if((long long int)sqrt(n)==n)
    return 1;
    else
    return 0;
}
int ispowerful(long long int n)
{
    for(long long int i=1;i<sqrt(n);i++)
    if(isprime(i)==1 && n%i==0 && n%(i*i)!=0)
     return 0;
    return 1;    
}
int isprime(long long int n)
{
    for(int i=2;i<=n/2;i++)
     if(n%i==0)
     return 0;
    return 1;
}