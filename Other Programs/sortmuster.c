#include <stdio.h>
#include <time.h>
void main()
{
    int n,i,j;
    printf("Enter size of the array.\n");
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
    {
        printf("Enter element no %d\n",i+1);
        scanf("%d",&a[i]);
    }
    printf("Original Array.\n");
    display(a,n);
    printf("Enter method of sorting 1 for bubble sort, 2 for selection sort, 3 for insertion sort, 4 for merge sort, 5 for quick sort, 6 for shaker sort and 7 for heap sort.\n");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
        bsort(a,n);
        break;
        case 2:
        ssort(a,n);
        break;
        case 3:
        isort(a,n);
        break;
        case 4:
        msort(a,0,n-1);
        break;
        case 5:
        qsort(a,0,n-1);
        case 6:
        shsort(a,n);
        break;
        case 7:
        hsort(a,n);
        break;
        default:
        printf("Invalid Input.\n");
    }
    if(ch>=1 && ch<=7)
     display(a,n);
    runtime();
}
void bsort(int a[],int n)
{
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
void ssort(int a[],int n)
{
    for(int i=0;i<n;i++) 
    {
        int small=a[i],pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(a[j]<small)
            {
                pos=j;
                small=a[j];
            }
        }
        a[pos]=a[i];
        a[i]=small;
    }
}
void isort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int temp=a[i],j;
        for(j=i-1;j>=0 && temp<a[j];j--)
        a[j+1]=a[j];
        a[j+1]=temp;
    }
}
void msort(int a[],int l,int r)
{
   if(l<r)
   {
     int m=(l+r)/2;
     msort(a,l,m);
     msort(a,m+1,r);
     merge(a,l,m,r);
   }
}
void merge(int a[],int l,int m,int r)
{
    int n1=m-l+1,n2=r-m,i,j,k;
    int L[n1],R[n2];
    for(i=0;i<n1;i++)
    L[i]=a[l+i];
    for(j=0;j<n2;j++)
    R[j]=a[m+1+j];
    i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
         a[k++]=L[i++];
         else
          a[k++]=R[j++];
    }
    while(i<n1)
     a[k++]=L[i++];
    while(j<n2)
     a[k++]=R[j++];
}
void qsort(int a[],int left,int right)
{
    int left1=left,right1=right,pivot=a[left];
    while(left<right)
    {
        while((a[right]>=pivot)&&(left<right))
         right--;
        if(left!=right)
        {
            a[left]=a[right];
            left++;
        }
        while((a[left]<=pivot)&&(left<right))
         left++;
        if(left!=right)
        {
            a[right]=a[left];
            right--;
        }
    }
    a[left]=pivot;
    pivot=left;
    left=left1;
    right=right1;
    if(left<pivot)
     qsort(a,left,pivot-1);
    if(right>pivot)
     qsort(a,pivot+1,right);
}
int leftchild(int i)
{
    return i+1;
}
void percolate_down(int a[],int i,int n)
{
    int temp,child;
    for(temp=a[i];leftchild(i)<n;i=child)
    {
        child=leftchild(i);
        if(child!=n-1&& a[child+1]>a[child])
            child++;
        if(temp<a[child])
            a[i]=a[child];
        else
            break;
    }
    a[i]=temp;
}
void hsort(int a[],int n)
{
    int i;
    for(i=n/2;i>=0;i--)
        percolate_down(a,i,n);
    for(i=n-1;i>0;i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        percolate_down(a,0,i);
    }
}
void shsort(int a[],int n)
{
    int i;
    int exchange;
    do{
        exchange=0;
        for(i=n-1;i>0;i--)
        {
            if(a[i-1]>a[i])
            {
                int t=a[i-1];
                a[i-1]=a[i];
                a[i]=t;
                exchange =1;
            }
        }
      for(i=1;i<n;i++)
      {
         if(a[i-1]>a[i])
         {
             int t=a[i-1];
             a[i-1]=a[i];
             a[i]=t;
             exchange=1;
         }
      }
    }while(exchange);
}
void display(int a[],int n)
{
    for(int i=0;i<n;i++)
     printf("%d\t",a[i]);
    printf("\n");
}
void runtime()
{
    printf("Runtime of this program= 0.0000%u\n",(clock()*100000)/CLOCKS_PER_SEC);
}