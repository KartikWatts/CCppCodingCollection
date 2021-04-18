#include <iostream>

using namespace std;

int main()
{
    int T,N,pack;
    cin>>T;
    while(T--)
    {
        cin>>N;
        if(N==1)
            pack=1;
        else
            pack=(N/2)+1;
        cout<<pack<<endl;
    }
    return 0;
}
