#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void prime(int);

int main()
{
    int T;
    scanf("%d",&T);
    prime(T);
    return 0;
}

void prime(int T)
{
    int L,i,j,k,flag=0,sum=0,a[6],cs=0,c,d;
    while(cs<T)
    {
        scanf("%d",&L);
        for(i=0;i<6;i++)
        scanf("%d",&a[i]);

    for(i=0;i<L;i++)
    {
       for(j=0;j<6;j++)
       {
           for(k=0;k<6;k++)
           {
           if(j<5)
           {
                c=(pow(i,2)+a[j+k]);
                d=(pow(i,2)+a[j]);
           }
           if(j==5)
           {
               c=pow(i,2)+a[j];
               d=pow(i,2)+a[0+k];
           }
           if(c%d==0)
            {
                flag=0;
            }
            if(flag==0)
                break;
            else flag=1;
           }
       }
       if(flag==1)
       {
           sum=sum+i;
       }
    }
    printf("%d\n",sum);
    }
}
