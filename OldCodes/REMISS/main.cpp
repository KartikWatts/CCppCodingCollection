//A Logical Creation by KartiK ArorA.KK™.
//Freely distributed in public interest for Open Source Development.
#include <iostream>

using namespace std;

int main()
{
    int T,A,B,min,max;
    cin>>T;
    while(T--)
    {
        cin>>A>>B;
        if(A>B)
            min=A;
        else min=B;
        max=A+B;
        cout<<min<<" "<<max<<endl;
    }
    return 0;
}
