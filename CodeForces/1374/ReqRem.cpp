#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y, n;
        cin >> x >> y >> n;
        long long rem = n % x, res;
        if (n < x)
        {
            res = y;
        }
        else if (rem == y)
        {
            res = n;
        }
        else if (rem == 0)
        {
            res = n - x + y;
        }
        else if (rem < y)
        {
            res = n - rem - x + y;
        }
        else if (rem > y)
        {
            res = n - rem + y;
        }
        cout << res << endl;
    }
}