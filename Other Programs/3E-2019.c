#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    char date [11];
    fflush(stdin);
    scanf("%10s",date);
    char day [3],month [3],year [5];
    int i;
    for(i=0;i<2;i++)
     day[i]=date[i];
    for(i=0;i<2;i++)
     month[i]=date[3+i];
    for(i=0;i<4;i++)
     year[i]=date[6+i];
    char months [][20]={" ","Jan","Feb","Mar","Apr","May","June","July","Aug","Sept","Oct","Nov","Dec"};
    int days [13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    if(atoi(month)>0 && days[atoi(month)]>=atoi(day)&& atoi(year)>0 && atoi(day)>0)
    {
       printf("%s-%d-%d\n",months[atoi(month)],atoi(day),atoi(year));
    }
    else
    {
        printf("Invaid Input.\n");
        return 0;
    }
    return 0;

}