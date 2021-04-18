#include <iostream>
#include <string.h>
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
        string s;
        cin >> s;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            a[i] = s[i] - '0';
            if (a[i] == 1)
            {
                count++;
            }
        }

        int dp[n][n];
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = a[i];
            for (int j = i + 1; j < n; j++)
            {
                dp[i][j] = dp[i][j - 1] + a[j];
                if (dp[i][j] == j - i + 1)
                {
                    // cout << "Counted for " << a[i] << " and " << a[j] << endl;
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}