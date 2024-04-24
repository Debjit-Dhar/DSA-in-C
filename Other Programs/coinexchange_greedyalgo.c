//Solution to coin exchange problem using greedy algorithm.
#include <stdio.h>
int main()
{
    int amt,i,max,ch,pos;
    printf("Enter the amount to be made.\n");
    scanf("%d",&amt);// amount to be formed using the minimum number of coins.
    int denom[5]={50,25,11,5,1};//array of denominations of coins to be used
    while(amt!=0)
    {
        max=denom[0],pos=0;
        for(i=0;i<5;i++)
            if(denom[i]>max)
            {
                max=denom[i];
                pos=i;
            }    
        denom[pos]=0;
        ch=amt/max;
        if(ch!=0)
        {
            printf("%d %dp coins\n",ch,max);
            amt-=max*ch;
        }
    }
    return 0;
}