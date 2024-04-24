#include <stdio.h>
void main()
{
    enum coins{penny,nickel,dime,quarter=100,half_dollar,dollar};
    enum coins money;
    printf("%d\t%d\n",nickel,dollar);
}