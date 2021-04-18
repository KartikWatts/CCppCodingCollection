#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        vector<int> v;
        for (int i = 0; i < s.size();)
        {
            int count = 0;
            if (s[i] == '0')
            {
                // cout << "0 detected\t";
                i++;
            }
            if (s[i] == '1')
            {
                // cout << "1 detected\t";
                count++;
                i++;
                while (s[i] == '1')
                {
                    count++;
                    i++;
                }
                v.push_back(count);
            }
        }
        sort(v.begin(), v.end(), greater<int>());
        int score = 0;
        for (int i = 0; i < v.size(); i++)
        {
            if (i % 2 == 0)
            {
                score += v[i];
            }
        }
        cout << score << endl;
    }
}