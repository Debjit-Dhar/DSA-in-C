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
    //SELECTION SORT
    for(i=0;i<n;i++)
    {
        int small=a[i],pos=i;
        for(j=i+1;j<n;j++) 
         if(small>a[j])
          {small=a[j];pos=j;}
        a[pos]=a[i];
        a[i]=small;
    }
    //DISPLAY SORTED ARRAY.
    printf("Sorted Array.\n");
    for(i=0;i<n;i++)
     printf("%d\t",a[i]);
    printf("\n");    
}