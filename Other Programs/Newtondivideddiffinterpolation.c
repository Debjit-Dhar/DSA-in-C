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
    double xi;
    printf("Enter any real number in range [%lf,%lf]\n",x[0],x[n]);
    scanf("%lf",&xi);
    double fdd[n+1][n+1];//to store the divided differences
    for(i=0;i<=n;i++)
     fdd[i][0]=y[i];
    for(j=1;j<=n;j++) 
    {
        for(i=0;i<=n-j;i++)
        fdd[i][j]=(fdd[i+1][j-1]-fdd[i][j-1])/(x[i+j]-x[i]);
    }
    printf("Divided Difference Table is:\n");
     for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        if(i>n-j)
         printf("\t");
         else
          printf("%lf\t",fdd[i][j]);
        printf("\n");
    }
    int xterm=1;
    yint[0]=fdd[0][0];
    for(int order=1;order<=n;order++)
     {
        xterm=xterm*(xi-x[order-1]);
        yint[order]=yint[order-1]+fdd[0][order]*xterm;
     }
    printf("Computed value of xi is=\n");
    printf("%lf\n",yint[n]);
}