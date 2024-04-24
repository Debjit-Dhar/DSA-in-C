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
    int exchange;
    do{
        exchange=0;
        for(i=n-1;i>0;i--)
        {
            if(a[i-1]>a[i])
            {
                int t=a[i-1];
                a[i-1]=a[i];
                a[i]=t;
                exchange =1;
            }
        }
      for(i=1;i<n;i++)
      {
         if(a[i-1]>a[i])
         {
             int t=a[i-1];
             a[i-1]=a[i];
             a[i]=t;
             exchange=1;
         }
      }
    }while(exchange);
    //DISPLAY SORTED ARRAY.
    printf("Sorted Array.\n");
    for(i=0;i<n;i++)
     printf("%d\t",a[i]);
    printf("\n"); 
}