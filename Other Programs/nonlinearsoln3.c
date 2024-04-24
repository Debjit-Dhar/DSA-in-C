#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double f(double);
double fdiff(double);
double diff(double);
void main()
{
    double a,fa,c,fc;
   for(int i=1;i<=3;i++)
   {
     printf("Enter assumed root\n");
     scanf("%lf",&a);
     fa=f(a);
     if(fa==0)
      {printf("Root =%lf\n",a);break;}
     for(;;)
     {
            c=diff(a);
            a=c;
            fc=f(c);
            if(fabs(fc)<0.000001)
            {printf("Root =%lf\n",c);break;}        
     }
   }
}
double f(double x)
{
    return pow(x,3)-2.5*pow(x,2)-2.46*x+3.96;
}
double fdiff(double x)
{
    return 3*pow(x,2)-5*x-2.46;    
}
double diff(double a)
{
    return a-f(a)/fdiff(a);
}