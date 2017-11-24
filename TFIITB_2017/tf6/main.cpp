#include <iostream>

using namespace std;

int main()
{
    int i,j,d,sumd,sumtotal=0;
    for(i=1;i<=100;i++)
    {
        for(j=1;j<=100;j++)
        {
            sumd=0;
            for(d=1;d<=j;d++)
            {
                if(j%d==i%d)
                {
                    sumd=sumd+d;
                }
            }
            sumtotal=sumtotal+sumd;
        }

    }
    cout<< sumtotal;
    return 0;
}
