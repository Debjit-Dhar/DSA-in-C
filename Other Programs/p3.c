#include <stdio.h>
#include <stdlib.h>
void main()
{
    char *p;
    p=malloc(1000);
    if(!p)
    {
        printf("Heap Space is out of memory");
        exit(1);
    }
    printf("Enter string.\n");
    gets(p);
    printf("The string entered is =%s\n",p);
    free(p);
}