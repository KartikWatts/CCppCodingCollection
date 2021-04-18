#include <iostream>

using namespace std;

int main()
{
    int n,q,i,query,l,r,x,y,count;
    cin>>n>>q;
    int a[n];
    for(i=1;i<=n;i++)
        cin>>a[i];
    while(q--)
    {
        count=0;
        cin>>query;
        if(query==1)
        {
            cin>>l>>r>>x;
            for(i=l;i<=r;i++)
                a[i]=a[i]*x;
        }
        if(query==2)
        {
            cin>>l>>r>>x>>y;
            for(i=l;i<=r;i++)
            {
                if(a[i]*x>=y)
                    count++;
            }
            cout<<count<<endl;
        }
    }
    return 0;
}
