#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of matrix.\n");
    scanf("%d",&n);
    double a[n][2*n];
    int i,j,k,p;
    double f; 
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
           printf("Enter element.\n");
           scanf("%lf",&a[i][j]);
       }
    }
    for(i=0;i<n;i++)
    {
        for(j=n;j<2*n;j++)
         if(i+n==j)
          a[i][j]=1;
          else
          a[i][j]=0;
    }
    for(i=0;i<n;i++)
    {
        j=i;
        while(a[i][i]==0&&j<n)
        {
            for(k=0;k<n*2;k++)
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
            for(k=i;k<n*2;k++)
             a[i][k]/=f;
        }
        for(k=0;k<n;k++)
        {
            if(k!=i)
            {
                if(a[i][i]==0)
                 {printf("Singular Matrix\n");return 0;}
                f=a[k][i]/a[i][i];
                for(p=i;p<n*2;p++)
                 a[k][p]-=f*a[i][p];
            }
        }
    }
    printf("Inverse of given matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=n;j<n*2;j++)
         printf("%lf\t",a[i][j]);
        printf("\n");
    }
    return 0;
}