#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>
int main()
{
    int test=1,t,n,m,i,j;
    uint32_t fact=1;
    //Enter test cases
    scanf("%d",&t);
    while(test<=t)
    {
        //Enter Value of n
        scanf("%d",&n);
        //Enter Value of m
        scanf("%d",&m);
        const unsigned int mod=pow(10,m);

        for(i=1;i<=n;i++)
        {
            fact=(fact*i);
            if(i==n)
            {
                for(j=n;j>=1;j--)
                fact=(fact*j)%mod;
            }
        }
        printf("%"PRId32"\n",fact);

        test++;
    }

    return 0;
}
