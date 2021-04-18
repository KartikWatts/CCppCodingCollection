#include <iostream>

using namespace std;

int main()
{
    int T,i,count,flag;
    char s[100000];
    cin>>T;
    while(T>0)
    {
        cin>>s;
        flag=0;
        i=0;
        count=0;
        do
            {
                if(s[i]=='\0')
                    break;
                else
                {
                    if(s[i]!='<'&&s[i]!='>'&&s[i]!='*')
                    {
                        flag=1;
                        break;
                    }
                    if(s[i]=='>')
                    {
                        if(s[i+1]!='<')
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(s[i]=='<')
                    {
                        if(s[i+1]=='>')
                        {
                            count++;
                        }
                    }
                }
                i++;
            }
        while(s[i]!='\0');

        if(flag==1)
        {
            T--;
            continue;
        }
        cout<<count<<endl;
        T--;
    }
    return 0;
}
