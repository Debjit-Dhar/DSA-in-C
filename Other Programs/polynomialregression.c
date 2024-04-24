//METHOD OF LEAST SQUARES
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void main()
{
    int n;
    printf("Enter number of values.\n");
    scanf("%d",&n);
    double x[n+1],y[n+1];
    int i;
    //Accept the points. 
    for(i=1;i<=n;i++)
    {
        printf("Enter x%d\n",i);
        scanf("%lf",&x[i]);
        printf("Enter y%d\n",i);
        scanf("%lf",&y[i]); 
    }
    printf("x\ty\n");
    //Display the points
    for(i=1;i<=n;i++)
      printf("%lf\t%lf\n",x[i],y[i]);
    int N;
    printf("Enter degree of the polynomial\n");
    scanf("%d",&N);
    double a[N+1][N+2];
    a[0][0]=n;
    int j,k;
    for(i=0;i<N+1;i++)
    {
      for(j=1;j<N+1;j++)
      {
        a[i][j]=0;
        for(k=1;k<=n;k++)
         a[i][j]+=pow(x[k],j+i);        
      }
    }
    for(i=1;i<N+1;i++)
    {
      a[i][0]=0;
      for(k=1;k<=n;k++)
       a[i][0]+=pow(x[k],i);
    }
    for(i=0;i<N+1;i++)
    {
      a[i][N+1]=0;
      for(k=1;k<=n;k++)
       a[i][N+1]+=y[k]*pow(x[k],i);
    }
    for(i=0;i<N+1;i++)
    {
      for(j=0;j<N+2;j++)
       printf("%lf\t",a[i][j]);
      printf("\n");
    }
    double u;
    n=N+1;
    printf("Triangular Matrix.\n");
    //TRIANGULIZE
   for(k=0;k<n;k++)
   {
    for(j=k+1;j<n;j++)
    {
        u=a[j][k]/a[k][k];
        for(i=k;i<n+1;i++)
        a[j][i]=a[j][i]-u*a[k][i];
    }
   }
     //PRINT 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        printf("%lf\t",a[i][j]);
        printf("\n");
    }
    int flag=0;
    for(j=0;j<n;j++)
    {
        if(a[n-1][j]!=0)
        {flag=1;break;}
    }
    if(flag==0)
    {
        if(a[n-1][n]==0)
        {printf("Infinite many solutions.\n");
        exit(0);}
        else 
        {printf("No solutions.\n");
        exit(0);}
    }
    //BACK SUBSTITUTE
    double X[n+1];
    X[n]=a[n-1][n]/a[n-1][n-1];
    for(i=n-2;i>=0;i--)
    {
        u=a[i][n];
        for(j=n-1;j>i;j--)
        u-=a[i][j]*X[j+1];
        X[i+1]=u/a[i][j];
    }
    printf("Polynomial of Regression of degree %d is y=",N);
    for(i=1;i<n+1;i++)
     printf(" +%lfx^%d ",X[i],i-1);
}