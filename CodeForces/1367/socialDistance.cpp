#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> occupied;
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                occupied.push_back(i);
            }
        }
        if (occupied.size() == 0)
        {
            if (k == n)
            {
                cout << "1" << endl;
                continue;
            }
            result = (n - 1) / k;
            cout << result << endl;
            continue;
        }
        //For first seats
        if (occupied[0] > k)
            result += (abs(occupied[0] - 1) / k);

        //For last seats
        if (n - occupied[occupied.size() - 1] > k)
            result += (abs(n - occupied[occupied.size() - 1] - 1) / k);

        for (int i = 1; i < occupied.size() - 1; i++)
        {
            if (occupied[i + 1] - occupied[i] > k)
                result += (abs(occupied[i + 1] - occupied[i] - 2) / k);
        }
        cout << result << endl;
    }
}