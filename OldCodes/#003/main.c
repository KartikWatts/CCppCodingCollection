#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;
    float b;
    scanf("%d",&a);
    scanf("%f",&b);
    if(a%5==0 && b>a+0.50)
    {
        b=b-a-0.50;
    }
    printf("%.2f",b);
    return 0;
}
