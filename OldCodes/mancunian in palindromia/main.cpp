#include <iostream>
#include <string.h>
using namespace std;
struct fr
{
    char str[50];
    int pal;
};

int main()
{
    int N,L,i,x,j,k,ans=0;
    char demo[50];
    fr F[10];
    cin>>N>>L;
    if(N>=1 && N<=10 && L>=1 && L<=50)
    {
        for(i=0;i<N;i++)
        {
            F[i].pal=0;
            cin>>F[i].str;
            x=strlen(F[i].str);
            if(x>L)
                return 1;
            if(x%2==0)
            {
                for(j=0;j<(x/2);j++)
                {
                    for(k=x-1;k>=x/2;k--)
                    {
                        if(F[i].str[j]==F[i].str[k])
                            F[i].pal=1;
                        else
                            F[i].pal=0;
                    }
                }
                if(F[i].pal==0)
                {

                }
            }
            else
            {
                for(j=0;j<(x-1)/2;j++)
                {
                    for(k=x-1;k>(x-1)/2;k--)
                    {
                        if(F[i].str[j]==F[i].str[k])
                            F[i].pal=1;
                        else
                            F[i].pal=0;
                    }
                }
            }
            ans=ans+F[i].pal;
        }
    cout<<ans;

    }
    return 0;
}
