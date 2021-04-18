#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,q,i,a[1000],max,min,m;
    scanf("%d",&n);
    scanf("%d",&q);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    max=a[0];
    for(i=0;i<n;i++)
    {
        if(max<a[i])
            max=a[i];
    }

    min=a[0];
    for(i=0;i<n;i++)
    {
        if(min>a[i])
            min=a[i];
    }

    while(q>0)
    {
        scanf("%d",&m);
            if(m<min || m>max)
            printf("No\n");
            else printf("Yes\n");
            q--;
    }
        return 0;
}
