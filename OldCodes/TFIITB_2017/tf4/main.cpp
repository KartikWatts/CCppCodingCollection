#include <iostream>

using namespace std;

int main()
{

    int i,count=0,ans,no,nt,nh,nth;
    for(i=10;i<=99;i++)
    {
        ans=1;
        no=i%10;
        nt=i/10;

        if((no=1 && no==nt) || (no=2 && no==nt))
        {
            ans=0;
        }
        if(ans==1)
            count++;
    }
    for(i=100;i<999;i++)
    {
         ans=1;
        no=i%10;
        nt=(i%100)/10;
        nh=i/100;

        if((no=1 && (no==nt || no==nh)) || (no=2 && (no==nt || no==nh)) || (no=3 && (no==nt || no==nh)))
        {
            ans=0;
        }
        if(ans==1)
            count++;
    }
    for(i=1000;i<9999;i++)
    {
         ans=1;
        no=i%10;
        nt=(i%100)/10;
        nh=(i%1000)/100;
        nth=i/1000;

        if((no=1 && (no==nt || no==nh || no==nth)) || (no=2 && (no==nt || no==nh || no==nth)) || (no=3 && (no==nt || no==nh || no==nth)) || (no=4 && (no==nt || no==nh || no==nth)))
        {
            ans=0;
        }
        if(ans==1)
            count++;

    }

    count++;
    cout<<count;
    return 0;
}
