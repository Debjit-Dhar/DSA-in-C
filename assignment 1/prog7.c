#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int check(int n)
{
    if(n<2)
        return 0;
    for(int i=2;i<=n/2;i++)
    if(n%i==0)
        return 0;
    return 1;
}
void main()
{
    int p;
    int n;
    srand(time(NULL));
    printf("Enter the number of large integers.\n");
    scanf("%lld",&n);
    long long int a[2][n];
    int i=0;
    for(;i<n;i++)
        a[0][i]=rand()*rand();
    for(int j=1;j<=7;j++){
    printf("Enter a four digit prime no.\n");
    scanf("%d",&p);
    if(!check(p))
        return;
    for(i=0;i<n;i++)
        a[1][i]=a[0][i]%p;
    for(i=0;i<n;i++)
        printf("Large integer=%lld Remainder=%lld\n",a[0][i],a[1][i]);
    }
}