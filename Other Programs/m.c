#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
void main()
{
    char s1[80];
    gets(s1);
    int a;
    if(isdigit(*s1))
     a=atoi(s1);
    char s2[80];
    sprintf(s2,"%d",a);
    printf("%d\n",a);
    printf("%s\n",s2);
}