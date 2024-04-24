//METHOD OF LEAST SQUARES
#include <stdio.h>
#include <math.h>
#define w 1
void main()
{
    int n;
    printf("Enter number of values.\n");
    scanf("%d",&n);
    double x[n+1],y[n+1];
    int i;
    //Accept the points.
    for(i=1;i<=n;i++)
    {
        printf("Enter x%d\n",i);
        scanf("%lf",&x[i]);
        printf("Enter y%d\n",i);
        scanf("%lf",&y[i]); 
    }
    printf("x\ty\n");
    //Display the points
    for(i=1;i<=n;i++)
      printf("%lf\t%lf\n",x[i],y[i]);
    double a0,a1;
    double s1=0,s2=0,s3=0,s4=0,s5=0; 
    for(i=1;i<=n;i++)
    {
        s1+=y[i]*sin(w*x[i]);
        s2+=sin(w*x[i])*cos(w*x[i]);
        s3+=pow(cos(w*x[i]),2);
        s4+=y[i]*cos(w*x[i]);
        s5+=pow(sin(w*x[i]),2);
    }
    a0=((s1*s3)-(s2*s4))/((s5*s3)-(s2*s2));
    a1=((s5*s4)-(s2*s1))/((s5*s3)-(s2*s2));
    printf("Trigonometric curve is y= %lfsin(%lfx+%lf)\n",sqrt(a0*a0+a1*a1),w,atan(a1/a0));
}