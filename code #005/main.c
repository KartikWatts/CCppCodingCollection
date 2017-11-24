#include <stdio.h>
#include <stdlib.h>

int report[10000],killer[10000];
int main()
{
    int total,i,j,k=0,flag=1;
    scanf("%d",&total);
    for(i=0;i<total;i++)
    {
        scanf("%d",&report[i]);
    }

    for(j=1;j<=total;j++)
    {
        flag=1;
        for(i=1;i<total;i++)
        {
            if(j==report[i])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            killer[k]=j;
            k++;
        }
    }

    for(i=0;i<k;i++)
    printf("%d ",killer[i]);

    return 0;
}
