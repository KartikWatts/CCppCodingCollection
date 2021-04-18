#include <iostream>

using namespace std;

int main()
{
    int a,b,c,count;

    for(a=1;a<11;a++)
    {
        for(b=1;b<11;b++)
        {
            for(c=1;c<11;c++)
            {
                if(a*b == c*c)
                    count++;
            }
        }
    }
    cout<<count;
    return 0;
}
