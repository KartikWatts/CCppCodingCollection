#include <iostream>

using namespace std;

class stats
{
    static int x;
    public:
    static void dis()
    {
        cout<<x;
    }
};
    int stats:: x;
int main()
{
    stats::dis();
    return 0;
}
