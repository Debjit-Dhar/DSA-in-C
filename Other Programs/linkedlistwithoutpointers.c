#include <stdio.h>
#define NIL -1
#define MAX 100
struct infor
{
    int n;
};
typedef struct
{
    struct infor info;
    int cursor;    
}nodetype;
nodetype nodepool[MAX];
int avail=0;//head pointer
int createNode(struct infor info1)
{
    int temp;
    if(avail==-1)//similar to heap space exhausted in case of linked list using pointers
    {
        perror("No available Nodes.\n");
        return -1;
    }
    temp=avail;
    avail=nodepool[avail].cursor;
    nodepool[temp].info=info1;
    nodepool[temp].cursor=NIL;
    if(temp!=0)
        nodepool[temp-1].cursor=temp;
    return temp;
}
void set_cur()
{
    int i;
    for(i=0;i<MAX-1;i++)
        nodepool[i].cursor=i+1;
    nodepool[i].cursor=NIL;
}
int init_l()
{
    return NIL;
}
int atend_l(int cur1)
{
    if(cur1==-1)
        return 0;
    else
        return nodepool[cur1].cursor;
}
int print_l()
{
    int start=0;
    while(start!=-1)
    {
        printf("%d->",((nodepool[start].info).n));
        start=nodepool[start].cursor;
    }
    printf("\n");
}
int main()
{
    set_cur();
    int cur1,cur2,head1=init_l(),head2;
    struct infor i;
    i.n=1;
    cur1=createNode(i);
    i.n=2;
    cur2=createNode(i);
    i.n=3;
    createNode(i);
    print_l();
    
    return 0;
}