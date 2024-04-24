#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double f(double);
double fdiff(double);
double chord(double,double);
double diff(double);
void main()
{
    int ch;
    double a,b,c,fa=1,fb=1,fc=1;
    printf("Enter choice 1 for bisection, 2 for regula falsi, 3 for Newton-Raphson.\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        printf("Using Bisection Method.\n");
        printf("Enter lower limit.\n");
        scanf("%lf",&a);
        printf("Enter upper limit.\n");
        scanf("%lf",&b);
        fa=f(a),fb=f(b);
        if(fa==0)
        {printf("Root =%.2lf\n",a);return;}
        if(fb==0)
        {printf("Root =%.2lf\n",b);return;}
        for(;;)
            {
            
            c=(a+b)/2;
            fc=f(c);
            if(fa*fc>0)
            a=c;
            else if(fa*fc<0)
            b=c;
            else
            {printf("Root= %lf\n",c); return;}
            if(fabs(fc)<0.000001)
            {printf("Root= %lf\n",c); return;}
          }
        break;
        case 2:
        printf("Using Regula Falsi Method.\n");
        printf("Enter lower limit.\n");
        scanf("%lf",&a);
        printf("Enter upper limit.\n");
        scanf("%lf",&b);
        fa=f(a);
        fb=f(b);
        if(fa==0)
        {printf("Root =%.2lf\n",a);return;}
        if(fb==0)
        {printf("Root =%.2lf\n",b);return;}
        for(;;)
        {
            c=chord(a,b);
            fc=f(c);
            if(fa*fc>0)
            a=c;
            else if(fb*fc>0)
            b=c;
            if(fabs(fc)<0.000001)
            {printf("Root =%lf\n",c);return;}
        }
        break;
        case 3:
        printf("Using Newton-Raphson Method.\n");
        printf("Enter assumed root.\n");
        scanf("%lf",&a);
        fa=f(a);
        if(fa==0)
        {printf("Root =%.2lf\n",a);return;}
        for(;;)
        {
            c=diff(a);
            a=c;
            fc=f(c);
            if(fabs(fc)<0.000001)
            {printf("Root =%lf\n",c);return;}
        }
        break;
        default:
        printf("Invalid Input.\n");
    }
}
double f(double x)
{
    return pow(x,3)-3*pow(x,2)+3*x-1;
    //return x*tan(x);
}
double fdiff(double x)
{
    return 3*pow(x,2)-6*x+3;
    //return tan(x)-x*pow(sec(x),2);
}
double chord(double a,double b)
{
    return a+((a-b)*f(a))/(f(b)-f(a));
}
double diff(double a)
{
    return a-f(a)/fdiff(a);
}
