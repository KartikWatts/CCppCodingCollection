#include <iostream>
#include <string.h>
using namespace std;

struct str
{
    char string[20];
};
int main()
{
    int n,q,i,query,ch,j,f,L,R,place,l;
    char prefix[20],repstr[20];
    cin>>n>>q;
    struct str S[n+2];
    for(i=1;i<=n;i++)
    {
        cin>>S[i].string;
    }
    for(l=0;l<q;l++)
    {
        int count=0;
        cin >>query;

        if(query==1)
        {
            cin>>L>>R;
            cin>>prefix;
            for(ch=0;prefix[ch]!='\0';ch++)
            {

            }
            for(i=L;i<=R;i++)
            {
                f=0;
                for(j=0;j<ch;j++)
                {
                    if(S[i].string[j]!= prefix[j])
                    {
                        f=1;
                        break;
                    }
                }
                if(f!=1)
                {
                    count++;
                }
            }
            cout<<count<<endl;
        }

        if(query==2)
        {
            cin>>place;
            cin >> repstr;
            for(i=0;S[place].string[i]!='\0';i++)
            {

            }
            for(j=0;repstr[j]!='\0';j++)
            {

            }
            if(j>=i)
                ch=j;
            else
                ch=i;
            for(i=0;i<ch;i++)
            {
                S[place].string[i]=repstr[i];
            }
        }
    }

    return 0;
}
