#include <iostream>

using namespace std;

int main()
{
    int T,N,min,i,j,ans,flag;
    cin>>T;
    while(T--)
    {
        flag=0;
        cin>>N;
        int a[N],rem[N];
        min=51;
        for(i=0;i<N;i++)
        {
            cin>>a[i];
            if(a[i]<min)
            {
                min=a[i];
            }
        }
        for(i=min;i>1;i--)
        {
            for(j=0;j<N;j++)
            {
                rem[j]=a[j]%i;
                if(rem[j]!=0)
                {
                    break;
                }
                if(j==N-1)
                {
                    if(rem[j]==0)
                    {
                        flag=1;
                        ans=i;
                        break;
                    }
                }
            }
            if(flag==1)
                break;
        }
        for(i=0;i<N;i++)
        {
            if(flag==1)
                cout<<a[i]/ans<<" ";
            else
                cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
