#include <iostream>

using namespace std;

int main()
{
    int T,sum,D,N,i;
    cin>>T;
    while(T>0)
    {
        sum=0;
        cin>>D>>N;
        for(i=0;i<D;i++)
        {
            sum=(N*(N+1))/2;
            N=sum;
        }
        cout<<sum<<endl;
        T--;
    }
    return 0;
}
