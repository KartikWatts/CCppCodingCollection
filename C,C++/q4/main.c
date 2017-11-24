#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,k,count=0;
    int a[10]={0,1,2,3,4,5,6,7,8,9};
    for(i=0;i<10;i++)
    {
        for(j=i+1;j<10;j++)
        {
            for(k=i+2;k<10;k++)
            {
                if((a[i]+a[j]+a[k])%3 ==0)
                    count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}
