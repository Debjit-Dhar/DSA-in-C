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
struct sparse s[MAX_SIZE];
void print(int start,int finish,struct sparse s[])
{
    int m=s[start-1].row,n=s[start-1].coln;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
            if(i==s[start].row && j==s[start].coln)
            {
                printf("%.2f\t",s[start].val);
                start++;
            }
            else
                printf("0.00\t");
        printf("\n");
    }    
}
int add(int startA,int finishA,int startB,int finishB,int avail)
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
int transpose(int start,int finish,int avail)
{
    if(avail==MAX_SIZE)
    {
        printf("Out of Bounds.\n");
        exit(1);
    }
    s[avail].row=s[start].coln;
    s[avail].coln=s[start].row;
    s[avail++].val=s[start].val;
    int col=s[start].coln,st=start+1,n=finish;    
    start++;
    for(int i=0;i<col;i++)
    {
        for(st=start;st<=n;st++)
        {
            if(s[st].coln==i)
            {
                s[avail].row=s[st].coln;
                s[avail].coln=s[st].row;
                s[avail++].val=s[st].val;
            }
        }
    } 
    return avail;
}
int mul(int startA,int finishA,int startB,int finishB,int avail)//Take A as it is and the transpose of B
{
    int m=s[startA-1].row,n=s[startB-1].row,sta,stb;
    float sum=0,i,j;
    for(i=0;i<m;i++)
    {
        sum=0;
        for(int j=0;j<n;j++)
        {
            sum=0;
            for(sta=startA;sta<=finishA;sta++)
            {
                for(stb=startB;stb<=finishB;stb++)
                    if(s[sta].row==i && s[stb].row==j && s[sta].coln==s[stb].coln)
                        sum+=s[sta].val*s[stb].val;
            }
            
            if(sum!=0)
            {
                s[avail].row=i;
                s[avail].coln=j;
                s[avail++].val=sum;
                
            }   
        }     
    }
    return avail;
}
void main()
{
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
    avail=transpose(sf[0][0]-1,sf[1][0],avail);
    sf[1][2]=avail-1;
    //Transpose B
    sf[0][3]=avail+1;
    avail=transpose(sf[0][1]-1,sf[1][1],avail);
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
        avail=add(sf[0][0],sf[1][0],sf[0][1],sf[1][1],avail);
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
        avail=mul(sf[0][0],sf[1][0],sf[0][3],sf[1][3],avail);
        printf("PRODUCT\n");
        sf[1][5]=avail-1;
        s[sf[0][5]-1].val=sf[1][5]-sf[0][5]+1;
        print(sf[0][5],sf[1][5],s);
    }    
}