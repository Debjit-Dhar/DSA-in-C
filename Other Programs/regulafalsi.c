#include <stdio.h>
#include <math.h>
#define e 0.0000001
double f(double);
double fchord(double,double);
void main()
{
    double a,b,c,fa,fb,fc=1;
    printf("Enter infinum\n");
    scanf("%lf",&a);
    printf("Enter supremum\n");
    scanf("%lf",&b);
    while(fc!=0)
    {
        fa=f(a);
        fb=f(b);
        c=fchord(a,b);
        fc=f(c);
        if(fa*fc<0)
         b=c;
        if(fb*fc<0)
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
    return log(x);
}
double fchord(double a,double b)
{
    double c=a-f(a)*(b-a)/(f(b)-f(a));
    return c;
}