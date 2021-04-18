#include <iostream>

using namespace std;

int main()
{
    int n,k,i,count=0;
    cin>>n>>k;
    int t[n];
    for(i=0;i<n;i++)
    {
        cin>>t[i];
    }
    for(i=0;i<n;i++)
    {
        if((t[i]%k)==0)
            count++;
    }
    cout<<count;
    return 0;
}
