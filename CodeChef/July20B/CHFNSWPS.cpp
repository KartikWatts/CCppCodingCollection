#include <iostream>
#include <unordered_map>

typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool possible = true;
        ll cost = 0;
        unordered_map<ll, int> a, b, miss;
        for (int i = 0; i < n; i++)
        {
            ll temp;
            cin >> temp;
            a[temp]++;
        }
        for (int i = 0; i < n; i++)
        {
            ll temp;
            cin >> temp;
            b[temp]++;
        }
        for (auto it : a)
        {
            if (b.find(it.first) != b.end())
            {
                if ((it.second + b[it.first]) % 2 != 0)
                {
                    // cout << "Broke at a loop for " << it.first << endl;
                    possible = false;
                    break;
                }
                else
                {
                    if (it.second != b[it.first])
                    {
                        miss[it.first] = abs(b[it.first] - it.second);
                        // if (it.second > b[it.first])
                        // {
                        //     it.second = it.second - b[it.first];
                        //     b[it.first] = 0;
                        // }
                        // else
                        // {
                        //     b[it.first] = b[it.first] - it.second;
                        //     it.second = 0;
                        // }
                    }
                }
            }
            else
            {
                miss[it.first] = it.second;
                if (it.second % 2 != 0)
                {
                    // cout << "Broke at a(not equal condition) loop for " << it.first << endl;
                    possible = false;
                    break;
                }
            }
        }

        for (auto it : b)
        {
            if (a.find(it.first) != a.end())
            {
                if ((it.second + a[it.first]) % 2 != 0)
                {
                    // cout << "Broke at b loop for " << it.first << "\t Total Count: " << it.second << " + " << a[it.first] << it.second + a[it.first] << endl;
                    possible = false;
                    break;
                }
                else
                {
                    if (it.second != a[it.first])
                    {
                        miss[it.first] = abs(a[it.first] - it.second);
                        // if (it.second > a[it.first])
                        // {
                        //     it.second = it.second - a[it.first];
                        //     a[it.first] = 0;
                        // }
                        // else
                        // {
                        //     a[it.first] = a[it.first] - it.second;
                        //     it.second = 0;
                        // }
                    }
                }
            }
            else
            {
                miss[it.first] = it.second;
                if (it.second % 2 != 0)
                {
                    // cout << "Broke at b(not equal condition) loop for " << it.first << endl;
                    possible = false;
                    break;
                }
            }
        }
        // cout << "Miss Map: \n";
        // for (auto it : miss)
        // {
        //     cout << it.first << "\t" << it.second << endl;
        // }
        if (possible == false)
        {
            cout << "-1\n";
            continue;
        }

        while (miss.size() > 0)
        {
            ll max = -1, min = 9223372036854775807;
            for (auto it : miss)
            {
                if (it.first > max)
                {
                    max = it.first;
                }
                if (it.first < min)
                {
                    min = it.first;
                }
            }
            miss[max] -= 2;
            miss[min] -= 2;
            cost += min;
            if (miss[max] <= 0)
            {
                miss.erase(max);
            }
            if (miss[min] <= 0)
            {
                miss.erase(min);
            }
        }
        cout << cost << endl;
    }
}