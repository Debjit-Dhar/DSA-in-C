#include <stdio.h>
#include <math.h>
void main()
{
    int n;
    printf("Enter number.\n");
    scanf("%d",&n);
    I(n,1);
}
void I(int n,int i)
{
   if(i==n+1)
    return;
    else
     {
        J(i,1);
        printf("\n");
        return I(n,i+1);
     }
}
void J(int i,int j)
{
    if(j==i+1)
     return;
     else
     {
        printf("%d\t",j);
        return J(i,j+1);
     }
}