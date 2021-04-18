//A Logical Creation by KartiK ArorA.KK™.
//Freely distributed in public interest for Open Source Development.
#include <iostream>

using namespace std;

int main()
{
    int T,sum,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        sum=0;
        while(N)
        {
            sum=sum+N%10;
            N=N/10;
        }
        cout<<sum<<endl;
    }
    return 0;
}
