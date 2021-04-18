#include <bits/stdc++.h>
using namespace std;

int m = pow(10, 9) + 7;
int countStrings(int n, int k)
{
    int dp[n + 1][k + 1][2];
    memset(dp, 0, sizeof(dp));

    dp[1][0][0] = 1;
    dp[1][0][1] = 1;

    for (int i = 2; i <= n; i++)
    {

        for (int j = 0; j <= k; j++)
        {
            dp[i][j][0] = dp[i - 1][j][0] + dp[i - 1][j][1];
            dp[i][j][1] = dp[i - 1][j][0];

            if (j - 1 >= 0)
                dp[i][j][1] += dp[i - 1][j - 1][1];
        }
    }

    return (dp[n][k][0] + dp[n][k][1]) % m;
}

// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int in, n, k;
        cin >> in >> n >> k;
        cout << in << " " << countStrings(n, k) << endl;
    }

    return 0;
}