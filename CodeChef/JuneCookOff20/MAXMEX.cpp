#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m;
        long long max = 0, result = 0;
        set<int> s;
        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &x);
            if (x != m)
                s.insert(x), ++result;
        }

        int mex = 1;
        while (s.count(mex))
            ++mex;

        if (mex != m)
            result = -1;

        // for (int i = 0; i < n; i++)
        // {
        //     cin >> a[i];
        //     if (a[i] > max)
        //         max = a[i];
        //     s.insert(a[i]);
        //     if (a[i] == m)
        //         count++;
        // }

        // if (s.size() < m)
        // {
        //     result = -1;
        // }
        // else
        // {
        //     result = s.size() - count;
        // }

        cout << result << endl;
        //     map<long long, int> mp;
        //     int start = 0, end = n - 1;
        //     int mid = (start + end) / 2;
        //     int result = -1;
        //     while (start < end)
        //     {
        //         for (int i = start; i < mid; i++)
        //             mp.insert({a[i], i});
        //     }
        //     //IF m is Missing
        //     if (mp.find(m) == mp.end())
        //     {
        //         int isSmallerMissing = false;
        //         for (int i = 1; i < m; i++)
        //         {
        //             //IF any number less then m missing
        //             if (mp.find(i) == mp.end())
        //             {
        //                 end = mid - 1;
        //                 isSmallerMissing = true;
        //                 break;
        //             }
        //         }
        //         if (!isSmallerMissing)
        //         {
        //             result = mid;
        //             start = mid + 1;
        //         }
        //     }
        //     else
        //     {
        //         end = mp[m] - 1;
        //     }
        //     if (end == start)
        //     {
        //         if (a[0] != m && result == -1)
        //         {
        //             cout << 1 << endl;
        //         }
        //         else
        //         {
        //             if (a[0] != m)
        //             {
        //                 result += 1;
        //             }
        //             else
        //             {
        //                 result = 0;
        //             }
        //         }
        //     }
        //     cout << result << endl;
        // }
    }
}