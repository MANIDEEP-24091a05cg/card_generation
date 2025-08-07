#include<stdio.h>
#define max 5
int arr[max];
int first=-1;
void push(int data)
{
    int i;
    first=first+1;
    for(i=first;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=data;
}
//if no data is given in arr then it stores garbage value
void main()
{
    int i;
    push(1);
    push(2);
    push(3);
    push(4);
    for(i=0;i<max;i++)
    printf("%d",arr[i]);
}

