#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
    int ch=1;
    while(ch)
    {
        double x;
        srand(time(NULL));
        double guess;
        printf("Enter bet in U.S dollars\n");
        fflush(stdin);
        scanf("%lf",&x);
        printf("Guess a number from 1 to 100\n");
        fflush(stdin);
        scanf("%lf",&guess);
        double ran=rand()%100;
        if(guess==ran)
        {
            printf("$%lf dollars credited\n",10*x);
        }
        else
        {
            printf("$%lf debited\n",x);
        }
         printf("If u continue u may replace ur losses. Press any number to continue and 0 to exit\n");
        scanf("%d",&ch);
    }
}