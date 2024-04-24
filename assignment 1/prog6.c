#include <stdio.h>
#include <string.h>
struct names{
    char name[100];
};
int main()
{
    FILE *fp;
    fp=fopen("Student.txt","w+");
    if(fp==NULL)
    {
        printf("Cannot Create file.\n");
        return 0;
    }
    int n;
    printf("Enter number of names.\n");
    scanf("%d",&n);
    struct names Stu[n];
    int i=1;
    char s[100];
    for(;i<=n;i++)
    {
        printf("Enter name.\n");
        fflush(stdin);
        scanf("%[^\n]s",s);
        fflush(stdin);
        fputs(s,fp);
        fputc('\n',fp);
    }
    rewind(fp);
    char min[100],max[100];
    fgets(s,100,fp);
    strcpy(min,s);
    strcpy(max,s);
    i=0;
    while(!feof(fp))
    {
        strcpy(Stu[i++].name,s);
        fgets(s,100,fp);
        if(strlen(min)>strlen(s))
            strcpy(min,s);
        if(strlen(s)>strlen(max))
            strcpy(max,s);
    }
    strcpy(Stu[i].name,s);
    printf("length = %d of max %s",strlen(max)-1,max);
    printf("length = %d of min %s",strlen(min)-1,min);
    printf("%d\n",n);
    for(i=n-1;i>=0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(strcmp(Stu[j].name,Stu[j+1].name)>=0)
            {
                strcpy(s,Stu[j].name);
                strcpy(Stu[j].name,Stu[j+1].name);
                strcpy(Stu[j+1].name,s);
            }
        } 
    }
    FILE*fps;
    fps=fopen("SortedData.txt","w+");
    if(fps==NULL)
    {
        printf("Cannot Create file.\n");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        fflush(stdin);
        fputs(Stu[i].name,fps);
    }
    fclose(fp);
    fclose(fps);
    return 0;
}