#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct data
{
    int n;
};
typedef struct avl* btpointer;
struct avl
{
    struct data dat;
    btpointer left,right;
    int height;//height of a node
};
btpointer init_t()
{
    return NULL;
}
int empty_t(btpointer t)
{
    return(t==NULL);
}
btpointer makeroot(struct data d)
{
    btpointer t=(btpointer)malloc(sizeof(*t));
    if(t==NULL)
        perror("Malloc Error.\n");
    else
    {
        t->dat=d;
        t->left=NULL;
        t->right=NULL;
        t->height=1;
    }
    return t;
}

int getheight(btpointer t)
{
    if(empty_t(t))
        return 0;
    return t->height;
}
int findbf(btpointer t)
{
    if(empty_t(t))
        return 0;
    return getheight(t->left)-getheight(t->right);
}
btpointer rightrotate(btpointer t)//ll rotation=>right rotate
{
    btpointer temp1=t->left;
    btpointer temp2=temp1->right;
    temp1->right=t;
    t->left=temp2;
    t->height=fmax(getheight(t->right),getheight(t->left))+1;
    temp1->height=fmax(getheight(temp1->right),getheight(temp1->left))+1;
    return temp1;
}
btpointer leftrotate(btpointer t)//rr rotation=>left rotate
{
    btpointer temp1=t->right;
    btpointer temp2=temp1->left;
    temp1->left=t;
    t->right=temp2;
    t->height=fmax(getheight(t->right),getheight(t->left))+1;
    temp1->height=fmax(getheight(temp1->right),getheight(temp1->left))+1;
    return temp1;
}

btpointer insert_node(btpointer t,struct data key)
{
    if(empty_t(t))
    {
        t=makeroot(key);
        return t;
    }
    /*else if((t->dat).n==key.n)
        return NULL;*/
    if(key.n<(t->dat).n)
        t->left=insert_node(t->left,key);
    else if(key.n>(t->dat).n)
        t->right=insert_node(t->right,key);
    
    t->height=1+fmax(getheight(t->left),getheight(t->right));
    int bf=findbf(t);
    //Left Left Case
    if(bf>1 && key.n < t->left->dat.n)
        return rightrotate(t);
    
    //Right Right
    if(bf<-1 && key.n > t->right->dat.n)
        return leftrotate(t);

    //Left Right
    if(bf>1 && key.n> t->left->dat.n)
    {
        t->left=leftrotate(t->left);
        return rightrotate(t);
    }

    //Right Left
    if(bf<-1 && key.n<t->right->dat.n)
    {
        t->right=rightrotate(t->right);
        return leftrotate(t);
    }
    return t;
}
void visit(btpointer t)
{
    printf("%d\n",(t->dat).n);
}
void inorder_traverse(btpointer t)
{
    if(!empty_t(t))
    {
        inorder_traverse(t->left);
        visit(t);
        inorder_traverse(t->right);
    }
}
void preorder_traverse(btpointer t)
{
    if(!empty_t(t))
    {
        visit(t);
        preorder_traverse(t->left);
        preorder_traverse(t->right);
    }
}
void postorder_traverse(btpointer t)
{
    if(!empty_t(t))
    {
        postorder_traverse(t->left);
        postorder_traverse(t->right);
        visit(t);
    }
}



int main()
{
    btpointer root=init_t();
    struct data d;
    d.n=1;root=insert_node(root,d);
    btpointer temp=root;
    d.n=2;root=insert_node(root,d);
    d.n=4;root=insert_node(root,d);
    d.n=5;root=insert_node(root,d);
    d.n=6;root=insert_node(root,d);
    d.n=3;root=insert_node(root,d);
    printf("Inorder Traverse.\n");
    inorder_traverse(root);
    printf("Preorder Traverse.\n");
    preorder_traverse(root);
    printf("Postorder Traverse.\n");
    postorder_traverse(root);
    return 0;
}