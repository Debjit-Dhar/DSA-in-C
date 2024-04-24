#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n;
    printf("Enter size of matrix.\n");
    scanf("%d",&n);
    int i,j,k,f=0;
    double a[n][n],b[n][n],u=0;
    //b is identity matrix which will later store the inverse.
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        if(i==j)
        b[i][j]=1;
        else
        b[i][j]=0;
    }
    //ACCEPT
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter\n");
            scanf("%lf",&a[i][j]);
        }
    }
    //PRINT 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%lf\t",a[i][j]);
        printf("\n");
    }
    //REDUCED ROW ECHELON FORM
    for(i=0;i<n;i++)
    {
        j=i;
        while(a[i][i]==0 && j<n)
        {
            for(k=0;k<n;k++)
            {
                double t=a[i][k];
                a[i][k]=a[j][k];
                a[j][k]=t;
                t=b[i][k];
                b[i][k]=b[j][k];
                b[j][k]=t;
            }
            j+=1;
        }
        f=a[i][i];
        for(k=i;k<n;k++)
        {if(f==0)break;
        a[i][k]/=f;
        b[i][k]/=f;}
        for(k=0;k<n;k++)
        {
            if(k!=i)
            {
                if(a[i][i]==0)
                {
                    printf("Singular Matrix.\n");
                    exit(0);
                }
                f=a[k][i]/a[i][i];
                for(int p=i;p<n;p++)
                {a[k][p]-=f*a[i][p];b[k][p]-=f*b[i][p];}
            }
        }
    }
    printf("Reduced Row Echelon form is:\n");
    //PRINT 
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%lf\t",a[i][j]);
        printf("\n");
    }
    int flag=0;
    for(j=0;j<n;j++)
    {
        if(a[n-1][j]!=0)
       {
          flag=1;
          break;
       }
    }
    if(flag==0)
     printf("Singular Matrix.\n");
    //Print b i.e the inverse of given matrix.
    printf("Inverse of given matrix is:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
         printf("%lf\t",b[i][j]);
        printf("\n");
    }
}