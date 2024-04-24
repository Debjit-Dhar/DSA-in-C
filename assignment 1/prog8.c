#include <stdio.h>
#include <math.h>
void main()
{
    char name[100];
    printf("Enter name.\n");
    fgets(name,100,stdin);
    char surname[100];
    printf("Enter surname.\n");
    fgets(surname,100,stdin);
    long long int nd=0,snd=0,nd1,snd1,nd2,snd2;
    int p=0,c1=0,c2=9;
    int i=0;
    for(;i<100;i++) 
    {
        if(name[i]=='\n')
         break;
        else
        {
            if(name[i]<'d')
             p=100;
            else
             p=1000;
            nd=nd*p+(int)name[i];
            c1+=p==100?2:3;
        }
    }
    for(i=0;i<100;i++)
    {
        if(surname[i]=='\n')
         break;
        else
        {
            if(surname[i]<'d')
             p=100;
            else
             p=1000;
            snd=snd*p+(int)surname[i];
            c2+=p==100?2:3;
        }
    }
    printf("%lld\n",nd);
    printf("%lld\n",snd);
    nd1=nd/(int)pow(10,c1);
    snd2=snd/(int)pow(10,c2);
    nd2=nd%(int)pow(10,c1);
    snd2=snd%(int)pow(10,c2);
    printf("%lld\n",nd1);
    printf("%lld\n",snd1);
    nd1+=nd2;
    snd1+=snd2;
    printf("%lld\n",nd1);
    printf("%lld\n",snd1);
}