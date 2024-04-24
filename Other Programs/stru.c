#include <stdio.h>
void main()
{
    struct s1{//structure of array
        int a[5];
    }arr1,arr2;
    for(int i=0;i<5;i++)
   arr1.a[i]=i;
   arr2=arr1;
   struct s1 *p=&arr2;
   for(int i=0;i<5;i++)
   printf("%d\n",p->a[i]);
   printf("%d\n",sizeof(arr1));
   struct s1 A[100];//array of structure
   struct s2{//structure of structure
    struct s1 arr1;
   }arr3;
   unsigned int i = 1;
   char *c = (char*)&i;
   if (*c)
     printf("Little endian");
   else
     printf("Big endian");
}