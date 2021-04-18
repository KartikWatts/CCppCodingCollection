//A Logical Creation by KartiK ArorA.KK™.
//Freely distributed in public interest for Open Source Development.
#include <iostream>

using namespace std;

int main()
{
    int T,four,N;
    cin>>T;
    while(T--)
    {
        cin>>N;
        four=0;
        while(N)
        {
            if(N%10==4)
                four++;
            N=N/10;
        }
        cout<<four<<endl;
    }
    return 0;
}
