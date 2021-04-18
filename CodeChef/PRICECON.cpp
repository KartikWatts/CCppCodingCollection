#include <iostream>

using namespace std;

int main()
{
    int t, n, k;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int a[n], p[n];
        long long suma = 0, sump = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > k)
            {
                p[i] = k;
            }
            else
            {
                p[i] = a[i];
            }
            suma += a[i];
            sump += p[i];
        }
        cout << suma - sump << endl;
    }
}