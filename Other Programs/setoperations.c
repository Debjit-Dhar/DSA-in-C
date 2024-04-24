#include <stdio.h>
void main()
{
    int m,n;
    printf("Enter size of first set\n");
    scanf("%d",&m);
    printf("Enter size of second set\n");
    scanf("%d",&n);
    int a[m],b[n];
    int i,j;
    for(i=0;i<m;i++)
    {
        printf("Enter \n");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        printf("Enter \n");
        scanf("%d",&b[i]);
    }
    int I[m+n],U[m+n];//i[] stores intersection and u stores union
    printf("A= {");
    for(i=0;i<m;i++)
    {printf("%d",a[i]);
     if(i!=m-1)
      printf(",");
    }
    printf("}\n");
    printf("B= {");
    for(i=0;i<n;i++)
    {printf("%d",b[i]);
     if(i!=n-1)
      printf(",");
    }
    printf("}\n");
    int k=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
         if(a[i]==b[j])
          I[k++]=a[i];
    }
    int ni=k;
    printf("(A'UB')'={");
    for(i=0;i<ni;i++)
     {printf("%d",I[i]);
      if(i!=ni-1)
       printf(",");
     }
    printf("}\n");
    i=0,j=0,k=0;
    while(i<=m && j<=n)
    {
       if(a[i]<=b[i])
        U[k++]=a[i++];
        else{
            int flag=1;
            for(int m=0;m<ni;m++)
             if(I[m]==b[j])
             {flag=0;break;}
            if(flag==0)
             j++;
             else
             U[k++]=b[j++];
        }
    }
    while(i<=m)
     U[k++]=a[i++];
    while(j<=n)
    {
        int flag=1;
            for(int m=0;m<ni;m++)
             if(I[m]==b[j])
             {flag=0;break;}
            if(flag==0)
             j++;
             else
             U[k++]=b[j++];
    }
    int nu=m+n-ni;
    printf("AUB={");
    for(i=0;i<nu;i++)
     {printf("%d",U[i]);
      if(i!=nu-1)
       printf(",");
     }
    printf("}\n");
}