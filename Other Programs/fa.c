#include <stdio.h>
#include <math.h>
int main()
{
    float a=10;
    float b=-10;
    printf("%d\n",isgreater(a,b));
    printf("%d\n",isgreaterequal(a,b));
    printf("%d\n",isless(a,b));
    printf("%d\n",islessequal(a,b));
    printf("%d\n",islessgreater(a,b));
    printf("%d\n",isunordered(a,b));
    return 0;    
}