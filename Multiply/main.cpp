#include <iostream>

using namespace std;

int main()
{
    int n,k,i,j,a[20],mul,carry;
    cout<<"Enter a no.\t";
    cin>>n;
    cout<<"Enter another no.\t";
    cin>>k;
    while(n)
    {
        a[i]=n%10;
        i++;
        n=n/10;
    }
    for(j=i-1;j>=0;j--)
    {
        cout<<a[j];
    }
    cout<<endl;
    carry=0;
    for(j=0;j<i;j++)
    {
        mul=a[j]*k+carry;
        a[j]=mul%10;
        carry=mul/10;
    }
    if(carry>0)
    {
        a[i]=carry;
        i++;
    }
    cout<<"Prod = ";
    for(j=i-1;j>=0;j--)
        cout<<a[j];
    return 0;
}
