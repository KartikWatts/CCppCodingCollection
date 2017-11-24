#include <iostream>

using namespace std;

int main()
{
    int T,N,K,i,key;
    cin>>T;
    while(T>0)
    {
        cin>>N>>key;
        char str[N+1];
        int ascii[N+1];
        cin>>str;
        for(i=0;i<N;i++)
        {
            K=key;
            ascii[i]=int(str[i]);
            if(ascii[i]>=48 && ascii[i]<=57)
            {
                if(K>10)
                {
                    K=K%10;
                }
                if(ascii[i]+K>57)
                {
                    ascii[i]=47+(ascii[i]+K-57);
                }
                else
                    ascii[i]=ascii[i]+K;
            }
            if(ascii[i]>=65 && ascii[i]<=90)
            {
                if(K>26)
                {
                    K=K%26;
                }
                if(ascii[i]+K>90)
                {
                    ascii[i]=64+K+ascii[i]-90;
                }
                else
                    ascii[i]=ascii[i]+K;
            }
            if(ascii[i]>=97 && ascii[i]<=122)
            {
                if(K>26)
                {
                    K=K%26;
                }
                if(ascii[i]+K>122)
                {
                    ascii[i]=96+K+ascii[i]-122;
                }
                else
                    ascii[i]=ascii[i]+K;
            }
        }
        for(i=0;i<N;i++)
        {
            str[i]=char(ascii[i]);
        }
        cout<<str<<endl;
        T--;
    }
    return 0;
}
