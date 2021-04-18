#include <bits/stdc++.h>
using namespace std;

long long merge(int a[], int l, int m, int r)
{
    int temp[r - l + 1];

    long long result = 0;
    int i = l, j = m, k = 0;

    while (i < m && j <= r)
    {
        if (a[i] > a[j])
        {
            temp[k++] = a[j++];
        }
        else
        {
            result += a[i] * (r - j + 1);
            temp[k++] = a[i++];
        }
    }

    while (i < m)
    {
        temp[k++] = a[i++];
    }
    while (j <= r)
    {
        temp[k++] = a[j++];
    }

    for (int i = l, k = 0; i <= r; i++, k++)
    {
        a[i] = temp[k];
    }

    return result;
}

long long murderSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        long long c1 = murderSort(a, l, m);
        long long c2 = murderSort(a, m + 1, r);
        long long c3 = merge(a, l, m + 1, r);

        return (c1 + c2 + c3);
    }
    return 0;
}

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
            cin >> a[i];
        cout << murderSort(a, 0, n - 1);
        cout << endl;
    }
}