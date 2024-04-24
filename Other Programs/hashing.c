#include <stdio.h>
#include <math.h>
int cd(int n)
{
    int c=0;
    while(n>0)
    {
        c++;
        n/=10;
    }
    return c;
}

int hash_division(int k)
{
    int M=17;
    return k%M;
}
int hash_midsquare(int k)
{
    int M=100,n=k*k,s=0;
    int a[100],i=0;
    while(n>0)
    {
        a[i++]=n%10;
        n/=10;
    }
    int mid=i/2,cm=cd(M)-1;
    i=i-mid;
    while(cm>0)
    {
        s=a[i]*10+s;
        cm--;
        i--;
    }
    return s;
}
int hash_multiplication(int k)
{
    int M=100;
    float c=0.314;
    float n=round( M*((c*k)-round(c*k)));
    return n;
}
long long int hash_folding(char s[],int n,int M)
{
    int i,p,c=0;
    long long int sum=0;
    long long int num;
    int a[100],k=0;
    for(i=n-1;i>=0;i--)
    {
        int p=(int)s[i];
        
        a[k++]=p%10;
        p/=10;
        a[k++]=p%10;
        p/=10;
        if(p!=0)
            a[k++]=p%10;
    }
    for(i=0;i<k;i++)
        printf("%d",a[i]);
    printf("\n");
    int fold_length=ceil(k/4.0);
    for(i=0;i<k;i++)
    {
        if(i%fold_length)
        {
           
            p=(int)pow(10,i%fold_length);
            p=p==99?100:p;
            num=(a[i]*p+num);
        }
        else
        {
            printf("%lld\n",num);
            sum=num;
            num=a[i];
            printf("sum=%lld\n",sum);
        }
    }
    
    printf("%lld\n",sum);
    return sum%1000;
}
int main()
{
    printf("%lld\n",hash_folding("INDIA",5,3));
    return 0;
}