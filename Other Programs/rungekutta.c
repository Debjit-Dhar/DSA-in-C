#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f(double ,double );
void main()
{
    printf("Enter initial conditions.\n");
    double x1,y1;
    printf("Enter x1\n");
    scanf("%lf",&x1);
    printf("Enter y1\n"); 
    scanf("%lf",&y1);
    double h=0.05;
    int i;
    double xf;
    printf("Enter xf.\n");
    scanf("%lf",&xf);
    double x=x1,y=y1,k1,k2,k3,k4;
    int o;
    printf("Enter order of runge-kutta method 1,2,3,4\n");
    scanf("%d",&o);
  switch(o)
  {
    case 1:
    while(x<=xf)
    {
        printf("At %lf= %lf\n",x,y);
        k1=f(x1,y1);
        x=x1+h;
        y=y1+h*k1;
        x1=x;
        y1=y;
    }
    printf("=Euler\n");
    break;
    case 2:
    while(x<=xf)
    {
        printf("At %lf= %lf\n",x,y);
        k1=f(x1,y1);
        k2=f(x1+h,y1+k1*h);
        x=x1+h;
        y=y1+(h/2)*(k1+k2);
        x1=x;
        y1=y;
    }
    printf("=Heun\n");
    while(x<=xf)
    {
        printf("At %lf= %lf\n",x,y);
        k1=f(x1,y1);
        k2=f(x1+h/2,y1+0.5*k1*h);
        x=x1+h;
        y=y1+(h/2)*(k1+k2);
        x1=x;
        y1=y;
    }
    printf("=Midpoint\n");
    break;
    case 3:
    while(x<=xf)
    {
        printf("At %lf= %lf\n",x,y);
        k1=f(x1,y1);
        k2=f(x1+h/2,y1+0.5*k1*h);
        k3=f(x1+h,y1-k1*h+2*k2*h);
        x=x1+h;
        y=y1+(h/6)*(k1+4*k2+k3);
        x1=x;
        y1=y;
    }
    break;
    case 4:
    while(x<=xf)
    {               
        printf("At %lf= %lf\n",x,y);
        k1=f(x1,y1);
        k2=f(x1+h/2,y1+0.5*k1*h);
        k3=f(x1+h/2,y1+0.5*k2*h);
        k4=f(x1+h,y1+k3*h);
        x=x1+h;
        y=y1+(h/6)*(k1+2*k2+2*k3+k4);
        x1=x; 
        y1=y;               
    }
    break;
    default:
    printf("Invalid\n");
    exit(1);
  }
}
double f(double x,double y)
{
    return -x*y;
}