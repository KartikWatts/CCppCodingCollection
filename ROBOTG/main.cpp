#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{
    int t,n,m,mu,nu,i,f,minn,minm;
    char s[100];
    cin>>t;
    while(t>0)
    {
        f=0;
        mu=0;
        nu=0;
        cin>>n>>m;
        cin>>s;
        minn=n-nu;
        minm=m-mu;
        for(i=0;s[i]!='\0';i++)
        {
            if(n-nu<minn)
                minn=n-nu;
            if(m-mu<minm)
                minm=m-mu;
            if(s[i]=='R')
            {
                mu++;
            }
            if(s[i]=='L')
            {
                mu--;
            }
            if(s[i]=='U')
            {
                nu++;
            }
            if(s[i]=='D')
            {
                nu--;
            }
            if(mu>=m || -(mu)>=minm)
            {
                f=1;
                cout<<"unsafe"<<endl;
                t--;
                break;
            }
            if(nu>=n || -(nu)>=minn)
            {
                f=1;
                cout<<"unsafe"<<endl;
                t--;
                break;
            }
        }
        if(f!=1)
        {
            cout<<"safe"<<endl;
        t--;
        }
    }
    return 0;
}
