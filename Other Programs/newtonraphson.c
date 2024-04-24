#include <stdio.h>
#include <math.h>
#define e 0.0000001
double f(double);
double fdiff(double);
double fd(double);
void main()
{
    double a,c,fa,fc=1;
    printf("Enter intial guess\n");
    scanf("%lf",&a);
    while(fc!=0)
    {
        printf("fc=%lf\n",fc);
        fa=f(a);
        c=fd(a);
        fc=f(c);
        a=c;
        if(fabs(fc)<e)
        {
            printf("Root =%lf\n",c);
            return;
        }
    }
}
double f(double x)
{
    return x*x;
}
double fdiff(double x)
{
    return 2*x;
}
double fd(double a)
{
    double c=a-f(a)/fdiff(a);
    return c;
}