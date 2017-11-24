#include <iostream>
#include<math.h>
using namespace std;

int main()
{
    int T,b,l;
    double min,max;
    cin>>T;
    while(T--)
    {
        cin>>b>>l;
        min=sqrt((l*l)-(b*b));
        max=sqrt((l*l)+(b*b));
        cout<<min<<" "<<max<<endl;
    }
    return 0;
}
