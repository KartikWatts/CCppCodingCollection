#include <stdio.h>
#include <stdlib.h>
#include<math.h>
int main()
{
    int m,count;
    for(m=1;m<=5000;m++)
    {
        if(sqrt(m)==sqrt(m+125))
            count++;
    }
    printf("Total Integers= %d",count);
    return 0;
}
