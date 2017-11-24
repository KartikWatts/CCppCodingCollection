#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int T,N,num,temp,ans,n;
    cin>>T;
    while(T--)
    {
        num=0;
        cin>>N;
        temp=N;
        while(temp)
        {
            num++;
            temp=temp/10;
        }
        ans=0;
        while(N)
        {
            n=N%10;
            ans=ans+n*pow(10,num-1);
            N=N/10;
            num--;
        }
        cout<<ans<<endl;
    }
    return 0;
}
