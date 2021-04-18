#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long modulo = pow(10, 9) + 7;
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[100];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < 100; j++)
            dp[i][j] = 0;

    for (int i = 0; i < n; i++)
    {
        dp[i][arr[i]] = 1;
        for (int k = i - 1; k >= 0; k--)
        {
            if (arr[i] > arr[k])
            {
                for (int j = 1; j <= 100; j++)
                {
                    int g;
                    g = __gcd(arr[i], j);
                    dp[i][g] = (dp[i][g] % modulo + dp[k][j] % modulo) % modulo;
                }
            }
        }
    }
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += dp[i][1];
    }
    cout << sum % modulo;
    return 0;
}

// #include <iostream>
// #include <bits/stdc++.h>

// using namespace std;

// int main()
// {
//     int n;
//     int mod = pow(10, 9) + 7;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a[i];
//     }
//     map<int, unsigned long long> map, mRep;
//     for (int i = 0; i < n; i++)
//     {
//         for (auto it : map)
//         {
//             int gcdVal = __gcd(it.first, a[i]);
//             map[gcdVal] = (map[gcdVal] % mod + it.second % mod) % mod;
//         }
//         if (mRep[a[i]] == 0)
//         {
//             map[a[i]]++;
//             mRep[a[i]]++;
//         }
//     }
//     cout << "GCD Values of all types are: " << endl;
//     for (auto it : map)
//     {
//         cout << it.first << ": " << it.second << "\t";
//     }
//     cout << "\nResult: " << endl;
//     cout << map[1] % mod;
// }