#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct data
{
    int n;
};
typedef struct threaded_btree_type* btpointer;
struct threaded_btree_type
{
    struct data dat;
    btpointer left,right;
    //int leftthread;
    int rightthread;//if 1 then right is pointer to inorder succesor i.e node does not have a right child but if 0 then pointer to right child of the node.
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
        //t->leftthread=0;
        t->rightthread=0;
    }
    return t;
}
btpointer add_rightthread(btpointer p,btpointer t)//t is right child of p
{
    t->rightthread=1;
    t->right=p;
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
void inorder_traverse(btpointer t)
{
    btpointer temp=t;
    while(!empty_t(t))
    {
        while(!empty_t(temp->left))
            temp=temp->left;
        visit(temp);
        while(temp->rightthread&&(!empty_t(temp->right)))
        {
            temp=temp->right;
            visit(temp);            
        }
        temp=temp->right;
    }
}
int main() {
    // Creating a threaded binary tree
    struct data root_data = {10};
    btpointer root = makeroot(root_data);

    struct data left_data = {5};
    addleft(root, left_data);

    struct data right_data = {15};
    addright(root, right_data);

    // Adding right threads
    add_rightthread(root, root->left);

    // Traversing the threaded binary tree in order
    printf("Inorder traversal of threaded binary tree:\n");
    inorder_traverse(root);

    // Finding the height of the tree
    int tree_height = height(root);
    printf("Height of the threaded binary tree: %d\n", tree_height);

    return 0;
}
