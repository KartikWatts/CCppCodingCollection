#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int point = 1;
    int i = 0;
    long long result = 0;
    sort(a, a + n);
    while (point < n)
    {
        if (point == i)
        {
            point++;
        }
        if (a[point] - a[i] >= k)
        {
            result += n - point;
            i++;
        }
        else
        {
            point++;
        }
    }
    cout << result;
}