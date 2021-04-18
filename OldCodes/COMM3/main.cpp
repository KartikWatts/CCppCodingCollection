#include <iostream>
#include<math.h>
using namespace std;

struct ranger
{
    int x;
    int y;
};
int main()
{
    ranger r[3];
    int T,R,i;
    float l1,l2,l3;
    cin>>T;
    while(T--)
    {
        cin>>R;
     for(i=0;i<=2;i++)
     {
         cin>>r[i].x>>r[i].y;
     }
        l1=sqrt(pow(r[0].x-r[1].x,2)+pow(r[0].y-r[1].y,2));
        l2=sqrt(pow(r[0].x-r[2].x,2)+pow(r[0].y-r[2].y,2));
        l3=sqrt(pow(r[1].x-r[2].x,2)+pow(r[1].y-r[2].y,2));
        if(l1<=R && (l2<=R || l3<=R))
            cout<<"yes";
        else if(l2<=R && (l1<=R || l3<=R))
            cout<<"yes";
        else if(l3<=R && (l2<=R || l1<=R))
            cout<<"yes";
        else cout<<"no";
        cout<<endl;
    }
    return 0;
}
