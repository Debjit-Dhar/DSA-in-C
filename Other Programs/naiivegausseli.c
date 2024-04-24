#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n;
    printf("Enter no. of unknowns.\n");
    scanf("%d",&n);
    int i,j,k;
    double a[n][n+1],u=0;
    //ACCEPT
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        { 
            printf("Enter\n");
            scanf("%lf",&a[i][j]);
        }
    }
    //PRINT 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
        printf("%lf\t",a[i][j]);
        printf("\n");
    }
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
    double x[n+1];
    x[n]=a[n-1][n]/a[n-1][n-1];
    for(i=n-2;i>=0;i--)
    {
        u=a[i][n];
        for(j=n-1;j>i;j--)
        u-=a[i][j]*x[j+1];
        x[i+1]=u/a[i][j];
    }
    for(i=1;i<n+1;i++)
    printf("x%d= %lf\n",i,x[i]);
}