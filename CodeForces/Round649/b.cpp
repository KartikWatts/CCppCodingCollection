#include <iostream>
#include <bits/stdc++.h>
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
        vector<int> result;

        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == n || ((a[i - 1] < a[i]) != (a[i] < a[i + 1])))
            {
                result.push_back(a[i]);
            }
        }
        cout << result.size() << endl;
        for (int i : result)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}