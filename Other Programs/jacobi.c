#include <stdio.h>
#include <stdlib.h>
#include <math.h>
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
    double x[n+1],x1[n+1],sum=0,temp,relerror;
    int iter,maxit=1000000,big;
    double e=1;
    for (i = 0;i<n ;i++)
     x[i] = 0;
    for (iter = 1;iter<=maxit;iter++);
    {  big = 0;
       for(i = 0;i<n;i++)
        { sum = 0;
           for (j = 0;j<=n;j++) 
              if (j != i) 
               sum = sum + a[i][j]*x[j];
          temp = (a[i][n + 1]-sum)/a[i][i];
          relerror =fabs((x[i]-temp)/temp);
          if (relerror > big)
            big = relerror;
         x1[i] = temp;
        }
      for(i = 0;i<n;i++)
        x[i] =x1[i];
      if (big <= e)
      {
        printf("Converges to a solution.\n");
        for(i=0;i<n+1;i++)
          printf("%lf\n",x[i]);
        exit(1);
      }
    }
    for(i=0;i<n+1;i++)
     printf("%lf\n",x1[i]);
    printf("Does not converge in %d iterations\n",maxit);
}