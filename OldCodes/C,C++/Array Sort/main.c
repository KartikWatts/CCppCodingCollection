#include <stdio.h>
#include <stdlib.h>

int main()
{
    int j,a[7]={4,7,6,3,2,5,1},i,temp;
    printf("Array Created is\n");
    for(i=0;i<=6;i++)
    {
        printf("%d\t",a[i]);
    }

    //FOR SORTING
    for(i=0;i<=6;i++)
    {
        for(j=i+1;j<=6;j++)
        {
        if(a[i]>a[j])
        {
            temp=a[j];
            a[j]=a[i];
            a[i]=temp;
        }
        }
    }
    printf("\nSorted Array is\n");
    for(i=0;i<=6;i++)
    {
        printf("%d\t",a[i]);
    }

    return 0;
}
