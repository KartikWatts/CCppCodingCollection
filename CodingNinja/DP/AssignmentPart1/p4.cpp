#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> a)
{
    unordered_map<int, int> m;

    int total = 0, max = 0;
    for (int i = 0; i < n; i++)
    {
        m[a[i]]++;
        total += a[i];
    }

    for (auto it : m)
    {
        int temp = total;
        if (m.find(it.first + 1) != m.end())
        {
            temp -= m[it.first + 1] * (it.first + 1);
        }
        if (m.find(it.first - 1) != m.end())
        {
            temp -= m[it.first - 1] * (it.first - 1);
        }
        if (temp > max)
        {
            max = temp;
        }
    }
    return max;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << solve(n, a);
    return 0;
}