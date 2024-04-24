#include <stdio.h>
int max(int l,int r,int a[])
{
    if(l==r)
        return a[l];
    else{
        int m=(l+r)/2;
        int max_left=max(l,m,a);
        int max_right=max(m+1,r,a);
        return max_left>max_right?max_left:max_right;
    }
}
int main()
{
    int n=7;
    int a[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter number.\n");
        scanf("%d",&a[i]);
    }
    printf("Maximum is= %d\n",max(0,n-1,a));
}