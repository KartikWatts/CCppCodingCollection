#include <iostream>

using namespace std;

int main()
{

    int i,j,count=0,no,nt,nh,nth,ntth;
    int k=0,good[100000];
    for(i=1;i<=100000;i++)
    {
        no=i%10;
        nt=(i%100)/10;
        nh=(i%1000)/100;
        nth=(i%10000)/1000;
        ntth=i/10000;

        int ar[5]={no,nt,nh,nth,ntth};
        for(j=0;j<=4;j++)
        {
            if(ar[j]==3 || ar[j]==8)
                {
                    good[k]=i;
                    k++;
                }
            else
                break;
        }
    }

    for(i=1;i<100000;i++)
    {
        k=0;
        while(good[k]!='\0')
        {
            if(i%good[k]==0)
            {
                count++;
                k++;
                break;
            }
            k++;
        }
    }
    cout<<count;
    return 0;
}
