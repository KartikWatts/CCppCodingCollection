#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,n,m,c,i,j,count;
    scanf("%d",&T);
    while(T>0 && T<=100)
    {
        count=0;
        scanf("%d",&n);
        scanf("%d",&m);
        scanf("%d",&c);
        if(n>=1 && m<=1000000 && c>=1 && c<=10000)
        {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if((i*j)==c)
                {
                    count++;
                }
            }
        }
        printf("%d\n",count);
        }
        T--;
    }

    return 0;
}
