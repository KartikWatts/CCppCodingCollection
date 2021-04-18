#include <iostream>

using namespace std;

int main()
{
    int T,N,count,flag;
    cin>>T;
    if(T<1 || T>1000)
        return 1;
    while(T>0)
    {
        flag=0;
        count=0;
        cin>>N;
    if(N<1 || N>1000000)
        flag=1;
    while(N!=0)
    {
        if(flag==1)
        {
            break;
        }
        if(N/100!=0)
        {
            count++;
            N=N-100;
        }
        else
        {
            if(N/50!=0)
            {
                count++;
                N=N-50;
            }
            else
            {
                if(N/10!=0)
                {
                    count++;
                    N=N-10;
                }
                    else
                    {
                        if(N/5!=0)
                        {
                            count++;
                            N=N-5;
                        }
                        else
                        {
                            if(N/2!=0)
                             {
                                 count++;
                                 N=N-2;
                             }
                             else
                             {
                                 if(N/1!=0)
                                 {
                                    count++;
                                    N=N-1;
                                 }
                             }
                        }
                    }
            }
        }
    }
    cout<<count<<endl;
    T--;
    }
    return 0;
}
