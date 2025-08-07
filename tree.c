#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*left,*right;
};
struct node*create()
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    int temp;
    printf("enter the data(-1 for stop):");
    scanf("%d",&temp);
    if(temp==-1)
     return 0;
    newnode->data=temp;
    printf("enter the left node data %d:",temp);
    newnode->left=create();
    printf("enter the right node data %d:",temp);
    newnode->right=create();
    return newnode;
}
void inorder(struct node*root)
{
    if(root==NULL)
     return 0;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}
void main()
{
    struct node*T=create(),*S=T;
    while(S!=NULL)
    {
     printf("%d",S->data);
     S=S->left;
    }
}