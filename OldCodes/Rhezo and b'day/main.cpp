#include <iostream>

using namespace std;

int main()
{
    char s[1000],c;
    int p,i,n,k,temp,max,end,flag,count;
    cin>>s;
    cin>>c;
    cin>>p;
    end=0;
    i=0;
    while(s[i]!='\0')
        {
            end++;
            i++;
        }
    max=0;
    flag=0;
    n=0;
    k=n+3;
    for(i=n;i<k;i++)
    {
        if(s[i]==c)
            temp++;
        if(i==k-1)
        {
            if(temp>max)
            {
                max=temp;
                temp=0;
                n=k;
                k=n+3;
                continue;
            }
        }
    }
    count=0;
    n=end-1;
    k=n-3;
        for(i=n;i>k;i--)
        {
            if(s[i]==c)
                count++;
            if(count==max)
            {
                flag=1;
                if(s[i+2]!='\0')
                cout<<i+2;
                else if(s[i+1]!='\0')
                    cout<<i+1;
                else cout<<i;
                break;
            }
            if(i==k+1)
            {
                n=k;
                k=n-3;
                count=0;
                continue;
            }

        }
    if(flag!=1)
        cout<<"-1";
    return 0;
}
