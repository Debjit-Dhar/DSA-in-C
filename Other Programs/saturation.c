//METHOD OF LEAST SQUARES
#include <stdio.h>
#include <math.h>
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
    double s1=0,s2=0,s3=0,s4=0; 
    for(i=1;i<=n;i++)
    {
        s1+=1/y[i];
        s2+=1/x[i];
        s3+=(1/x[i])*(1/x[i]);
        s4+=(1/x[i])*(1/y[i]);
    }
    a0=((s1*s3)-(s2*s4))/((n*s3)-(s2*s2));
    a1=((n*s4)-(s2*s1))/((n*s3)-(s2*s2));
    printf("Saturation curve is y= %lfx/(%lf+x)\n",1/a0,a1/a0);
}