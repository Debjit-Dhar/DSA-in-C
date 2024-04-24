#include <stdio.h>
void main()
{
    int n;
    printf("Number of known values.\n");
    scanf("%d",&n);
    double x[n+1],y[n+1],yint[n+1];
    int i,j,k;
    for(i=0;i<n+1;i++)
    { 
        printf("x%d=",i);
        scanf("%lf",&x[i]);
        printf("f(x%d)=",i);
        scanf("%lf",&y[i]);
    }
    double X;
    printf("Enter any real number in range [%lf,%lf]\n",x[0],x[n]);
    scanf("%lf",&X);
    double sum=0,p=1;
    for(i=0;i<=n;i++)
    {
        p=1;
        for(j=0;j<=n;j++)
        if(i!=j)
          p*=(X-x[j])/(x[i]-x[j]);
        sum+=y[i]*p;
    }
    printf("Calculated value= %lf\n",sum);
}