#include <iostream>

using namespace std;

int main()
{
    int arr[15]={130,298,466,634,802,970,1138,1306,1474,1642,1810,1978,2146,2314};
    int rem[20],i,ans,sumk=0,k;
    for(k=2;k<=2314;k++)
    {

        for(i=0;i<14;i++)
        {
            rem[i]= arr[i]%k;
        }

        for(i=0;i<13;i++)
        {
            if(rem[i]==rem[i+1])
            {
                ans=1;
            }
            else
            {
                ans=0;
                break;
            }
        }
        if(ans==1)
        {
            sumk++;
        }
    }
    cout<<sumk;
    return 0;
}
