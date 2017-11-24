#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,c,sum=0,temp,s,sum2=0,count=0;
    /*for(n=100;n<=999;n++)
    {*/
         n=200;
        temp=n;
    while(temp!=0)
    {
        c=temp%10;
        sum=sum+c;
        temp=temp/10;
    }
    printf("sum=%d",sum);
    /*while(sum!=0)
    {
        s=sum%10;
        sum2=sum2+s;
        sum=sum/10;
    }*/
    if(sum==2|| sum==11 ||sum==20)
        count++;
    }
    printf("total integers=%d",count);
    return 0;
}
