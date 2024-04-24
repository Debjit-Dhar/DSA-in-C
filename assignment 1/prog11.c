#include <stdio.h>
#include <string.h>
struct dict
{
    char s[100];
};
int iscontain(char s[],char str[])
{
    int i=0,c=0,n1=strlen(s),n2=strlen(str);
    char copy[100];
    strcpy(copy,str);
    for(;i<n1;i++)
    {
        for(int j=0;j<n2;j++)
        {
            if(s[i]==copy[j])
            {
                copy[j]='$';
                c++;
                break;
            }
        }
    }
    if(c==n1)
        return n2-n1;
    return -1;
}

void main()
{
    struct dict d[4];
    strcpy(d[0].s,"ale");
    strcpy(d[1].s,"apple");
    strcpy(d[2].s,"monkey");
    strcpy(d[3].s,"plea");
    char str[100];
    strcpy(str,"abpcplea");
    int check[4];
    int i;
    for(i=0;i<4;i++)
        check[i]=iscontain(d[i].s,str);
    int pos=0;
    for(i=1;i<4;i++)
        if(check[i]<check[pos]&&check[i]!=-1)
            pos=i;
    if(check[pos]==-1)
        printf("2");
    else
        printf("%s",d[pos].s);    
}