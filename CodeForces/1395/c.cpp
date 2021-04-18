#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    map<int, int> dp;

    int orRes = 0;
    cout << "OR Result: " << orRes << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Finding MinAnd for " << a[i] << "\n";
        if (dp.find(a[i]) == dp.end())
        {
            int minAnd = 1024;
            for (int j = 0; j < m; j++)
            {
                cout << "Temp minAnd found at " << b[j] << endl;
                if ((a[i] & b[j]) < minAnd)
                {
                    minAnd = a[i] & b[j];
                }
            }
            cout << "Final MinAnd= " << minAnd << "\n";
            dp.insert({a[i], minAnd});
            orRes = orRes | (a[i] & dp[a[i]]);
            cout << "OR Result: " << orRes << endl;
        }
        else
        {
            orRes = orRes | (a[i] & dp[a[i]]);
            cout << "OR Result: " << orRes << endl;
        }
    }
    cout << orRes;
}