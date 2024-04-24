#include <stdio.h>
void main()
{
    int n;
    printf("Enter the number of cuts.\n");
    scanf("%d",&n);
    printf("Number of pieces =%d\n",(n*n+n+2)/2);
}