#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,temp,sum,a[5];
    int i,f=0,count=0;
    for(n=10000;n<=99999;n++)
    {
    i=0;
    sum=0;
    temp=n;
    while(temp!=0)
    {
        a[i]=temp%10;
        sum=sum+a[i];
        temp=temp/10;

        i++;
    }

    if(n%15==0)
    {
    for(i=0;i<5;i++)
    {
        if(a[i]==1 && a[i+1]==5)
            {
                count++;
        break;
            }
    }
    }
    }

    printf("Total digits =%d",count);
    return 0;
}
