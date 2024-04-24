#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct data
{
    int n;
};
typedef struct bst* btpointer;
struct bst
{
    struct data dat;
    btpointer left,right;
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
    }
    return t;
}
void addleft(btpointer t,struct data d)
{
    t->left=makeroot(d);
}
void addright(btpointer t,struct data d)
{
    t->right=makeroot(d);
}
btpointer search_recursive(btpointer t,struct data d)
{
    if(empty_t(t))
        return NULL;
    else if((t->dat).n==d.n)
        return t;
    else if(d.n<(t->dat).n)
        return(search_recursive(t->left,d));
    else
        return(search_recursive(t->right,d));   
}
btpointer search_iterative(btpointer t,struct data d)
{
    if(empty_t(t))
        return NULL;
    else
    {
        while(!empty_t(t))
        {
            if((t->dat).n==d.n)
                return t;
            else if(d.n<(t->dat).n)
                t=t->left;
            else
                t=t->right;
        }
        return NULL;
    }
}
int insert_node(btpointer t,struct data d)
{
    if(empty_t(t))
    {
        t=makeroot(d);
        return 1;
    }
    else if((t->dat).n==d.n)
        return 0;
    else if(d.n<(t->dat).n)
    {
        insert_node(t->left,d);
    }
    else
    {
        insert_node(t->right,d);
    }
}
btpointer minValueNode(btpointer t) {//to be used with delete_node1
    btpointer current = t;
    while (current->left != NULL)
        current = current->left;
    return current;
}
btpointer maxValNode(btpointer t)//to be used with delete_node2
{
    btpointer cur=t;
    while(cur->right!=NULL)
        cur=cur->right;
    return cur;
}

btpointer delete_node1(btpointer root, struct data key) {//using the concept of replacing by minimum node of right subtree for a node having two children
    if (root == NULL)
        return root;

    if (key.n < root->dat.n)
        root->left = delete_node1(root->left, key);
    else if (key.n > root->dat.n)
        root->right = delete_node1(root->right, key);
    else {
        if (root->left == NULL) {
            btpointer temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            btpointer temp = root->left;
            free(root);
            return temp;
        }

        btpointer temp = minValueNode(root->right);
        root->dat = temp->dat;
        root->right = delete_node1(root->right, temp->dat);
    }
    return root;
}
btpointer delete_node2(btpointer t,struct data key)//using the concept of replacing by maximum node of left subtree for a node having two children
{
    if(empty_t(t))
        return t;
    else if(key.n<t->dat.n)
        t->left=delete_node2(t->left,key);
    else if(key.n>t->dat.n)
        t->right=delete_node2(t->right,key);
    else
    {
        if(empty_t(t->right))
        {
            btpointer temp=t->left;
            free(t);
            return temp;
        }
        else if(empty_t(t->left))
        {
            btpointer temp=t->right;
            free(t);
            return temp;
        }
        btpointer temp=maxValNode(t->left);
        t->dat=temp->dat;
        t->left=delete_node2(t->left,temp->dat);
    }
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
void main()
{
    btpointer root=init_t();
    struct data d;
    d.n=20;
    root=makeroot(d);
    d.n=15;addleft(root,d);
    d.n=25;addright(root,d);
    d.n=9;addleft(root->left,d);
    d.n=16;addright(root->left,d);
    d.n=22;addleft(root->right,d);
    
    d.n=22;
    if(search_recursive(root,d))
        printf("Found.\n");
    else
        printf("Not Found.\n");
    if(search_iterative(root,d))
        printf("Found.\n");
    else
        printf("Not Found.\n");
    d.n=13;
    if(insert_node(root,d))
        printf("Inserted.\n");
    else
        printf("Node already present.\n");

    inorder_traverse(root);
    d.n=20;
    //delete_node1(root,d);
    delete_node2(root,d);
    printf("After Deletion.\n");
    inorder_traverse(root);
}