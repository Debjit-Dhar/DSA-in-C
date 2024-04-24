#include <stdio.h>
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
    //BUBBLE SORT
    //for(i=n-1;i>0;i--)
    for(i=0;i<n;i++)
    {
        //for(j=0;j<i;j++)
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    //DISPLAY SORTED ARRAY.
    printf("Sorted Array.\n");
    for(i=0;i<n;i++)
     printf("%d\t",a[i]);
    printf("\n");    
}