#include <stdio.h>
#include <stdlib.h>
struct data
{
    int n;
};
typedef struct avl*btpointer;
struct avl
{
    struct data dat;
    btpointer left;
    btpointer right;
    int height;
};
int empty_t(btpointer t)
{
    return (t==NULL);
}
int getHeight(btpointer t){
    if(empty_t(t))
        return 0;
    return t->height;
}
 
btpointer createNode(struct data d){
    btpointer t= (btpointer) malloc(sizeof(*t));
    t->dat = d;
    t->left = NULL;
    t->right = NULL;
    t->height = 1;
    return t;
}
 
 
int getBalanceFactor(btpointer t){
    if(t==NULL){
        return 0;
    }
    return getHeight(t->left) - getHeight(t->right);
}
 
btpointer rightRotate(btpointer t){
    btpointer temp1 = t->left;
    btpointer temp2 = temp1->right;
 
    temp1->right = t;
    t->left = temp2;
 
    temp1->height = max(getHeight(temp1->right), getHeight(temp1->left)) + 1;
    t->height = max(getHeight(t->right), getHeight(t->left)) + 1;
 
    return temp1;
}
 
struct Node* leftRotate(struct Node* x){
    struct Node* y = x->right;
    struct Node* T2 = y->left;
 
    y->left = x;
    x->right = T2;
 
    x->height = max(getHeight(x->right), getHeight(x->left)) + 1;
    y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
 
    return y;
}
 
btpointer insert(btpointer t, struct data key){
    if (empty_t(t))
        return  createNode(key);
 
    if (key.n < t->dat.n)
        t->left  = insert(t->left, key);
    else if (key.n > t->dat.n)
        t->right = insert(t->right, key);
 
    t->height = 1 + max(getHeight(t->left), getHeight(t->right));
    int bf = getBalanceFactor(t);
 
    // Left Left Case
        if(bf>1 && key < node->left->key){
            return rightRotate(node);
        }
    // Right Right Case
        if(bf<-1 && key > node->right->key){
            return leftRotate(node);
        }
    // Left Right Case
    if(bf>1 && key > node->left->key){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
    // Right Left Case
    if(bf<-1 && key < node->right->key){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
    return node;
}
 
void preOrder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}
 
int main(){
    struct Node * root = NULL;
 
 
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);
    preOrder(root);
    return 0;
}