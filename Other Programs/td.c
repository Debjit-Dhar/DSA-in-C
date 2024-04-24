#include <stdio.h>
#include <conio.h>
int main()
{
    char ch[12];
    fflush(stdin);
    fgets(ch,12,stdin);
    printf("%s\n",ch);
    return 0;
}