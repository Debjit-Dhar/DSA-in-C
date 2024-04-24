#include <stdio.h>
#include <stdlib.h>
#define FACTOR_OF_SAFETY 0.2
#define MAX_TERMS 120 
struct polynomial
{
    float coeff;
    int exp;
};
struct polynomial terms[MAX_TERMS]; 
int isZero(int start)
{
    if(terms[start].exp==0)
        return 1;
    else
        return 0; 
}
int degree(int start)
{
    return terms[start].exp;
}
void print(int start,int finish)
{
    for(int i=start;i<=finish;i++)
    if(terms[i].coeff<0)
        {if(terms[i].exp==1)
            terms[i].coeff!=-1?printf("%.2fx",terms[i].coeff):printf("-x");
            else if (terms[i].exp==0)
            terms[i].coeff!=-1?printf("%.2f",terms[i].coeff):printf("-1");
            else
            terms[i].coeff!=-1?printf("%.2fx^%d",terms[i].coeff,terms[i].exp):printf("-x^%d",terms[i].exp);
        }
    else
        {if(terms[i].exp==1)
            terms[i].coeff!=1?printf("+%.2fx",terms[i].coeff):printf("+x");
            else if (terms[i].exp==0)
            terms[i].coeff!=1?printf("+%.2f",terms[i].coeff):printf("+1");
            else
            terms[i].coeff!=1?printf("+%.2fx^%d",terms[i].coeff,terms[i].exp):printf("+x^%d",terms[i].exp);
        }
}
struct polynomial attach(float c,int e,int avail)
{
    if(avail>=MAX_TERMS)
    {
        printf("Out of Bounds Exception.\n");
        exit(1);
    }
    terms[avail].coeff=c;
    terms[avail].exp=e;
}
int add(int startA,int finishA,int startB,int finishB,int avail)
{
    while(startA<=finishA&&startB<=finishB)
    {
        if(terms[startA].exp<terms[startB].exp)
        {
            attach(terms[startB].coeff,terms[startB].exp,avail);
            startB++;
        }
        else if(terms[startA].exp>terms[startB].exp)
        {
            attach(terms[startA].coeff,terms[startA].exp,avail);
            startA++;
        }
        else
        {
            attach(terms[startA].coeff+terms[startB].coeff,terms[startA].exp,avail);
            startA++;
            startB++;
        }
        avail++;
    }
    for(;startA<=finishA;startA++)
    {
        attach(terms[startA].coeff,terms[startA].exp,avail);
        avail++;
    }
    for(;startB<=finishB;startB++)
    {
        attach(terms[startB].coeff,terms[startB].exp,avail);
        avail++;
    }
    return avail;
}
int mult(int startA,int finishA,int startB,int finishB,int avail)
{
    struct polynomial temp[(finishA+1)*(finishB-finishA)];
    int availc=0;
    for(;startA<=finishA;startA++)
    {
        for(int i=startB;i<=finishB;i++)
        {
            temp[availc].coeff=terms[startA].coeff*terms[i].coeff;
            temp[availc].exp=terms[startA].exp+terms[i].exp;
            availc++;
            //attach(terms[startA].coeff*terms[i].coeff,terms[startA].exp+terms[i].exp,avail);
            //avail++;
        }
    }
    
    for(int i=0;i<availc;i++)
    {
        for(int j=i+1;j<availc;j++)
        {
            if(temp[i].exp==temp[j].exp)
            {
                temp[i].coeff+=temp[j].coeff;
                temp[j].exp=0;
                temp[j].coeff=0;
            }
        }
        if(temp[i].exp==0&&temp[i].coeff==0)
            continue;
        else
        {   
            attach(temp[i].coeff,temp[i].exp,avail);
            avail++;
        }
    }
    return avail;
}
void cmult(int Const,int startA,int avail)
{
    for(;startA<avail;startA++)
        terms[startA].coeff*=Const;
}
