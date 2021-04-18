#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int N,i,j,k,sum=0,s;
    scanf("%d",&N);
    int a[N];
    for(i=0;i<N;i++)
    {
        scanf("%d",&a[i]);
    }

    for(i=0;i<N-2;i++)
    {
        for(j=i+1;j<N-1;j++)
        {
            for(k=j+1;k<N;k++)
            {
                s=(a[i]+a[j]+a[k])/(a[i]*a[j]*a[k]);
                printf("%d\n",s);

                sum=sum+s;
            }
        }
    }
    printf("sum=%d",sum);

    return 0;
}
