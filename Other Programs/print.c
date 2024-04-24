#include <stdio.h>
int main()
{
    printf("%*.*f",10,4,123.37812);
    unsigned int a=1;
    char *b=(char*)&a;
    if(*b)
        printf("Little Endian.\n");
    else
        printf("Big Endian.\n");
    return 0;
}