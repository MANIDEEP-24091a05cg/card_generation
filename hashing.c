#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 10
int hashtable[size]={0};
struct node
{
    int data;
    struct node*link;
}*arr[size]={NULL};
int hash(int data)
{
 return (abs(data))%size;
}
int mid_square(int data)
{
    long long key=data*data,temp=key;
    int count=0,arr[20],t,i=0,result;
    while(temp!=0)
    {
        t=temp%10;
        arr[i++]=t;
        temp=temp/10;
        count++;
    }
    if(count%2==0)
    {
        if(arr[count/2]!=0)
           result=(arr[(count/2)+1]*10)+arr[count/2];
        else
          result=arr[(count/2)+1];
    }
    else
     result=arr[count/2];
    while(result>size-1)
    {
       result=mid_square(result);
    }
    return result;
}
void ins_opha(int data)
{
    int key=hash(data);
    struct node*newnode=(struct node*)malloc(sizeof(struct node)),*temp;
    newnode->data=data;
    newnode->link=NULL;
    if(arr[key]==NULL)
    {
       arr[key]=newnode;
    }
    else{
         newnode->link=arr[key];
         arr[key]=newnode;
    }
}
void insertlp(int data)
{
    int key,count=0;
    key=hash(data);
    while(hashtable[key]!=0&&count<size)
    {
        key=(key+1)%size;
        count++;
    }
    if(count==size)
    {
     printf("HASH TABLE IS FULL");
     return;
    }
    hashtable[key]=data;
}
void insertqp(int data)
{
    int key=mid_square(data),i=1,j;
    if(hashtable[key]==0)
    {
       hashtable[key]=data;
       return;
    }
    else{
        while(i<=size)
        {
            if(i<size)
            {
               while(hashtable[(key+(i*i))%size]!=0)
              {
                  i++;
              }
            }
             else
        {
            printf("size is not found");
            return;
        }
        }
        hashtable[(key+(i*i))%size]=data;
    }
}
void searchlp(int data)
{
    int key=hash(data);
    if(hashtable[key]==data)
    {
        printf("%d is found at %d",data,key);
        return;
    }
    else{
        while(hashtable[key]!=0)
        {
            if(hashtable[key]==data)
            {
                printf("%d is found at %d",data,key);
                return;
            }
            key=(key+1)%size;
        }
        printf("key not found");
    }
}
void display()
{
    int i=0;
    while(i!=size)
    {
        printf("%d->",hashtable[i]);
        i++;
    }
}
void main()
{
    int ch,data ;
    while(1)
    {
        printf("1.inserlp,2.searchlp,3.dispaylp,4.ins_opha,5.insertqp,switch is incomplete");
        printf(":data:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("enter the data");
                    scanf("%d",&data);
                    insertlp(data);
                    break;
            case 2:printf("enter the data:");
                    scanf("%d",&data);
                    searchlp(data);
                    break;
            case 3:display();
                    break;
            case 4:printf("enter the data:");
                   scanf("%d",&data);
                   ins_opha(data);
                   break;
            case 5:printf("enter the data:");
                   scanf("%d",&data);
                   insertqp(data);
                   break;
            case 6:exit(1); 
        }
    }
}