#include<stdio.h>
#include<stdlib.h>

 struct node
   {
       int data;
       struct node *link;
   };
 struct node* ll()
 {
    struct node *head=(struct node*)malloc(sizeof(struct node)),*t;
    t=head;
    printf("Enter a value:");
    scanf("%d",t->data);
    t->link=NULL;
    while(1)
    {
      int a; 
      printf("do u want another node:");
      scanf("%d",&a);
      if(a==0)
      break;
      t->link=(struct node*)malloc(sizeof(struct node));
      t=t->link;
    }
    
 }
int main() {
  struct node *head=(struct node*)malloc(sizeof(struct node));
  ll();
  printf("%d",head->data);
    return 0;
}