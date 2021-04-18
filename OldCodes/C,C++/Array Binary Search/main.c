#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a[20],i,tmp,j,first,middle,last,search;
    printf("Enter total no. of elements\n");
    scanf("%d",&n);
    printf("Enter %d elements\n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                tmp=a[i];
                a[i]=a[j];
                a[j]=tmp;
            }
        }
    }

    printf("Enter the no. to be searched\n");
    scanf("%d",&search);
    first=0;
    last=n-1;
    middle=(first+last)/2;

    while(first<=last)
    {
        if(search<a[middle])
            last=middle-1;
        else if(search==a[middle])
        {
            printf("No. is found at position %d",middle+1);
            break;
        }
        else if(search>a[middle])
            first=middle+1;

            middle=(first+last)/2;
    }
    if(first>last)
        printf("No. NOT found");
    return 0;
}
