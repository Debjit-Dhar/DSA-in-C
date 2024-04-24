#include <stdio.h>
void main()
{
    int n;
    printf("Enter the number of dimensions.\n");
    scanf("%d",&n);
    int i=1,dim[n+1];
    for(i=1;i<=n;i++)
    {
        printf("Enter the %d th dimension.\n",i);
        scanf("%d",&dim[i]);
    }
    long long int a; 
    printf("Enter base address.\n");
    scanf("%lld",&a);
    long long int p=1;
    int I[n+1];
    for(i=1;i<=n;i++)
    {
        printf("Enter %d th index.\n",i);
        scanf("%d",&I[i]);
    }
    for(i=1;i<=n;i++)
    {
        p=1;
        for(int j=i+1;j<=n;j++)
         p*=dim[j];
        a+=p*I[i];
    }
    printf("Row major address =%lld\n",a);
}