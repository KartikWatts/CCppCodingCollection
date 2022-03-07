#include <iostream>

using namespace std;

int main()
{
    long long t, n, i;
    cin >> t;
    while (t--)
    {
        long long ad = 0, bd = 0;
        long long dist = 0;
        cin >> n;
        long long a[n], b[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        for (i = 0; i < n; i++)
        {
            if (ad == bd)
            {
                if (a[i] == b[i])
                {
                    dist += a[i];
                }
            }
            ad += a[i];
            bd += b[i];
        }
        cout << dist << endl;
    }
}