#include <stdio.h>
#define balance float
#define WIN__INSPIRON_15__3000akawin10apache1
int main()
{
    #ifdef WIN__INSPIRON_15__3000akawin10apache1
    printf("Windows\n");
    #elif LINUX
    printf("Linux\n");
   #elif MAC
   printf("MAC\n");
    #endif
    balance a=2.5;
    return 0;
}