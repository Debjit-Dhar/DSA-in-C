#include <stdio.h>
#include <time.h>
int generate()
{
    int size=11;
    int a[size][size],count=1,i=0,j=0,ci=0,cj=0;
    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            a[i][j]=0;
    time_t start=time(NULL);
    i=0;
    j=size/2;
    a[i][j]=count;
    while(count !=size*size)
    {
        ci=i;
        cj=j;
        i--;
        j--;
        if(i<0)
            i+=size;
        if(j<0)
            j+=size;
        if(a[i][j]!=0)
        {
            i=ci+1;
            j=cj;
        }
        a[i][j]=++count;
    }
    time_t stop=time(NULL);
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    printf("%ld\n",CLOCKS_PER_SEC);
    printf("Duration =%lf\n",(double)difftime(stop,start));
    printf("End.\n");
}
int main()
{
    generate();
    return 0;
}