#include <stdio.h>
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
    double x=x1,y=y1;
    while(x<=xf)
    {
        printf("At %lf =%lf\n",x,y);
        x=x1+h;
        y=y1+h*f(x1,y1);
        x1=x;
        y1=y;
    }
}
double f(double x,double y)
{
    return -x*y;
}