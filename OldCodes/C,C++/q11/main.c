#include <stdio.h>
#include <stdlib.h>

int main()
{
        int a,b=1,sum=0,i;
        for(a=1;a<=1000;a++)
        {
            {
                if(((a+13*b)%11==0) &&((a+11*b)%13==0))
                    printf("%d %d\n",a,b);
            }
            b++;
        }

        for(i=100;i<=999;i++)
            sum=sum+i;
        printf("%d",sum);
        return 0;
}
