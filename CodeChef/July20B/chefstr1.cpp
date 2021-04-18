#include <iostream>

typedef long long ll;

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll *s = new ll[n + 2];
        unsigned long long res = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        for (ll i = 1; i < n; i++)
        {
            res += abs(s[i - 1] - s[i]) - 1;
        }
        cout << res << endl;
    }
}