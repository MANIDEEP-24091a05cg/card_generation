#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data,height;
    struct node*left,*right;
};
struct node* create(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    newnode->height=1;
    return newnode;
}
int height(struct node* node)
{
    if(node==NULL)
    {
        return 0;
    }
    return node->height;
}
int isbalence(struct node* node)
{
    if(node==NULL)
    {
        return 0;

    }
    return height(node->left)-height(node->right);
}
int max(int a,int b)
{
    return a>b?a:b;
}
struct node* leftrotation(struct node*node)
{
    struct node* x=node->right->left;
    struct node*y=node->right;
    node->right->left=node;
    node->right=x;
    node->height=max(height(node->left),height(node->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    return y;
}
struct node* rightrotation(struct node*node)
{
    struct node* y=node->left->right;
    struct node*z=node->left;
    node->left->right=node;
    node->left=y;
    node->height=max(height(node->left),height(node->right))+1;
    z->height=max(height(z->left),height(z->right))+1;
    return z;
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
struct node*insert(int data,struct node* node)
{
    if(node==NULL)
    {
        return create(data);
    }
    if(node->data > data)
    {
        node->left=insert(data,node->left);
    }
    else if(node->data<data)
    {
        node->right=insert(data,node->right);
    }
    else
    {
        return node;
    }
    node->height=max(height(node->left),height(node->right))+1;
    int balence=isbalence(node);
    if(balence>1 && data<node->left->data)
    {
        return rightrotation(node);
    }
    if(balence<-1 && data>node->right->data)
    {
        return leftrotation(node);
    }
    if(balence<-1 && data<node->right->data)
    {
        node->right=rightrotation(node->right);
        return leftrotation(node);
    }
    if(balence>1 && data>node->left->data)
    {
        node->left=leftrotation(node->left);
        return rightrotation(node);
    }
    return node;
}
int main()
{
    struct node* root=NULL;
    root=insert(10,root);
    root=insert(20,root);
    root=insert(30,root);
    root=insert(40,root);
    root=insert(50,root);
    root=insert(25,root);
    preorder(root);
    return 0;
}