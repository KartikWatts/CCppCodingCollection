#include <iostream>

using namespace std;

int main()
{
    int i,sum,num=29312017,n=2,count;
    int arprev[20], arnext[20];
    while(num/n>0)
    {
        num = 29312017;
        for(i=0;i<=n/2;i++)
        {
            arprev[i]=num-1;
            num=num-1;
        }
        num = 29312017;
        for(i=0;i<=n/2;i++)
        {
            arnext[i]=num+1;
            num=num+1;
        }
        num = 29312017;
        for(i=0;i<=n/2;i++)
        {
            sum=num+arprev[i];
        }
        for(i=0;i<=n/2;i++)
        {
            sum=num+arnext[i];
        }

        if(sum==num)
            count++;
    }
    cout<<count;
    return 0;
}
