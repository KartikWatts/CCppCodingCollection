#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T,N,M,i,E[77],ptr,p,j,temp,pE[77],total=0;
    scanf("%d",&T);

    while(T>0)
    {
        if(T>8)
            exit(1);
        total=0;
        scanf("%d",&N);
        scanf("%d",&M);
        ptr=N;

    if(N>=7 && M<=77777)
    {
        for(i=0;i<N;i++)
        {
            scanf("%d",&E[i]);
            if(E[i]<7 || E[i]>77)
                exit(1);
        }
        while(M%ptr!=0)
        {
            ptr--;
            if(M%ptr==0)
            {
                p=M/ptr;
            }
        }

        for(i=0;i<N;i++)
        {
            for(j=i+1;j<N;j++)
            {
                if(E[j]>E[i])
                {
                    temp=E[i];
                    E[i]=E[j];
                    E[j]=temp;
                }
            }
        }

        for(i=0;i<ptr;i++)
        {
            pE[i]=p;
        }
        for(i=ptr;i<N;i++)
        {
            pE[i]=0;
        }

        for(i=ptr;i<N;i++)
        {
            pE[i]=E[i]*ptr;
            total=total+pE[i];
        }
    }
    if(T<0 || T>8 || N<7 || M>7777)
        exit(1);
    printf("%d\n",total);
    T--;
    }
    return 0;
}
