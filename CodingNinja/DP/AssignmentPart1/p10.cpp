#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int l, r, start[n] = {0}, end[n] = {0}, coins[n], res[m + 1] = {0};
    for (int i = 0; i < m; i++)
    {
        cin >> l >> r;
        start[l - 1]++;
        end[r - 1]++;
    }
    coins[0] = start[0];
    for (int i = 1; i < n; i++)
    {
        coins[i] = coins[i - 1] + start[i] - end[i - 1];
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Coins in CoinBox " << i + 1 << ":\t" << coins[i] << endl;
    // }

    int coinSearch = m;
    sort(coins, coins + n, greater<int>());
    for (int i = 0; i < n;)
    {
        if (coinSearch == -1)
        {
            break;
        }
        if (coins[i] == coinSearch)
        {
            res[coinSearch]++;
            i++;
        }
        else
        {
            coinSearch--;
        }
    }
    for (int i = m - 1; i >= 0; i--)
    {
        res[i] += res[i + 1];
    }

    // for (int i = 0; i <= m; i++)
    // {
    //     cout << "Coinboxes with Atleast " << i << " coins: " << res[i] << endl;
    // }

    int q;
    cin >> q;
    while (q--)
    {
        int query;
        cin >> query;
        if (query <= m)
            cout << res[query] << endl;
        else
        {
            cout << "0\n";
        }
    }
}