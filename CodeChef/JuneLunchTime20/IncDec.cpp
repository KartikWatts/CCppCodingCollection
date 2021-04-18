#include <iostream>
// #include <bits/stdc++.h>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> incRes, decRes;

    while (t--)
    {
        incRes.clear();
        decRes.clear();
        int n;
        cin >> n;
        int a[n], maxNum = -1;
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            m[a[i]]++;
            maxNum = max(maxNum, a[i]);
        }
        if (m[maxNum] > 1)
        {
            cout << "NO\n";
            continue;
        }
        bool possible = true;
        for (auto it : m)
        {
            if (it.second >= 3)
            {
                cout << "NO\n";
                possible = false;
                break;
            }
        }
        if (!possible)
            continue;
        cout << "YES\n";
        // cout << "Map before:\n";
        // for (auto it : m)
        // {
        //     cout << it.first << ": " << it.second << "\t";
        // }
        for (auto &it : m)
        {
            if (it.first < maxNum && it.second >= 1)
            {
                incRes.push_back(it.first);
                it.second--;
            }
        }
        // cout << "Map after:\n";
        // for (auto it : m)
        // {
        //     cout << it.first << ": " << it.second << "\t";
        // }

        sort(incRes.begin(), incRes.end());
        incRes.push_back(maxNum);
        for (auto &it : m)
        {
            if (it.first < maxNum && it.second >= 1)
            {
                decRes.push_back(it.first);
                it.second--;
            }
        }
        sort(decRes.begin(), decRes.end(), greater<int>());
        for (auto it : incRes)
        {
            cout << it << " ";
        }
        for (auto it : decRes)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}