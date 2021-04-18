#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long k;
        cin >> k;
        vector<unsigned long long> a;
        unsigned long long temp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            a.push_back(temp);
        }

        sort(a.begin(), a.end());
        while (a.size() > 0)
        {
            // if ()
        }
    }
}