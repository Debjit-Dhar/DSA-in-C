#include <stdio.h>
void main()
{
     int a=2;
    double b=3.5;
    char c='y';
    void*arr[3];
    arr[0]=&a;
    arr[1]=&b;
    arr[2]=&c;
    int *d=arr[0];
    double *e=arr[1];
    char *f=arr[2];
    printf("%d\n",*d);
    printf("%lf\n",*e);
    printf("%c\n",*f);
}