// Online C compiler to run C program online
//FADDEV-LEVERRIER METHOD TO FIND THE EIGEN VALUE OF A MATRIX
#include <stdio.h>
#include <math.h>
double trace(int n,double a[n][n])
{
    double sum=0;
    for(int i=0;i<n;i++)
     sum+=a[i][i];
    return sum;
}
double f(int n,double x,double p[n+1])
{
   double sum=pow(x,n);
   for(int i=1;i<=n;i++)
    sum+=-pow(x,n-i)*p[i];
   return x;
}
void main()
{
   int n;
   printf("Enter size\n");
   scanf("%d",&n);
   int i,j,k;
   double a[n][n],b[n][n],c[n][n];
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
       {
          printf("Enter\n");
          scanf("%lf",&a[i][j]);
       }
   }
   for(i=0;i<n;i++)
   {
      for(j=0;j<n;j++)
        printf("%lf\t",a[i][j]);
      printf("\n");
   }
   for(i=0;i<n;i++)
      for(j=0;j<n;j++)
       b[i][j]=a[i][j];   
   double p[n+1];
   for(i=1;i<=n;i++)
   {
      p[i]=trace(n,b);
      for(j=0;j<n;j++)            
       b[j][j]-=p[i];
      for (int I = 0; I < n; I++) {
        for (int J = 0; J < n; J++) {
            c[I][J] = 0;
            for (int K = 0; K< n; K++) {
                c[I][J] += a[I][K] * b[K][J];
            }
        }
      }
      for(j=0;j<n;j++)
      {
         for(k=0;k<n;k++)
          b[j][k]=c[j][k];
      }
   }
   printf("x^%d",n);
   for(i=1;i<=n;i++)
   printf("-%lfx^%d\t",p[i],n-i);
   printf("\n");
   double A,B,C,fa,fb,fc=1;
   printf("Enter lower limit.\n");
   scanf("%lf",&A);
   printf("Enter upper limit.\n");
   scanf("%lf",&B);
   fa=f(n,A,p),fb=f(n,B,p);
   if(fa==0)
    {printf("Root =%.2lf\n",a);return;}
   if(fb==0)
    {printf("Root =%.2lf\n",b);return;}
   while(fc!=0)
   {         
      printf("fc=%lf\n",fc);
      C=(A+B)/2;
      fc=f(n,C,p);
      if(fa*fc<0)
        B=C;
      if(fb*fc<0)
        A=C;
      if(fabs(fc)<0.000001)
       {printf("Eigen value= %lf\n",C); return;}
   }
   printf("Eigen value =%lf\n",C);return ;
}