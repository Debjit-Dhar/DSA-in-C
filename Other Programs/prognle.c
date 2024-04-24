#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double f(double);
double chord(double,double);
void main()
{
    int ch;
    double a,b,c,fa=1,fb=1,fc=1;
    printf("Enter choice 1 for bisection, 2 for regula falsi, 3 for Newton-Raphson.\n");
    scanf("%d",&ch);
    double er=0,ep=0;
    printf("Enter ep.\n");
    scanf("%lf",&ep);
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
        while(er>ep)
            {
            
            c=(a+b)/2;
            fc=f(c);
            if(fa*fc>0)
            a=c;
            else if(fa*fc<0)
            b=c;
            else
            {printf("Root= %lf\n",c); return;}
           ep=fc-0;
          }
        printf("Root =%lf\n",c);
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
        if(fa*fb>0)
        {
            printf("No real roots in given range.\n");
            return;
        }
        else
        {
            fc=5;
          while(fc>0.01)
          {
            int k=0;
           c=chord(a,b);
           fc=f(c);
           if(fc==0)
           {printf("Root =%.2lf\n",c); return;}
           a=c;
           if(k==100)
            {printf("Root =%.2lf\n",c);return;}
          k++;
          }
        }
        break;
        case 3:
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
double chord(double a,double b)
{
    return a+((a-b)*f(a))/(f(b)-f(a));
}