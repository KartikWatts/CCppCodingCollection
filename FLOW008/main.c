#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,N[1000],i=0,test=0;
    scanf("%d",&T);
    while(test<T && T<=1000)
    {
        scanf("%d",&N[i]);
        i++;
        test++;
    }
    for(i=0;i<T;i++)
    {
        if(N[i]>=-20 && N[i]<=20 && T<=1000)
        {
            if(N[i]<10)
                printf("What an obedient servant you are!\n");
            else
                printf("-1\n");
        }
    }
    return 0;
}
