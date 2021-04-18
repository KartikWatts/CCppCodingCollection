#include <iostream>

typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll a, b, n, result = 0;
        cin >> a >> b >> n;
        while (a <= n && b <= n)
        {
            if (a <= b)
            {
                a += b;
            }
            else
            {
                b += a;
            }
            result++;
        }
        cout << result << endl;
    }
}