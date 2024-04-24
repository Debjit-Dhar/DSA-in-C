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
    double u=(X-x[n])/(x[n]-x[n-1]);
    double idel[n+1][n+1];
    for(i=n;i>=0;i--)
     idel[i][0]=y[i]-y[i-1];
    for(j=1;j<n;j++){
    for(i=n;i>=1;i--)
     idel[i-j][j]=idel[i-j+1][j-1]-idel[i-j][j-1];
    }
    printf("Backward Difference Table:\n");
    for(i=1;i<n+1;i++)
    {
        for(j=0;j<=n-i;j++)
         printf("%lf\t",idel[i][j]);
        printf("\n");
    }
    double sum=y[n],p=1; 
    for(i=n;i>0;i--)
    {
        p=1;
        for(j=0;j<=n-i;j++)
         p*=(u+j);
        sum+=p*(idel[i][n-i]/fact(n-i+1));
    }
    printf("Value =%lf\n",sum);
}
int fact(int n)
{
    int p=1;
    for(int i=2;i<=n;i++)
     p*=i;
    return p;
}