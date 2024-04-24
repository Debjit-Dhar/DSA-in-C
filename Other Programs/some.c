// Online C compiler to run C program online
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct tree_type* BST;
struct tree_type
{
    int key;
    BST left;
    BST right;
    int height;
};
BST init_t()
{
    return NULL;
}
int empty_t(BST t)
{
    return t==NULL;
}
BST make_root(int n)
{
    BST t=(BST)malloc(sizeof(struct tree_type));
    t->key=n;
    t->left=NULL;
    t->right=NULL;
    t->height=1;
    return t;
}
void addleft(BST t,int n)
{
    t->left=make_root(n);
}
void add_right(BST t,int n)
{
    t->right=make_root(n);
}
int height(BST t)
{
    if(empty_t(t))
        return 0;
    else
        return t->height;
}
BST search(BST t,int n)
{
    if(empty_t(t))
        return NULL;
    else if(n==t->key)
        return t;
    else if(n<t->key)
        return search(t->left,n);
    else
        return search(t->right,n);
}
BST search_i(BST t,int n)
{
    if(empty_t(t))
        return NULL;
    while(!empty_t(t))
    {
        if(t->key==n)
            return t;
        else if(n<t->key)
            t=t->left;
        else
            t=t->right;
    }
    return NULL;
}
int insert(BST t,int n)
{
    if(empty_t(t))
    {
        t=make_root(n);
        return 1;
    }
    else if(n<t->key)
        insert(t->left,n);
    else if(n>t->key)
        insert(t->right,n);
    else
        return 0;
}
BST inorder_s(BST t)
{
    while(!empty_t(t->left))
        t=t->left;
    return t;    
}
BST delete(BST t,int n)
{
    if(empty_t(t))
        return NULL;
    else if(n<t->key)
        t->left=delete(t->left,n);
    else if(n>t->key)
        t->right=delete(t->right,n);
    else
    {
        if(empty_t(t->left))
        {
            BST cur=t->right;
            free(t);
            return cur;
        }   
        else if(empty_t(t->right))
        {   
            BST cur=t-> left;
            free(t);
            return cur;
        }
        BST cur=inorder_s(t->right);
        t->key=cur->key;
        t->right=delete(t->right,cur->key);
    }
    return t;
}
BST rightrotate(BST t)
{
    BST temp1=t->left;
    BST temp2=temp1->right;
    t->left=temp2;
    temp1->right=t;
    t->height=1+fmax(height(t->left),height(t->right));
    temp1->height=1+fmax(height(temp1->left),height(temp1->right));
    return temp1;
}
BST lefttrotate(BST t)
{
    BST temp1=t->right;
    BST temp2=temp1->left;
    temp1->left=t;
    t->right=temp2;
    t->height=fmax(getheight(t->right),getheight(t->left))+1;
    temp1->height=fmax(getheight(temp1->right),getheight(temp1->left))+1;
    return temp1;
}
int main()
{
    return 0;
}