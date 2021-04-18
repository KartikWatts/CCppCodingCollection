#include <iostream>

using namespace std;

int main()
{
    int a;
    cin>>a;
    while(a!=42)
    {
        if(a==42)
            break;
        cout<<a<<endl;
        cin>>a;
    }
    return 0;
}
