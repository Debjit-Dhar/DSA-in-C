#include <stdio.h>
void sort(int a[],int left,int right)
    {
        int left1=left;
        int right1=right;
        int pivot=a[left];
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
          sort(a,left,pivot-1);
        if(right>pivot)
          sort(a,pivot+1,right);
    }
void main()
{
    int n,i,j;
    printf("Enter size of the array.\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element no %d\n",i+1);
        scanf("%d",&a[i]);
    }
    printf("Original Array.\n");
    for(i=0;i<n;i++)
     printf("%d\t",a[i]);
    printf("\n");
    //QUICK SORT
    sort(a,0,n-1);
    //DISPLAY SORTED ARRAY. 
    printf("Sorted Array.\n");
    for(i=0;i<n;i++)
     printf("%d\t",a[i]);
    printf("\n");    
}
