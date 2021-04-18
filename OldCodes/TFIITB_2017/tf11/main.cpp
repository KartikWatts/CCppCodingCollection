#include <iostream>

using namespace std;

int main()
{

    int i,j,count=0,ans,no,nt,nh,nth,prime;
    for(i=1000;i<=9999;i++)
    {

        no=i%10;
        nt=(i%100)/10;
        nh=(i%1000)/100;
        nth=(i%10000)/1000;
        ntth=(i%100000)/10000;
        nl=i/1000000;
    }
        for(i=10;i<=99;i++)
        {
            if(no==nt)
                count++;
        }
        for(i=100;i<=999;i++)
        {
            if(no==nh)
                count++;
        }
        for(i=1000;i<=9999;i++)
        {
            if(no==nth && nh==nt)
                count++;
        }
        for(i=10000;i<=99999;i++)
        {
            if(no==ntth && nth==nt)
                count++;
        }
        for(i=100000;i<=999999;i++)
        {
            if(no==nl && nt==ntth && nh=nth)
                count++;
        }
    cout<<count;
    return 0;
}
