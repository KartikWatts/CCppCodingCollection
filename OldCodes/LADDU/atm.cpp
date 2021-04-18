#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,x;
    float b;
    scanf("%d",&a);
    scanf("%f",&b);
    x=a/5;
    if(a%5==0 && b>a+0.50)
    {
        b=b-(x*0.50);
    }
    printf("%.2f",b);
    return 0;
}
