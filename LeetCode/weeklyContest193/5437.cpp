#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int findLeastNumOfUniqueInts(vector<int> &arr, int k)
{
    map<long long, int> m;
    for (int i = 0; i < arr.size(); i++)
    {
        m[arr[i]]++;
    }
    for (auto x : m)
        cout << x.first << " " << x.second << endl;
    long long toBeDeleted = 1;
    bool isChanged = false;
    while (k > 0)
    {
        for (auto it = m.cbegin(); it != m.cend();)
        {
            cout << "Frequency: " << it->second;
            if (it->second == toBeDeleted)
            {
                cout << "Element to be removed: " << it->first << endl;
                if (toBeDeleted == 1)
                {
                    m.erase(it++);
                }
                else
                {
                    m[it->first]--;
                    cout << "Value of " << it->first << "after decrementing: " << m[it->first];
                    toBeDeleted = m[it->first];
                    isChanged = true;
                    k--;
                    break;
                }
                cout << "Element removed" << endl;
                k--;
                cout << "Value of k: " << k << endl;
                for (auto y : m)
                {
                    cout << y.first << " " << y.second << endl;
                }
            }
            else
            {
                ++it;
            }
            if (k == 0)
            {
                break;
            }
        }
        if (!isChanged)
            toBeDeleted++;
    }
    return m.size();
}

int main()
{
    vector<int> v = {4, 3, 1, 1, 3, 3, 2};
    int k = 3;
    cout << findLeastNumOfUniqueInts(v, k);
}