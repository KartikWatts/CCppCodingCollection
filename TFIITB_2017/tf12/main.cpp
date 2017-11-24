#include <iostream>

using namespace std;

int main()
{

    int i,count=0,no[1000],nt[1000],moolank;

    for(i=1;i<=100;i++)
    {

        no[i]=i%10;
        nt[i]=i/10;
    }

    for(i=1;i<=100;i++)
    {
        moolank=no[i]+nt[i];

        if(moolank<5)
            count++;
    }
    cout<<count;
    return 0;
}
