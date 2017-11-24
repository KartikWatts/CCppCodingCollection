#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum,sumf,temp,suml=0,i,c,n,x,count=0;
    for(n=10;n<=99;n++)
    {
        sum=0;
        sumf=0;
        temp=n;
        x=100;
    while(temp!=0)
    {
        c=temp%10;
        sum=sum+x*c;
        temp=temp/10;
        x=x/10;
    }
        for(i=1;i<=16;i++)
        {
            if((n+sum)-(i*i)==0)
                count++;
        }
    }

    printf("total difdiodigits=%d",count);
    return 0;
}
