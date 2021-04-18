#include <iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    int T,n,i,sp1,sp2,j,k;
    cin>>T;
    while(T>0)
    {
        cin>>n;
        char c[n],nw[n];
        gets(c);
        gets(c);
        scanf(" %[^\t\n]s",&c);
        cout<<c<<endl;
        sp1=-1;
        for(i=0;i<n;i++)
        {
            if(c[i]==' ')
            {
                sp2=i;
                cout<<"sp2="<<sp2<<endl;
                for(j=sp1+1,k=1;j<sp2;j++,k++)
                {
                    cout<<"c[j]="<<c[j]<<endl;
                    nw[j]=c[sp2-k];
                    cout<<"new n[j]="<<c[j]<<endl;
                }
                sp1=sp2;
                cout<<"sp1="<<sp1<<endl;
            }
        }
        puts(nw);
        //cout<<nw<<endl;
        T--;
    }
    return 0;
}
