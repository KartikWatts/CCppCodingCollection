#include <iostream>

using namespace std;

int main()
{
    int N,i,max,winner,j;
    cin>>N;
    int a[N],b[N],A[N],B[N];
    i=0;
    while(N--)
    {
        cin>>a[i]>>b[i];
        A[i]=0;
        B[i]=0;
        for(j=0;j<=i;j++)
        {
            A[i]=A[i]+a[j];
            B[i]=B[i]+b[j];
        }
        if(i==0)
        {
            if(a[0]>b[0])
            {
                max=a[0]-b[0];
                winner=1;
            }
            else if(b[0]>a[0])
            {
                max=b[0]-a[0];
                winner=2;
            }
        }
        else
        {
        if(A[i]>B[i] && A[i]-B[i]>max)
        {
            max=A[i]-B[i];
            winner=1;
        }
        else if(B[i]>A[i] && B[i]-A[i]>max)
        {
            max=B[i]-A[i];
            winner=2;
        }
        }
        i++;
    }
    cout<<winner<<" "<<max;
    return 0;
}
