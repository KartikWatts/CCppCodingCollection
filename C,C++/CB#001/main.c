#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,test=1,save,n,i,j,a[100];
    //print no. of test cases
    scanf("%d",&t);

    while(test<=t)
    {
        //Enter no. of friends
        scanf("%d",&n);
        save=n;
        for(i=0;i<n;i++)
        {
            //Enter Party day
            scanf("%d",&a[i]);
        }

        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]==a[j])
                    {
                        save=save-1;
                        break;
                    }
            }
        }
        printf("%d\n",save);
        test++;
    }
    return 0;
}
