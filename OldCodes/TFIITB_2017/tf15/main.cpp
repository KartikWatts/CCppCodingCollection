#include <iostream>

using namespace std;

int lcmf(int m, int n)
{
    int fact,div,lcm=0;
    if(m<n)
    {
        fact=m;
        div=n;
    }
    else
    {
        fact=n;
        div=m;
    }

    while(fact!=10000)
    {
        if(div%fact==0)
        {
            lcm=fact;
            return lcm;
        }
        fact++;
    }

}
int main()
{

    return 0;
}
