#include <stdio.h>
#include <string.h>
#include <ctype.h>
void main()
{
    char a[]="Debjit",b[]="maDam";
    if(strcspn(a,b)>(strlen(a)-1))
     printf("Not Contained\n");
     else
      printf("Contained.\n");
}