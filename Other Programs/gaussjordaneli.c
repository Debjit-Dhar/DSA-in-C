#include <stdio.h>
int main()
{
    int n;
    printf("Enter number of unknowns.\n");
    scanf("%d",&n);
    double a[n][n+1];
    int i,j,k,p;
    double f; 
    for(i=0;i<n;i++)
    {
       for(j=0;j<n+1;j++)
       {
           printf("Enter element.\n");
           scanf("%lf",&a[i][j]);
       }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
         printf("%lf\t",a[i][j]);
        printf("\n");
    }
    for(i=0;i<n;i++) 
    {
        j=i;
        while(a[i][i]==0&&j<n)
        {
            for(k=0;k<n+1;k++)
            {
                f=a[i][k];
                a[i][k]=a[j][k];
                a[j][k]=f;
            }
            j=j+1;
        }
        f=a[i][i];
        if(a[i][i]!=0)
        {
            for(k=i;k<n+1;k++)
             a[i][k]/=f;
        }
        for(k=0;k<n;k++)
        {
            if(k!=i)
            {
                f=a[k][i]/a[i][i];
                for(p=i;p<n+1;p++)
                 a[k][p]-=f*a[i][p];
            }
        }
    }
    printf("Reduced Row Echelon Form\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n+1;j++)
         printf("%lf\t",a[i][j]);
        printf("\n");
    }
    double x[n+1];
    for(i=0;i<n;i++)
     x[i+1]=a[i][n];
    for(i=1;i<=n;i++)
     printf("x%d =%lf\n",i,x[i]);
}