#include <stdio.h>
int fact(int );
void main()
{
    int n;
    printf("Enter number of values.\n");
    scanf("%d",&n);
    double x[n+1],y[n+1];
    int i,j,k;
    for(i=0;i<n+1;i++)
    {
        printf("Enter x%d\n",i);
        scanf("%lf",&x[i]);
        printf("Enter f(x%d)\n",i);
        scanf("%lf",&y[i]);
    }
    double X;
    printf("Enter X\n");
    scanf("%lf",&X);
    double u=(X-x[0])/(x[1]-x[0]);
    double del[n+1][n+1];
    for(i=0;i<n+1;i++)
     del[i][0]=(y[i+1]-y[i]);
    for(j=1;j<n+1;j++){
    for(i=1;i<n+1;i++)
     del[i][j]=del[i][j-1]-del[i-1][j-1];
    }
    printf("Forward Difference Table.\n");
    for(i=0;i<n;i++)
     {
        for(j=0;j<=i;j++)
         printf("%lf\t",del[i][j]);
        printf("\n");
     }  
    double sum=y[0],p=1;
    for(i=1;i<n+1;i++)
    {
        p=1;
        for(j=0;j<i;j++)
         p*=(u-j);
        sum+=p*(del[i-1][i-1]/fact(i)); 
    }
    printf("\n");
    printf("Value= %lf\n",sum);
}
int fact(int n)
{
    int p=1;
    for(int i=2;i<=n;i++)
     p*=i;
    return p;
}