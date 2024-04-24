#include <stdio.h>
int max(int a[],int l,int r)
{
    if(l==r)
        return a[l];
    else
    {
        int m=(l+r)/2;
        int left=max(a,l,m);
        int right=max(a,m+1,r);
        return left>right?left:right;
    }
}

int main()
{
    int a[6]={5,3,2,1,3,4,};
    int n=6;
    printf("%d\n",max(a,0,n-1));
    return 0;
}