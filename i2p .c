#include <stdio.h>
#include<ctype.h>
int pre(char c)
{
  if(c=='+'||c=='-')
  {
      return 1;
  }
  if(c=='*'||c=='/')
  return 2;
  if(c=='^')
  return 3;
  return 0;
}
void main() {
    char in[100],po[100],temp[100];
    int i,j=0,top=-1;
    printf("enter infix expression:");
    scanf("%s",in);
    for(i=0;in[i]!='\0';i++)
    {
        char c=in[i];
        if(isalnum(c))
        po[j++]=c;
        else if(c=='(')
        {
            temp[++top]=c;
        }
        else if(c==')')
        {
            while(temp[top]!='('&&top!=-1)
            po[j++]=temp[top--];
            top--;
        }
        else
        {
            while(top!=-1&&pre(c)<=pre(temp[top]))
            po[j++]=temp[top--];
            temp[++top]=c;
        }
    }
    while(top!=-1)
    {
        po[j++]=temp[top--];
    }
    po[j]='\0';
    printf("%s",po);
}