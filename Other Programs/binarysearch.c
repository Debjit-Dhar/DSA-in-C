#include <stdio.h>
void main()
{
    int n,i;
    printf("Enter size of the array.\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element no %d\n",i+1);
        scanf("%d",&a[i]);
    }
    int ele;
    printf("Enter element to be searched.\n");
    scanf("%d",&ele);
    qsort(a,0,n-1);
    printf("Sorted Array.\n");
    for(i=0;i<n;i++)
     printf("%d\t",a[i]);
    printf("\n");
    int low=0,high=n-1,mid=(low+high)/2,flag=0;
    while(low<high)
    {
        if(a[mid]>ele)
        high=mid-1;
        else if(a[mid]<ele)
         low=mid+1;
         else
         {
             printf("%d occurs at postion %d in the array.\n",ele,mid);
             flag=1;
             break;
         }
         mid=(low+high)/2;
    }
    if(flag==0)
     printf("%d does not exist in the array.\n",ele);
}
void qsort(int a[],int left,int right)
{
    int left1=left,right1=right,pivot=a[left];
    while(left<right)
    {
        while((a[right]>=pivot)&&(left<right))
         right--;
        if(left!=right)
        {
            a[left]=a[right];
            left++;
        }
        while((a[left]<=pivot)&&(left<right))
         left++;
        if(left!=right)
        {
            a[right]=a[left];
            right--;
        }
    }
    a[left]=pivot;
    pivot=left;
    left=left1;
    right=right1;
    if(left<pivot)
     qsort(a,left,pivot+1);
    if(left>pivot)
     qsort(a,pivot-1,right);
}