#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        int i;
        for (i = 0; i < n - 2; i++)
        {
            long long sum = (long long)a[i] + (long long)a[i + 1];
            long long sum2 = (long long)a[n - 1];
            if (sum < sum2)
            {
                cout << i + 1 << " " << i + 2 << " " << n << endl;
                // cout << a[i] << " " << a[i + 1] << " " << a[n - 1] << endl;
                break;
            }
        }
        if (i == n - 2)
        {
            cout << "-1\n";
        }
    }
}