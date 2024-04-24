#include<stdio.h>
#include<limits.h>
#include<float.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
int **mat()
 {
    int i,j,**a;
    int n;
    printf("Enter size\n");
    scanf("%d",&n);
    for(i=0;i<n;i++)
     a=(int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
     a[i]=(int *)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=i*i+j*j;
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    return a;
}
int main()
{
    mat();
    return 0;
}