#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,a[100],odd=0,even=0;
    printf("Enter No. of soldiers\n");
    scanf("%d",&n);
    if(n<0 || n>100)
    {
        printf("Error!! Value should be within the limit 0 to 100\n");
        exit(1);
    }

    printf("Enter No. of Weapons for each Soldier\n");
    for(i=0;i<n;i++)
    {
        printf("Enter No. of Weapons for Soldier %d\n",i+1);
        scanf("%d",&a[i]);
    }
    if(a[i]<0 || a[i]>100)
    {
        printf("Error!!Value should be within the range 0 to 100\n");
        exit(2);
    }
    for(i=0;i<n;i++)
    {
        if(a[i]%2==0)
            even++;
        else odd++;
    }
    if(even>odd)
        printf("READY FOR BATTLE\n");
        else
            printf("NOT READY\n");
    return 0;
}
