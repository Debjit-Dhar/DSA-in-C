#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#define String const char*
#define Systemoutprint printf
#define true 1
#define false 0
void main()
{
    String s="Debjit Dhar";    
    Systemoutprint("%s\n",s);
    if(true)
    {
        Systemoutprint("Correct\n");
    }
    else{
        Systemoutprint("Incorrect\n");
    }
    printf("%d\n",sizeof(void*));
}
