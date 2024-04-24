#include <stdio.h>
#include <math.h>
#define e 0.00001
double f(double);
void main()
{
    double a,b,c,fa,fb,fc=1;
    printf("Enter infinum\n");
    scanf("%lf",&a);
    printf("Enter supremum\n");
    scanf("%lf",&b);
    int co=0;
    while(fc!=0)
    {
        co++;
        fa=f(a);
        fb=f(b);
        c=(a+b)/2;
        fc=f(c);
        if(fa*fc<0)
         b=c;
        if(fb*fc<0)
         a=c;
        if(fabs(fc)<e)
        {
            printf("Root =%.4lf\n",c);
            printf("No of iterations= %d\n",co);
            return;
        }
    }
}
double f(double x)
{
    return pow(x,4)-pow(x,3)-2*pow(x,2)-6*x-1;
}