#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n, i, j;
    cin >> t;
    while (t--)
    {
        long long minB = -1, minO = -1;
        cin >> n;
        long long a[n], b[n];
        int count = 0;
        for (i = 0; i < n; i++)
            cin >> a[i];
        for (i = 0; i < n; i++)
            cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        minB = a[0];
        minO = b[0];
        int j = 0;
        for (i = 0; i < n; i++)
        {
            if (minB > minO)
            {
                count++;
                minB = a[i + 1];
                j++;
                minO = b[j];
            }
            else
            {
                minB = a[i + 1];
            }
        }
        cout << count << endl;
    }
}