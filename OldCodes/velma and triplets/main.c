#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

int main()
{
    int64_t N,i,j,k,sum=0,s;
    scanf("%"PRId64"",&N);
    int64_t a[N];
    for(i=0;i<N;i++)
    {
        scanf("%"PRId64"",&a[i]);
    }

    for(i=0;i<N-2;i++)
    {
        for(j=i+1;j<N-1;j++)
        {
            for(k=j+1;k<N;k++)
            {
                s=(a[i]+a[j]+a[k])/(a[i]*a[j]*a[k]);
                sum=sum+s;
            }

        }
    }
    printf("%"PRId64"",sum);

    return 0;
}
