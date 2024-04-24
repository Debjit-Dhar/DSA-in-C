#include <stdio.h>
#include <stdlib.h>
#define FACTOR_OF_SAFETY 0.2
#define MAX_SIZE 120
struct sparse
{
    int row;
    int coln;
    float val;
};
void print(int start,int finish,struct sparse s[])
{
    int m=s[start-1].row,n=s[start-1].coln,k=start;
    float a[m][n];
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
            a[i][j]=0.00;
    while(start<=finish)
    {
        a[s[start].row][s[start].coln]=s[start].val;
        start++;
    }
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(a[i][j])
                printf("%.2f\t",a[i][j]);
            else
                printf("0.00\t");
        printf("\n");
    }
}
int transpose(int start,int finish,struct sparse s[],int avail)
{
    if(avail==MAX_SIZE)
    {
        printf("Out of Bounds.\n");
        exit(1);
    }
    for(;start<=finish;start++)
    {
        s[avail].row=s[start].coln;
        s[avail].coln=s[start].row;
        s[avail++].val=s[start].val;
    }    
    return avail;
}
int add(int startA,int finishA,int startB,int finishB,struct sparse s[],int avail)
{
    while(startA<=finishA &&startB<=finishB)
    {
        if(s[startA].row==s[startB].row)
        {
            if(s[startA].coln==s[startB].coln)
            {
                if(s[startA].val+s[startB].val==0)
                {
                    startA++;
                    startB++;
                    continue;
                }
                s[avail].row=s[startA].row;
                s[avail].coln=s[startA].coln;
                s[avail].val=s[startA].val+s[startB].val;
                startA++;
                startB++;
                avail++;
            }
            else if(s[startA].coln<s[startB].coln)
            {
                s[avail].row=s[startA].row;
                s[avail].coln=s[startA].coln;
                s[avail].val=s[startA].val;
                startA++;
                avail++;
            }
            else
            {
                s[avail].row=s[startB].row;
                s[avail].coln=s[startB].coln;
                s[avail].val=s[startB].val;
                startB++;
                avail++;
            }
        }
        else if(s[startA].row<s[startB].row)
        {
            s[avail].row=s[startA].row;
            s[avail].coln=s[startA].coln;
            s[avail].val=s[startA].val;
            startA++;
            avail++;
        }
        else
        {
            s[avail].row=s[startB].row;
            s[avail].coln=s[startB].coln;
            s[avail].val=s[startB].val;
            startB++;
            avail++;
        }
    }
    while(startA<=finishA)
    {
                s[avail].row=s[startA].row;
                s[avail].coln=s[startA].coln;
                s[avail].val=s[startA].val;
                startA++;
                avail++;
    }
    while(startB<=finishB)
    {
                s[avail].row=s[startB].row;
                s[avail].coln=s[startB].coln;
                s[avail].val=s[startB].val;
                startB++;
                avail++;
    }
    return avail;
}
int mul(int startA,int finishA,int startB,int finishB,struct sparse s[],int avail)
{
    float sum;
    int copy;
    while(startA<=finishA)
    {
        sum=0;
        copy=startB;
        while(startB<=finishB)
        {
            if(s[startA].row==s[startB].coln)
            {
                sum+=s[startA].val*s[startB].val;
            }
            startB++;
        }
        startB=copy;
        if(sum!=0)
        {
            s[avail].row=s[startA].row;
            s[avail].coln=s[startA].coln;
            s[avail].val=sum;
            avail++;
        }
        startA++;
    }
    return avail;
}
void main()
{
    struct sparse s[MAX_SIZE];
    int sf[2][MAX_SIZE];
    sf[0][0]=1;
    int m,n,i,j,avail=1;
    float num;
    //Accept Sparse Matrix A
    printf("Enter size rows .\n");
    scanf("%d",&m);
    printf("Enter size columns.\n");
    scanf("%d",&n);
    s[0].row=m;s[0].coln=n;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter value.\n");
            scanf("%f",&num);
            if(num)
            {
                s[avail].row=i;
                s[avail].coln=j;
                s[avail++].val=num;
            }
        }
    }
    s[0].val=avail-1;
    sf[1][0]=avail-1;
    sf[0][1]=avail+1;
    //Accept Sparse Matrix B
    printf("Enter size rows .\n");
    scanf("%d",&m);
    printf("Enter size columns.\n");
    scanf("%d",&n);
    s[avail].row=m;s[avail].coln=n;
    avail++;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("Enter value.\n");
            scanf("%f",&num);
            if(num)
            {
                s[avail].row=i;
                s[avail].coln=j;
                s[avail++].val=num;
            }
        }
    }
    s[sf[0][1]-1].val=avail-sf[0][1];
    sf[1][1]=avail-1;
    //Print A
    printf("Matrix A\n");
    print(sf[0][0],sf[1][0],s);
    //Print B
    printf("Matrix B\n");
    print(sf[0][1],sf[1][1],s);
    //Transpose A
    sf[0][2]=avail+1;
    avail=transpose(sf[0][0]-1,sf[1][0],s,avail);
    sf[1][2]=avail-1;
    //Transpose B
    sf[0][3]=avail+1;
    avail=transpose(sf[0][1]-1,sf[1][1],s,avail);
    sf[1][3]=avail-1;
    //Print A
    printf("Transpose of Matrix A\n");
    print(sf[0][2],sf[1][2],s);
    //Print B
    printf("Transpose of Matrix B\n");
    print(sf[0][3],sf[1][3],s);
       
    //SUM
    if(s[sf[0][0]-1].row==s[sf[0][1]-1].row&&s[sf[0][0]-1].coln==s[sf[0][1]-1].coln)
    {
        sf[0][4]=avail+1;
        s[avail].row=s[0].row;
        s[avail].coln=s[0].coln;
        avail+=1;
        avail=add(sf[0][0],sf[1][0],sf[0][1],sf[1][1],s,avail);
        printf("SUM\n");
        sf[1][4]=avail-1;
        s[sf[0][4]-1].val=avail-sf[0][4];
        print(sf[0][4],sf[1][4],s);
    }   

    //Product
    if(s[0].coln==s[sf[0][1]-1].row)   
    {
        sf[0][5]=avail+1;
        s[avail].row=s[0].row;
        s[avail].coln=s[sf[0][1]-1].coln;
        avail+=1;
        avail=mul(sf[0][0],sf[1][0],sf[0][1],sf[1][1],s,avail);
        printf("PRODUCT\n");
        sf[1][5]=avail-1;
        s[sf[0][5]-1].val=10;
        printf("avail=%d\n",avail);
        print(sf[0][5],sf[1][5],s);
    }
    for(i=26;i<=30;i++)
        printf("%d)%d %d %f\n",i,s[i].row,s[i].coln,s[i].val);
    printf("%d %d",sf[0][5],sf[1][5]); 
}