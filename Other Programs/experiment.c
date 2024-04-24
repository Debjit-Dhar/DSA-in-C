#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int roll;
    char name[100];
    float score;
};
int f_roll(struct student a,struct student b)
{
    if(a.roll>b.roll)
        return 1;
    return 0;
}
void sort(struct student stdlist[],int n,int (*cmp)(struct student,struct student))
{
    int i,j;
    for(i=n-1;i>=0;i--)
    {
        for(j=0;j<i;j++)
        if(cmp(stdlist[j],stdlist[j+1]))
        {
            struct student t=stdlist[j];
            stdlist[j]=stdlist[j+1];
            stdlist[j+1]=t;
        }
    }
}
void main()
{
    int n;
    printf("Enter number of students.\n");
    scanf("%d",&n);
    struct student stdlist[n];
    for(int i=0;i<n;i++)
    {
        printf("Enter roll.\n");
        scanf("%d",&stdlist[i].roll);
        fflush(stdin);
        printf("Enter name.\n");
        scanf("%s",stdlist[i].name);
        printf("Enter score.\n");
        scanf("%f",&stdlist[i].score);
    }
    int (*fp)(struct student,struct student);
    fp=f_roll;
    sort(stdlist,n,fp);
    printf("Roll\tName\tScore\n");
    for(int i=0;i<n;i++)
        printf("%d\t%s\t%f\n",stdlist[i].roll,stdlist[i].name,stdlist[i].score);
}