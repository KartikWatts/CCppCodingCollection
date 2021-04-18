#include <iostream>

using namespace std;

int main()
{
    int n,k,i,j;
    int a[n][1],breaky,count,y,x,forbidden[2*n],ans=0;

    for(i=0;i<2*n;i++)
    {
        forbidden[i]=0;
    }

    cin>>n>>k;
    for(i=0;i<n-1;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }

    for(i=0;i<n-1;i++)
    {
        cout<<a[i][0]<<a[i][1]<<endl;
    }

     for(i=0;i<n-1;i++)
    {
        count=0;
        breaky=0;
        for(y=0;y<2*n;y++)
        {
            if(a[i][0]==forbidden[y] || a[i][1]==forbidden[y])
            {
                breaky=1;
                break;
            }
        }
        if(breaky==1)
            break;
        for(j=0;j<n;j++)
        {
            if(a[j][0]==a[i][1] || a[j][1]==a[i][1])
            {
                count++;
                if(count==k)
                {
                    ans++;
                    break;
                }
            }
        }
        for(x=0;x<2*n;x=x+2)
        {
                forbidden[x]=a[i][0];
                forbidden[x+1]=a[i][1];
        }
    }

    cout<<ans;
    return 0;
}
