#include <iostream>

using namespace std;

int main()
{
    int N,Q,i,a[1000],L,R,peak;
    cin>>N>>Q;
    for(i=1;i<=N;i++)
    {
        cin>>a[i];
    }
    while(Q>0)
    {
        peak=0;
        cin>>L>>R;
        for(i=L;i<=R;i++)
        {
            if(i==1)
            {
                if(a[1]>a[N] && a[1]>a[2])
                    peak++;
            }
            if(i==N)
            {
                if(a[N]>a[N-1] && a[N]>a[1])
                    peak++;
            }
            if(i!=1 && i!=N)
            {
                if(a[i]>a[i-1] && a[i]>a[i+1])
                    peak++;
            }
        }
        cout<<peak<<endl;
        Q--;
    }
    return 0;
}
