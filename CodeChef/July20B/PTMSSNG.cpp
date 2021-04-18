#include <iostream>
#include <unordered_map>

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
        unordered_map<ll, int> mx, my;
        for (ll i = 0; i < (4 * n - 1); i++)
        {
            ll pointX, pointY;
            cin >> pointX >> pointY;
            mx[pointX]++;
            my[pointY]++;
            if (mx[pointX] == 2)
            {
                mx.erase(pointX);
            }
            if (my[pointY] == 2)
            {
                my.erase(pointY);
            }
        }
        // cout << "Result:\t";
        for (auto it : mx)
        {
            cout << it.first;
        }
        cout << " ";
        for (auto it : my)
        {
            cout << it.first;
        }
        cout << endl;
    }
}