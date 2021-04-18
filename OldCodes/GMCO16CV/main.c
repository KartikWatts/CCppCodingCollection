#include <stdio.h>
#include <stdlib.h>

int main()
{
    int N,M,i,j,sum,flag=1,cas=1,fl=1,C,k,z,l,p;

    struct emp
    {
        int X[1500];
        int Y[1500];
        int malt;
        int arr;
        int T;
    }e[100];
    scanf("%d",&C);

    while(C>0 && C<=100)
    {
        scanf("%d",&N);
        scanf("%d",&M);
        sum=0;
        flag=1;
        fl=1;
    if(N>=1 && N<=10 && M>=1 && M<=100)
    {
        for(i=0;i<M;i++)
        {
            scanf("%d",&e[i].T);
            e[i].malt=0;
            for(j=0;j<e[i].T;j++)
            {
                scanf("%d",&e[i].X[j]);
                scanf("%d",&e[i].Y[j]);

                if(e[i].Y[j]==1)
                {
                    e[i].malt=e[i].malt+1;
                    e[i].arr=1;
                }
                else
                    e[i].arr=0;
            }
            if(e[i].malt>1)
                flag=0;

        }

        for(i=0;i<M;i++)
        {
            for(j=0;j<e[i].T;j++)
            {
                sum=sum+e[i].X[j]+e[i].Y[j];
            }
        }

    if(sum<=3000 && flag!=0)
    {
        for(i=0;i<M;i++)
        {
            for(j=i+1;j<M;j++)
            {
                for(k=0;k<e[i].T;k++)
                {
                    for(z=0;z<e[j].T;z++)
                    {
                    if(e[i].X[k]==e[j].X[z])
                    {
                        printf("X equal hua");
                        for(p=0;p<e[i].T;p++)
                        {
                        for(l=0;l<e[j].T;l++)
                        {
                            if(e[i].Y[p]!=e[j].Y[l])
                            {
                                printf("Y nhi equal hua\n");
                                fl=0;
                            }
                        }
                        }
                    }
                    }
                }
            }
        }

        if(fl==0)
        {
            printf("Case #%d: IMPOSSIBLE TO SATISFY ALL\n",cas);
            cas++;
        }
        else
        {
            printf("Case #%d: YES ",cas);
            for(i=0;i<N;i++)
                printf("%d ",e[i].arr);
                printf("\n");
        }
    }
    }
        C--,cas++;
    }
    return 0;
}
