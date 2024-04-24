#include<stdio.h>
#include<stdarg.h>
int max(int num, ...)
{
   int i, temp, m;
   va_list args;
   va_start(args, num);
   m=va_arg(args, int);
   for(i=2;i<=num;i++)
   {
     temp=va_arg(args, int);
     if(m<temp)
      m=temp;
   }
   return(m);
}
int main()
{
   printf("Max = %d\n", max(4, 23, 56, 89, 29));
   return 0;
}
