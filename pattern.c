#include<stdio.h>
void main()
{
  int n;
  printf("enter n value:");
  scanf("%d",&n);
  int size=2*n-1,i,j;
  for(i=1;i<=size;i++)
  {
    for(j=1;j<=size;j++)
    {
        int value=(i<j?i:j)<(size-i+1<size-j+1?size-i+1:size-j+1)?(i<j?i:j):(size-i+1<size-j+1?size-i+1:size-j+1);
        printf("%d ",n-value+1);
    }
    printf("\n");
  }
}