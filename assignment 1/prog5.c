#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int iscontain(int a[],int len,int n)
{
    for(int j=0;j<len;j++)
        if(a[j]==n)
            return 1;
    return 0;        
}
void main()
{
    FILE*fp;
    fp=fopen("Strings.txt","w");
    int a[10];
    char s[11];
    srand(time(NULL));
    int n=2,len=10,num;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<10;j++){
        do{
            num=65+rand()%26;
        }while(iscontain(a,j,num));
        a[j]=num;
        s[j]=(char)a[j];
        }
        fputs(s,fp);
        if(i!=n)
            fputc('\n',fp);
    }
    fclose(fp);
}