#include <iostream>

using namespace std;

int main()
{
    int T,i,N,sum;
    cin>>T;
    while(T--)
    {
        cin>>N;
        int a[N];
        i=0;
        while(N)
        {
            a[i]=N%10;
            i++;
            N=N/10;
        }
        sum=a[0]+a[i-1];
        cout<<sum<<endl;
    }
    return 0;
}
