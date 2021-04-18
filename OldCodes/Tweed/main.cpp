#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int T,test=0,N,a[50],i;
    char str[5];
    cin>>T;
    while(test<T && T>=1 && T<=50)
    {
        int even=0,odd=0,flag=1,dee=1,dum=1;
        cin>>N;
        if(N>=1 && N<=50)
        {
            cin>>str;
            dee=strcmp(str,"Dee");
            dum=strcmp(str,"Dum");
            if(dee==0 || dum==0)
            {
                for(i=0;i<N;i++)
                {
                    cin>>a[i];
                    if(a[i]<1 || a[i]>50)
                        flag=0;
                }
            }
            for(i=0;i<N;i++)
            {
                if(a[i]%2==0)
                    even++;
                else odd++;
            }

                /*if(dee==0 && flag!=0)
                {
                    if(even==odd+1)
                        cout<<"Dee"<<endl;
                    else cout<<"Dum"<<endl;
                }
                else if(dum==0 && flag!=0)
                {
                    if(odd==even)
                        cout<<"Dee"<<endl;
                    else cout<<"Dum"<<endl;
                }
                */
                if(flag!=0)
                {
                    if(N==1 && even==1 && dee==0)
                        cout<<"Dee"<<endl;
                    else
                        cout<<"Dum"<<endl;
                }
        }
        test++;
    }

    return 0;
}
