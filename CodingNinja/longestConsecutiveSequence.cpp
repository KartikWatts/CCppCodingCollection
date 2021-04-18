#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<int> longestConsecutiveIncreasingSequence(int *a, int n)
{
    //Your Code goes here
    unordered_map<ll, bool> m;
    unordered_map<ll, ll> indexMap;

    for (ll i = 0; i < n; i++)
    {
        m[a[i]] = true;
    }
    for (ll i = 0; i < n; i++)
    {
        indexMap[a[i]] = i;
    }
    vector<int> result, tempV;
    ll maxLength = 0;
    int startIndex = 0;
    // cout << "Value of StartIndex: " << startIndex << endl;
    for (ll i = 0; i < n; i++)
    {
        if (m[a[i]] == true)
        {

            ll lf = 1;
            tempV.clear();
            if (lf > maxLength)
            {
                maxLength = lf;
                result.push_back(a[i]);
            }
            ll k = a[i];
            m[k] = false;
            tempV.push_back(k);
            int currIndex = i;

            // cout << "Value of currIndex: " << currIndex << endl;
            // cout << "Current Value: " << k << endl;
            // cout << "Looking for: " << k + 1 << endl;
            while (m.find(k + 1) != m.end())
            {
                m[k + 1] = false;
                // cout << "Found " << k + 1 << endl;
                k = k + 1;
                tempV.push_back(k);
                lf++;
                // if (result[0])
                // {
                //     cout << result[0] << endl;
                // }
                if (lf > maxLength || (lf >= maxLength && currIndex == startIndex))
                {
                    // cout << "New Max Length: " << lf << endl;
                    maxLength = lf;
                    result.clear();
                    result = tempV;
                }
                // cout << "Now Looking for: " << k + 1 << endl;
            }
            k = a[i];
            // cout << "Checking backward for: " << k << endl;
            // cout << "Looking for: " << k - 1 << endl;
            while (m.find(k - 1) != m.end())
            {
                currIndex = indexMap[k - 1];
                // cout << "Value of currIndex: " << currIndex << endl;

                m[k - 1] = false;
                // cout << "Found " << k - 1 << endl;
                k = k - 1;
                tempV.push_back(k);
                lf++;
                if (lf > maxLength)
                    startIndex = currIndex;
                else if (lf == maxLength && currIndex < startIndex)
                {
                    startIndex = currIndex;
                }
                // cout << "Value of startIndex: " << startIndex << endl;

                if (lf > maxLength || (lf >= maxLength && currIndex == startIndex))
                {
                    // cout << "New Max Length: " << lf << endl;
                    if (lf == 1)
                    {
                        result.clear();
                    }
                    maxLength = lf;

                    result = tempV;
                }
                // cout << "Now Looking for: " << k - 1 << endl;
            }
            // cout << "Not Found" << endl;
        }
    }

    sort(result.begin(), result.end());
    return result;
}
int main()
{
    int size;

    cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    vector<int> ans = longestConsecutiveIncreasingSequence(arr, size);

    for (auto it = ans.cbegin(); it != ans.cend(); it++)
    {
        cout << *it << endl;
    }

    delete arr;
}