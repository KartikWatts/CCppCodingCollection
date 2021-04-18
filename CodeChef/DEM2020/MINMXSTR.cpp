#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> v;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            v.push_back(str);
        }
        int minStrIn = 0, maxStrIn = 0;
        for (int i = 1; i < n; i++)
        {
            int len = min(v[minStrIn].size(), v[i].size());
            bool foundBigger = false, isEqual = true;
            // cout << "Comparing Strings:\t" << v[minStrIn] << "\tand\t" << v[i] << endl;
            for (int j = 0; j < len; j++)
            {
                if (int(v[i][j]) > int(v[minStrIn][j]))
                {
                    foundBigger = true;
                    isEqual = false;
                    break;
                }
                if (int(v[i][j]) < int(v[minStrIn][j]))
                {
                    isEqual = false;
                    break;
                }
            }
            if (foundBigger == false)
            {
                if (isEqual == false)
                {
                    minStrIn = i;
                }
                else
                {
                    if (v[i].size() > v[minStrIn].size())
                    {
                        minStrIn = i;
                    }
                }
            }
            // cout << "MinStr: " << v[minStrIn];
        }

        for (int i = 1; i < n; i++)
        {
            int len = min(v[minStrIn].size(), v[i].size());
            bool foundSmaller = false, isEqual = true;
            for (int j = 0; j < len; j++)
            {
                if (int(v[i][j]) < int(v[maxStrIn][j]))
                {
                    foundSmaller = true;
                    isEqual = false;
                    break;
                }
                if (int(v[i][j]) > int(v[maxStrIn][j]))
                {
                    isEqual = false;
                    break;
                }
            }
            if (foundSmaller == false)
            {
                if (isEqual == false)
                {
                    maxStrIn = i;
                }
                else
                {
                    if (v[i].size() > v[maxStrIn].size())
                    {
                        maxStrIn = i;
                    }
                }
            }
        }

        // cout << "Min Str Index: " << minStrIn << endl;
        // cout << "Max Str Index: " << maxStrIn << endl;
        int q;
        cin >> q;
        while (q--)
        {
            int type;
            cin >> type;
            if (type == 2)
            {
                cout << minStrIn + 1 << endl;
            }
            else if (type == 3)
            {
                cout << maxStrIn + 1 << endl;
            }
            else
            {
                int index;
                char ch;
                cin >> index >> ch;
                index = index - 1;
                string newStr = v[index] + ch, minStr = v[minStrIn], maxStr = v[maxStrIn];
                v.push_back(newStr);
                int newIndex = v.size() - 1;
                int len = min(v[minStrIn].size(), newStr.size());
                if (index == minStrIn)
                {
                    minStrIn = newIndex;
                }
                else
                {
                    int start = 0, end = len;
                    int mid = (start + end) / 2;
                    while (start >= end)
                    {
                        if (int(newStr[mid]) < int(minStr[mid]))
                        {
                            minStrIn = newIndex;
                            break;
                        }
                    }
                }
                if (index == maxStrIn)
                {
                    maxStrIn = newIndex;
                }
            }
        }
    }
}