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
struct node* reverse(struct node*rev)
{
    struct node*temp,*temp2;
    temp=rev;
    temp2=head->link;
    temp->link=NULL;
    while(temp2!=NULL)
    {
        rev=temp2;
        temp2=temp2->link;
        rev->link=temp;
        temp=rev;
    }
    return rev;
}
void main()
{
    int n;
    struct node*org,*newnode,*rev,*temp,*temp2;
    int a,b;
    printf("enter no.of nodes do u want:");
    scanf("%d",&n);
    head=creat(n);
    temp=head;
    if(n%2==0)
    {
        a=n%2;
    }
    else{
        a=n%2+1;
    }
    while(a--)
    {
        temp=temp->link;
    }
    rev=temp->link;
    temp->link=NULL;
    rev=reverse(rev);
    temp2=rev;
    temp=head;
    org=newnode;
    while(temp!=NULL&&temp2!=NULL)
    {
        org=(struct node*)malloc(sizeof(struct node));
        org->data=temp->data;
        temp=temp->link;
        org->link=NULL;
        org=(struct node*)malloc(sizeof(struct node));
        
    }
}