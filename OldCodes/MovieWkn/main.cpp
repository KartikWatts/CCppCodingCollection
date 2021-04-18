#include <iostream>

using namespace std;

int main()
{
    int T,n,i,L[100],R[100],max,movie;
    cin>>T;
    while(T>0)
    {
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>L[i];
        for(i=1;i<=n;i++)
            cin>>R[i];

        max=L[1]*R[1];
        movie=1;
        for(i=2;i<=n;i++)
        {
                if(L[i]*R[i]>max)
                {
                    max=L[i]*R[i];
                    movie=i;
                }
                if(L[i]*R[i]==max)
                {
                    if(R[i]>R[movie])
                        {
                            max=L[i]*R[i];
                            movie=i;
                        }
                }
        }
        cout<<movie<<endl;

        T--;
    }
    return 0;
}
