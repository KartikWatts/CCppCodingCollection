#include <iostream>

using namespace std;

int main()
{
    int t,n,i,j;
    cin >> t;
    while(t>0)
    {
        int count=0;
        if(n==1)
        {
            cout<<1;
            break;
        }
        cin>>n;
        int start[n],end[n];
        for(i=0;i<n;i++)
        {
            if(start[i]> end[i])
            {

            }

            cin>>start[i]>>end[i];
            if(start[n]>=360)
            {
                start[n]=start[n]-360;
            }
            if(end[n]>=360)
            {
                end[n]=end[n]-360;
            }
        }

        for(i=0;i<n;i++)
        {
            for(j=1;j<n-1;j++)
            {
                if(start[j]>=start[i] || start[j]<=end[i] || end[j]>=start[i] || end[j]<=end[i])
                count++;
            }
        }
        cout <<count<<endl;
        t--;
    }
    return 0;
}
