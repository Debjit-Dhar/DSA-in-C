#include <stdio.h>
void main()
{
    int n;
    printf("Enter number of values.\n");
    scanf("%d",&n);
    double x[n+1],y[n+1];
    int i;
    for(i=0;i<n+1;i++)
    {
        printf("Enter x%d\n",i);
        scanf("%lf",&x[i]); 
        printf("Enter f(x%d)\n",i);
        scanf("%lf",&y[i]);
    }
    double sum=y[0]+y[n];
    double h=x[1]-x[0];
    for(i=1;i<n;i++)
        if(i%3==0)
         sum+=2*y[i]; 
         else
          sum+=3*y[i];
    sum*=3*(h/8);
    printf("Integration from %lf to %lf =%lf\n",x[0],x[n],sum);    
}