#include <iostream>

using namespace std;

int main()
{
    int n,countf,sumf,i,ans,prime=1;

    for(n=10;n<=4000;n++)
    {
        countf=0;
        prime=1;
        sumf=0;
        for(i=1;i<n;i++)//ek no. ke divisors nikalne  ke liye
        {
            if(n%i==0)
            {
                countf++;
                prime=1;
                sumf=sumf+i;
            }
        }

        for(i=2;i<n;i++)//us no. ka sumf prime he ya nhi pta karne ke liye
        {
            if(sumf%i==0)
            {
                prime=0;
                break;
            }
        }
        if(countf%2==0 && prime==1)
        {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
