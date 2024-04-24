#include <stdio.h>
int main()
{
    int ch;
    printf("Enter choice 1 to push,2 to pop,3 to print and any other number to exit.\n");
    scanf("%d",&ch);
    for(;;){
    switch(ch)
    {
        case 1:
        printf("Push\n");
        break;
        case 2:
        printf("Pop\n");
        break;
        case 3:
        printf("Print\n");
        break;
        default:
        exit(0);
    }
    }
    return 0;
}