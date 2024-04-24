#include <stdio.h>
void main()
{
    int n;
    printf("Enter a number.\n");
    scanf("%d",&n);
    if(fiscomposite(n)==1&&fdig(n)%2==0)
    {
        int i,j,c=0;
        for(i=10;i<=n;i++)
        {
            for(j=10;j<=n;j++)
            {
                if(fdig(i)%2==0 && fdig(j)%2==0 && fdig(i)+fdig(j)==fdig(n))
                 //Write;
            }
        }
    }
}