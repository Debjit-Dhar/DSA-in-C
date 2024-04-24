#include <stdio.h>
void*fact_iter(int n)
{
void *f;
long long int a=0,b=1,c=0;
for(int i=1;i<=n-2;i++)
{
c=a+b;
a=b;
b=c;
}
f=&c;
return f;
}
int fibonacci_recur(int n,int a,int b,int i)
{
if(i==n-2)
return a+b;
else
fibonacci_recur(n,b,a+b,i+1);
}
void main()
{

int n;
printf("Enter number.\n");
scanf("%d",&n);
if(*((int*)fact_iter(n))<0&& *((long int*)fact_iter(n))<0)
printf("long integer overflow convert to long long int %lld\n",*((long long int*)fact_iter(n)));
else if(*((int*)fact_iter(n))<0)
printf("integer overflow convert to long int %ld\n",*((long int*)fact_iter(n)));
else
printf("%d\n",*((int*)fact_iter(n)));
printf("Recur.\n");
printf("%d\n",fibonacci_recur(n,0,1,1));
}