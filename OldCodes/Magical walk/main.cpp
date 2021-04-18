#include <iostream>

using namespace std;

int main()
{
    int test=0,T,K,s,m,i,a[1000],c,flag,start;
    cin>>T;
    while(test<T)
    {
        cin>>K;
        for(i=1;i<=K;i++)
        {
            cin>>a[i];
        }
        cin>>s;
        cin>>m;
        cin>>c;
        if(m<a[s])
        {
            start=-1;
            flag=0;
        }
        else if(m>=a[s])
        {
            start=s;
            flag=1;
        }
            while(m>=a[start] && flag==1)
            {
                m=m-a[start];
                if(start==1 && c==-1)
                    start=K;
                else if(start==K && c==1)
                    start=1;
                else
                {
                    if(c==1)
                        start++;
                    if(c==-1)
                        start--;
                }
            }
            cout<<start<<endl;
            test++;
    }
    return 0;
}
