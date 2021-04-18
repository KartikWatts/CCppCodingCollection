#include <iostream>
using namespace std;
int multiply(int x,int a[],int size)
{
    int carry=0;
    int i;
    for(i=0;i<size;i++)
    {
        int prod=a[i]*x+carry;
        a[i]=prod%10;
        carry=prod/10;
    }
    while(carry)
    {
        a[size]=carry%10;
        carry=carry/10;
        size++;
    }
    return size;
}

void factorial(int n)
{
    int a[200],size=1,i;
    a[0]=1;
    for(i=2;i<=n;i++)
        size=multiply(i,a,size);
    for(i=size-1;i>=0;i--)
        cout<<a[i];
    cout<<endl;
}

int main()
{
    int T,n;
    cin>>T;
    while(T>0)
    {
        cin>>n;
        factorial(n);
        T--;
    }
    return 0;
}
