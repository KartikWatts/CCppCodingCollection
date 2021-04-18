#include <iostream>

using namespace std;

int main()
{
    int t, n, i, x;
    cin >> t;
    while (t--)
    {
        cin >> n >> x;
        int a[n];
        int even = 0, odd = 0;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] % 2 == 0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }
        if (odd == 0)
        {
            cout << "No" << endl;
        }

        else if (even >= x)
        {
            cout << "Yes" << endl;
        }
        else
        {
            x = x - even;
            if (x % 2 == 0)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
    }
}