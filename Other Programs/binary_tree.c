#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct data
{
    int n;
};
typedef struct btree* btpointer;
struct btree
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
int height(btpointer t)
{
    if(empty_t(t))
        return 0;
    else
        return (1+fmax(height(t->left),height(t->right)));
}
void visit(btpointer t)
{
    printf("%d\n",(t->dat).n);
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
void inorder_traverse(btpointer t)
{
    if(!empty_t(t))
    {
        inorder_traverse(t->left);
        visit(t);
        inorder_traverse(t->right);
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
int main() {
    // Initialize an empty binary tree
    btpointer root = init_t();

    // Create nodes for the binary tree
    struct data d = {8};
    root=makeroot(d);
    d.n=5;addleft(root,d);
    d.n=10;addright(root,d);
    d.n=3;addleft(root->left,d);
    d.n=6;addright(root->left,d);
    d.n=9;addleft(root->right,d);
    d.n=13;addright(root->right,d);
    d.n=1;addleft(root->left->left,d);
    d.n=4;addright(root->left->left,d);
    d.n=12;addleft(root->right->right,d);
    d.n=14;addright(root->right->right,d);
    // Perform traversals
    printf("Preorder Traversal:\n");
    preorder_traverse(root);
    printf("\n");

    printf("Inorder Traversal:\n");
    inorder_traverse(root);
    printf("\n");

    printf("Postorder Traversal:\n");
    postorder_traverse(root);
    printf("\n");

    // Calculate and print the height of the tree
    int tree_height = height(root);
    printf("Height of the binary tree: %d\n", tree_height);

    return 0;
}