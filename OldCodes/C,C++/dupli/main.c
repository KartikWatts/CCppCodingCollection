#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[6]={4,3,2,4,2,1},i,j;
    for(i=0;i<6;i++)
    {
        for(j=i+1;j<6;j++)
        {
            if(a[i]==a[j])
            {
                for(z=j;z<6;z++)
                {
                    a[j]=a[j+1];
                }
                z
            }
        }
    }
    i=0;
    while(a[i])
    printf("%d\n",a[i]);
    return 0;
}
