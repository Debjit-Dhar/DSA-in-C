#include <stdio.h>
#include <stdlib.h>
void main()
{
    int a[3]={2,1,3};
    FILE*fp;
    fp=fopen("Data.txt","w");
    char ch;
    for(int i=0;i<3;i++)
    {
        ch=(char)(a[i]+48);
        printf("%c",ch);
        fflush(stdin);
        fputc(ch,fp);
        fflush(stdin);
        fputc('\n',fp);
    }
    fclose(fp);
}