#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,c,sum=0,temp,count=0,digi=0;

    for(n=100000;n<=999999;n++)
    {
        sum=0;
        digi=0;
        temp=n;
        i=0;
    while(temp!=0)
    {
        a[i]=temp%10;
        sum=sum+a[i];
        temp=temp/10;
        i++;
    }

    for(i=0;i<6;i++)
    {
        for(j=i+1;j<6;j++)
        {
            if(a[i]==a[j])
            {
                while(a[j]!=NULL)
                {
                    a[j]=a[j+1];
                }
            }
        }
    }

    /*while(sum!=0)
    {
        s=sum%10;
        sum2=sum2+s;
        sum=sum/10;
    }*/
    if(sum==10 &&)
       {
           count++;
       }
    }

    printf("total integers=%d",count);
    return 0;
}
