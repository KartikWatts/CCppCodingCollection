#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x, sum = 0;
        cin >> n >> x;
        int a, l = -1, r;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            if (a % x)
            {
                if (l == -1)
                    l = i;
                r = i;
            }
            sum += a;
        }
        if (sum % x)
            cout << n;
        else if (l == -1)
            cout << "-1";
        else
        {
            cout << n - min(l + 1, n - r);
        }
        cout << endl;
    }
}