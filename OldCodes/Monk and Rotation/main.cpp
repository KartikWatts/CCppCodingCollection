#include <iostream>

using namespace std;

int main()
{
    int T,N,K,i,a[10000],temp1,temp2,flag;
    cin>>T;
    if(T<1 || T>20)
        return 1;
    while(T>0)
    {
        flag=0;
        cin>>N>>K;
        if(N<1 || N>100000 || K<0 || K>1000000)
            break;
        for(i=0;i<N;i++)
        {
            cin>>a[i];
            if(a[i]<0 || a[i]>1000000)
            {
                flag=1;
                break;
            }
        }

        if(flag==1)
            break;
        while(K>0)
        {
            temp1=a[0];
            for(i=1;i<N;i++)
            {
                temp2=a[i];
                a[i]=temp1;
                temp1=temp2;
            }
            a[0]=temp1;
            K--;
        }

        for(i=0;i<N;i++)
        {
            cout<<a[i]<<" ";
        }
        T--;
    }
    return 0;
}
