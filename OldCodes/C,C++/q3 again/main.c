#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,c,sum=0,temp,count=0;

    for(n=10000000;n<=99999999;n++)
    {
        sum=0;
        temp=n;
    while(temp!=0)
    {
        c=temp%10;
        sum=sum+c;
        temp=temp/10;
    }

    /*while(sum!=0)
    {
        s=sum%10;
        sum2=sum2+s;
        sum=sum/10;
    }*/
    if(sum==4)
       {
           count++;
       }
    }

    printf("total integers=%d",count);
    return 0;
}
