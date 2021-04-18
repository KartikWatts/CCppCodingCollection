#include <iostream>

using namespace std;

int main()
{
    int T,zeros,j;
    long long int n;
    cin>>T;
    while(T>0)
    {
        zeros=0;
        cin>>n;
            for(j=5;j<1000000000;j=j*5)
            {
                zeros=zeros+n/j;
                if(n/j==0)
                    break;
            }
        cout<<zeros<<endl;
        T--;
    }
    return 0;
}
