#include <iostream>

using namespace std;

int main()
{
    int test=0,T,n,c[100000],i,j,H[100000];
    cin>>T;
    while(test<T && T<=10)
    {
        cin>>n;
        if(n>=2 && n<=1000000)
        {
            for(i=0;i<n;i++)
            {
                c[i]=1;
                cin>>H[i];
                if(H[i]<1 && H[i]>10000000)
                    return 1;
            }

            for(i=n-1;i>0;i--)
            {
                j=i-1;
                while(j>=0 && H[j]<=H[i])
                    {
                        c[i]++;
                        j--;
                    }
            }
            for(i=0;i<n;i++)
                cout<<c[i]<<" ";
                cout<<endl;
        }
        test++;
    }
    return 0;
}
