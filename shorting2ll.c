#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*link;
};
struct node*creat(int n)
{ 
    struct node*temp,*head=(struct node*)malloc(sizeof(struct node)),*last;
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
void main()
{
    struct node *head1=creat(5),*head2=creat(4),*temp1=head1,*temp2=head2;
    while(temp1->link!=NULL||temp2->link!=NULL)
    {
        if(temp1->link==NULL)
        { 
           while(temp2!=NULL)
           {
             printf("%d->", temp2->data);
             temp2=temp2->link;
           }
        }
        else if(temp2->link==NULL)
        { 
           while(temp1!=NULL)
           {
             printf("%d->" ,temp1->data);
             temp1=temp1->link;
           }
        }
        else if(temp1->data<=temp2->data)
        {
            printf("%d->",temp1->data);
            temp1=temp1->link;
        }
        else
        {
             printf("%d->",temp2->data);
            temp2=temp2->link;
        }
    }
}