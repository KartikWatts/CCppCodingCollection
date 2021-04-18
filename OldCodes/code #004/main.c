#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test,i,studs,given[10000],taken[10000],ans;
    scanf("%d",&test);

    while(test>0)
    {
        ans=0;
        scanf("%d",&studs);
        for(i=0;i<studs;i++)
        {
           scanf("%d",&given[i]);
        }
        for(i=0;i<studs;i++)
        {
            scanf("%d",&taken[i]);
        }

        for(i=0;i<studs;i++)
        {
            if(i==0)
            {
                if(given[0]>=taken[0])
                    ans++;
            }
            else if((given[i]-given[i-1])>=taken[i])
                ans++;
        }

        printf("%d\n",ans);
        test--;
    }
    return 0;
}
