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
    printf("Enter choice 1 for bisection,2 for Newton-Raphson.\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
       for(int i=1;i<=3;i++){
            printf("Enter lower limit.\n");
        scanf("%lf",&a);
        printf("Enter upper limit.\n");
        scanf("%lf",&b);
        fa=f(a),fb=f(b);
        printf("Using Bisection Method.\n");
        if(fa==0)
        {printf("Root =%.2lf\n",a);break;}
        if(fb==0)
        {printf("Root =%.2lf\n",b);break;}
        for(;;)
            {
            
            c=(a+b)/2;
            fc=f(c);
            if(fa*fc>0)
            a=c;
            else if(fa*fc<0)
            b=c;
            else
            {printf("Root= %lf\n",c); break;}
            if(fabs(fc)<0.000001)
            {printf("Root= %lf\n",c); break;}
          }}
        break;
       case 2:
       for(int i=1;i<=3;i++){
        printf("Using Newton-Raphson Method.\n");
        printf("Enter assumed root.\n");
        scanf("%lf",&a);
        fa=f(a);
        if(fa==0)
        {printf("Root =%.2lf\n",a);break;}
        for(;;)
        {
            c=diff(a);
            a=c;
            fc=f(c);
            if(fabs(fc)<0.000001)
            {printf("Root =%lf\n",c);break;}
        }
       }
        break;
        default:
        printf("Invalid Input.\n");
    }
}
double f(double x)
{
    //return pow(x,3)-3*pow(x,2)+3*x-1;
    return x*tan(x);
}
double fdiff(double x)
{
    //return 3*pow(x,2)-6*x+3;
    return tan(x)-x*pow(1/cos(x),2);
}
double chord(double a,double b)
{
    return a+((a-b)*f(a))/(f(b)-f(a));
}
double diff(double a)
{
    return a-f(a)/fdiff(a);
}
