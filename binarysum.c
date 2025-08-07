#include<stdio.h>
#include<math.h>
#include<string.h>
void main()
{
    char a[]="11",b[]="1";
    int A=strlen(a),d=0,j;
    int B=strlen(b);
    for(int i=0,j=A-1;i<A;i++,j--)
    {
      d=d+(a[j]*pow(2,i));
    }
    printf("%d",d);
}