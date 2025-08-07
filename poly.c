#include<stdio.h>
#include<stdlib.h>
struct node
{
    char a;
    int data;
    struct node*link;
}*head==NULL,*head2==NULL,*last2==NULL,*last==NULL;
struct node *create()
{
  struct node *newnode=(struct node*)malloc(sizeof(struct node)),*temp=newnode;
  int data,b;
  printf("enter the data:");
  scanf("%d",&newnode->data);
  printf("enter the variable:");
  scanf("%c",&newnode->a);
  temp->link=NULL;
  while(1)
  {
    printf("do u want another node:");
    scanf("%d",&b);
    if(b==0)
    break;
    printf("enter the data:");
    scanf("%d",&newnode->data);
    printf("enter the variable:");
    scanf("%c",&newnode->a);
    temp->link=(struct node*)malloc(sizeof(struct node));
    temp=temp->link;
  }
  return newnode;
}
void main()
{
    
}