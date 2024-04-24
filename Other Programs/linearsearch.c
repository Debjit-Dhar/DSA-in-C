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
    int flag=0;
    for(i=0;i<n;i++)
        if(a[i]==ele)        
        {
            printf("%d occurs at position %d in the array.\n",ele,i);
            flag=1;
        }
    if(flag==0)
     printf("%d does not exist in the array.\n",ele);
}