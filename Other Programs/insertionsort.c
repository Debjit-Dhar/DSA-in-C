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
    //INSERTION SORT
    for(i=1;i<n;i++)
        {
            int temp=a[i];
            for(j=i-1;j>=0&&temp<a[j];j--)
             a[j+1]=a[j];
             a[j+1]=temp;
        }
    //DISPLAY SORTED ARRAY.
    printf("Sorted Array.\n");
    for(i=0;i<n;i++)
     printf("%d\t",a[i]);
    printf("\n");    
}