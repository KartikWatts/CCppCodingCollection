#include <iostream>

using namespace std;

int main()
{

    int i,j,count=0,ans,no,nt,nh,nth,prime;
    for(i=10;i<=99;i++)
    {

        ans=0;
        no=i%10;
        nt=i/10;

        prime=1;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                prime=0;
                break;
            }
        }

        if(prime==1)
        {
            if(no+nt<=4)
                ans=1;
        }
        if(ans==1)
            count++;
    }
    for(i=100;i<999;i++)
    {
         ans=0;
        no=i%10;
        nt=(i%100)/10;
        nh=i/100;

        prime=1;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                prime=0;
                break;
            }
        }

        if(prime==1)
        {
            if(no+nt+nh<=4)
                ans=1;
        }
        if(ans==1)
            count++;
    }
    for(i=1000;i<9999;i++)
    {
         ans=0;
        no=i%10;
        nt=(i%100)/10;
        nh=(i%1000)/100;
        nth=i/1000;

        prime=1;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                prime=0;
                break;
            }
        }

        if(prime==1)
        {
            if(no+nt+nh+nth<=4)
                ans=1;
        }
        if(ans==1)
            count++;

    }

    cout<<count;
    return 0;
}
