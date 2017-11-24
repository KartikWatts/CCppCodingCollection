#include <iostream>

using namespace std;

int main()
{
    int K,n,i,n9;
    char X[20],a[20];
    n=0;
    n9=0;
        cin>>X;
    cin>>K;
    while(X[n]!='\0')
    {
        a[n]=X[n]%10;
        if(a[n]==9)
            n9++;
        n++;
    }
    for(i=n-1;i>=n-K-n9;i--)
    {
        if(a[n]==9)
            i++;
        else
            a[i]=9;
    }
    for(i=n-1;i>=0;i--)
        cout<<a[i];
    return 0;
}
