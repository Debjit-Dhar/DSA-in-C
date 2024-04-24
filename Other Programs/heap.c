#include <stdio.h>
#include <stdlib.h>
void main()
{
    int n=4;
    int **a;
    for(int i=0;i<n;i++)
     a=malloc(n*sizeof(int *));//rows
    for(int i=0;i<n;i++)
     *(a+i)=malloc(n*sizeof(int));//columns
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
         {
            a[i][j]=i*i+j*j;
            printf("%d\t",a[i][j]);
         }
        printf("\n");
    }
}