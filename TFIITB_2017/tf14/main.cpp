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
        nth=i/1000;

        if(no==1 || nt==1 || nh==1 || nth==1)
            count++;

        if(no==2)
        {
            if(nt==2 || nh==2 || nth==2)
                count++;
        }
        if(nt==2)
        {
            if(nh==2 || nth==2)
                count++;
        }
        if(nh==2)
        {
            if(nth==2)
                count++;
        }

        if(no==3)
        {
            if((nt==3 && nh==3) ||(nh==3 && nth==3) ||(nth==3 && nt==3))
                count++;
        }
        if(nt==3)
        {
            if(nh==3 && nth==3)
                count++;
        }
    }
    cout<<count;
    return 0;
}
