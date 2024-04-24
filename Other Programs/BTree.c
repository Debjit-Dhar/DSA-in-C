#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define order 4
struct data
{
    int n;
};
typedef struct Btree* Btpointer;
struct Btree
{
    int k;
    struct data datalist[order];
    Btpointer ptrlist[order+1];
};
Btpointer init_t()
{
    return NULL;
}
Btpointer empty_t(Btpointer t)
{
    return (t==NULL);
}

int main()
{
    return 0;
}