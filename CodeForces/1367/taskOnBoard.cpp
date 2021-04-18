#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int n = s.length();
        int m;
        cin >> m;
        int b[m];
        for (int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        map<int, vector<char>> myMap;
        for (int i = 0; i < n; i++)
        {
            int sum = 0;
            if (i == n - 1)
            {
                sum = 1;
            }
            else
            {

                for (int j = i + 1; j < n; j++)
                {
                    if (int(s[i]) < int(s[j]))
                    {
                        sum += j - i;
                    }
                }
            }

            if (myMap.find(sum) == myMap.end())
            {
                myMap.insert({sum, {s[i]}});
            }
            else
            {
                auto it = myMap.find(sum);
                it->second.push_back(s[i]);
            }
        }
        for (auto itr = myMap.begin(); itr != myMap.end(); ++itr)
        {
            cout << itr->first << " :\t";
            for (auto vit = itr->second.begin(); vit != itr->second.end(); vit++)
            {
                cout << *vit << " ,";
            }
            cout << endl;
        }
        cout << endl;

        cout << "*****ANSWER****" << endl;
        for (int i = 0; i < m; i++)
        {
            auto it = myMap.find(b[i]);
            cout << b[i] << ": " << it->first << "\t";
            // cout << it->second[0];
            // it->second.erase(it->second.begin());
        }
        cout << endl;
    }
}