#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    char str[80];
    FILE* fp;
    if((fp=fopen("test","w+"))==NULL)
    {
        printf("Cannot open file.\n");
        exit(1);
    }
    do{
        gets(str);
        strcat(str,"\n");
        fputs(str,fp);
    }while(*str!='\n');
    rewind(fp);
    while(!feof(fp))
    {
        fgets(str,79,fp);
        printf(str);
    }
    return 0;
}