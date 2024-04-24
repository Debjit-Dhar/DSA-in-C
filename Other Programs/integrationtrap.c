#include <stdio.h>
int fact(int );
void main()
{
    int n;
    printf("Enter number of values.\n");
    scanf("%d",&n);
    double x[n+1],y[n+1];
    int i,j,k;
    for(i=0;i<n+1;i++)
    { 
        printf("Enter x%d\n",i);
        scanf("%lf",&x[i]);
        printf("Enter f(x%d)\n",i);
        scanf("%lf",&y[i]);
    }
    double a,b,fa,fb;
    printf("Enter infinum\n"); 
    scanf("%lf",&a);
    printf("Enter supremum\n");
    scanf("%lf",&b);
    int posi,posj;
    for(i=0;i<=n;i++)
     if(x[i]>=a)
      posi=i;
    for(i=n;i>=0;i--)
     if(x[i]<=b)
      posj=i;
    double X=a;  
    for(k=1;k<=2;k++){
     double u=(X-x[0])/(x[1]-x[0]);
    double del[n+1][n+1];
    for(i=0;i<n+1;i++)
     del[i][0]=(y[i+1]-y[i]);
    for(j=1;j<n+1;j++){
    for(i=1;i<n+1;i++)
     del[i][j]=del[i][j-1]-del[i-1][j-1];
    }
    double sum=y[0],p=1;
    for(i=1;i<n+1;i++)
    {
        p=1;
        for(j=0;j<i;j++)
         p*=(u-j);
        sum+=p*(del[i-1][i-1]/fact(i));
    }
    if(k==1)
     fa=sum;
     else
      fb=sum;
    X=b;
    }
    printf("Integration from %lf",a);
    a=x[posi];
    double sum1=0.5*(fa+y[posi])*(x[posi]-a);
    double h=x[1]-x[0];
    k=posi;
    for(;k<=posj;k++)
     sum1+=0.5*(y[k]+y[k+1])*h;
    sum1+=0.5*(fb+y[posj])*(b-x[posj]);
    printf(" to %lf= %lf\n",b,sum1);
}
int fact(int n)
{
    int p=1;
    for(int i=2;i<=n;i++)
     p*=i;
    return p;
}