#include <iostream>

using namespace std;

int fact(int n)
{
    int ans=1,i;
    for(i=n;i>0;i--)
    {
        ans= ans*i;
    }
    return ans;
}

float p(int n,int r)
{
    return (fact(n)/fact(r));
}

float c(int n,int r)
{
    return (fact(n)/(fact(r)*fact(n-r)));
}

int main()
{
    int choice,n,r;
    cout<<"Enter choice=>1: Factorial 2: Permutation 3: Combination\t";
    cin>>choice;
    if(choice==1)
    {
        cin>>n;
        cout<<"Factorial: "<<fact(n)<<endl;
    }
    if(choice==2)
    {
        cin>>n>>r;
        cout<<"Permutation: "<<p(n,r)<<endl;
    }
    if(choice==3)
    {
        cin>>n>>r;
        cout<<"Combination: "<<c(n,r)<<endl;
    }
    return 0;
}

