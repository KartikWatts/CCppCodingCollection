#include <iostream>

using namespace std;

class Ram
{
    int x;
    public:
        Ram(int a)
        {
            x=a;
        }
        int fun(Ram R)
        {
            return R.x;
        }
};
int main()
{
    Ram r(108);
    cout<<r.fun(r);
    cout << "Hello world!" << endl;
    return 0;
}
