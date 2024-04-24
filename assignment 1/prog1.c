#include <stdio.h>
void*fact_iter(int n)
{
void *f;
long long int fact=1;
for(int i=1;i<=n;i++)
fact*=i;
f=&fact;
return f;
}
void *fact_recur(int n)
{
void*f;
long long int fact=1;
if(n==1)
{
f=&fact;
return f;
}
else
f=&fact;
fact=n*(*((long long int*)fact_recur(n-1)));
return f;
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
if(*((int*)fact_recur(n))<0&& *((long int*)fact_recur(n))<0)
printf("long integer overflow convert to long long int %lld\n",*((long long int*)fact_recur(n)));
else if(*((int*)fact_recur(n))<0)
printf("integer overflow convert to long int %ld\n",*((long int*)fact_recur(n)));
else
printf("%d\n",*((int*)fact_recur(n)));
}