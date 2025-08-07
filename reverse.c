#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
}*head,*last;
struct node*creat(int n)
{ 
    struct node*temp;
    head=(struct node *)malloc(sizeof(struct node));
    printf("Enter a data:");
    scanf(" %d",&head->data);
    head->link=NULL;
    temp=head;
    for(int i=1;i<n;i++)
    {
        last=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data:");
        scanf("%d",&last->data);
        last->link=NULL;
        temp->link=last;
        temp=temp->link;
    }
    return head;
}
void removedup(struct node*head)
{
   struct node*temp=head,*temp2=temp->link;
   int i=2,j=i;
   while(temp2!=NULL)
   {
    while(temp2!=NULL)
    {
        if(temp2->data==temp->data)
        {
            del_pos(i);
        }
        else
        {
          j++;
        }
        temp2=temp2->link;
    }
     temp=temp->link;
     i=i+1;
     j=i;
    }
}
void del_pos(int i)
{
    struct node*temp=head,*del;
    int i;
    if(head==NULL)
     printf("no sll");
    else
    {
      while(i-2)
      {
        temp=temp->link;
        i--;
      }
      del=temp->link;
      temp->link=temp->link->link;
      free(del);
    }
}
struct node* reverse()
{
    struct node*temp,*temp2;
    temp=head;
    temp2=head->link;
    temp->link=NULL;
    while(temp2!=NULL)
    {
        head=temp2;
        temp2=temp2->link;
        head->link=temp;
        temp=head;
    }
    return head;
}
void main()
{
    int n;
    struct node*temp;
    printf("enter no.of nodes do u want:");
    scanf("%d",&n);
    head=creat(n);
    head=reverse();
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->link;
    }
}