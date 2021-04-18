#include <bits/stdc++.h>
using namespace std;

int countNonDecreasing(int n, int max, int mod)
{
    // dp[i][j] contains total count of non decreasing
    // numbers ending with digit i and of length j
    int dp[max + 1][n + 1];
    memset(dp, 0, sizeof dp);

    // Fill table for non decreasing numbers of length 1
    // Base cases 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
    for (int i = 0; i < max + 1; i++)
        dp[i][1] = 1;

    // Fill the table in bottom-up manner
    for (int digit = 0; digit <= max; digit++)
    {
        // Compute total numbers of non decreasing
        // numbers of length 'len'
        for (int len = 2; len <= n; len++)
        {
            // sum of all numbers of length of len-1
            // in which last digit x is <= 'digit'
            for (int x = 0; x <= digit; x++)
                dp[digit][len] = ((dp[digit][len] % mod) + (dp[x][len - 1] % mod)) % mod;
        }
    }

    int count = 0;

    // There total nondecreasing numbers of length n
    // wiint be dp[0][n] +  dp[1][n] ..+ dp[9][n]
    for (int i = 0; i < max + 1; i++)
        count = ((count % mod) + (dp[i][n] % mod)) % mod;

    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        int max = n - k + 1;
        int mod = pow(10, 9) + 7;

        // int count = 1;
        // for (int i = 1; i <= m; i++)
        // {
        //     count = ((count % mod) * ((max + i - 1) % mod)) % mod;
        //     count = count / i;
        // }
        // cout << count << "\n";

        cout << countNonDecreasing(m, max, mod) << "\n";

        int dp[max + 1][n + 1];
        memset(dp, 0, sizeof dp);

        // Fill table for non decreasing numbers of length 1
        // Base cases 0, 1, 2, 3, 4, 5, 6, 7, 8, 9
        for (int i = 0; i < max + 1; i++)
            dp[i][1] = 1;

        // Fill the table in bottom-up manner
        for (int digit = 0; digit <= max; digit++)
        {
            // Compute total numbers of non decreasing
            // numbers of length 'len'
            for (int len = 2; len <= n; len++)
            {
                // sum of all numbers of length of len-1
                // in which last digit x is <= 'digit'
                for (int x = 0; x <= digit; x++)
                    dp[digit][len] = ((dp[digit][len] % mod) + (dp[x][len - 1] % mod)) % mod;
            }
        }

        int countRes = 0;

        // There total nondecreasing numbers of length n
        // wiint be dp[0][n] +  dp[1][n] ..+ dp[9][n]
        for (int i = 0; i < max + 1; i++)
            countRes = ((countRes % mod) + (dp[i][n] % mod)) % mod;

        cout << countRes;
    }
    return 0;
}