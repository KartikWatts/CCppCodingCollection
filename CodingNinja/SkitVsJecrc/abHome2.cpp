#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    unsigned long long dp2[100000], dp3[100000];
    for (int i = 0; i < 100000; i++)
    {
        dp2[i] = pow(i + 1, 2);
    }
    for (int i = 0; i < 100000; i++)
    {
        dp3[i] = pow(i + 1, 3);
    }

    while (t--)
    {
        unsigned long long n, sqN, cbN, count = 0;

        cin >> n;
        sqN = floor(sqrt(n));
        cbN = floor(cbrt(n));
        count = sqN + cbN;
        cout << sqN << " " << cbN << "\n";
        unordered_map<unsigned long long, int> squares, cubes;
        for (int i = 1; i <= sqN; i++)
        {
            if (i < 100000)
                squares.insert({dp2[i - 1], 1});
            else
                squares.insert({pow(i, 2), 1});
        }
        for (int i = 1; i <= cbN; i++)
        {
            if (i < 100000)
                cubes.insert({dp3[i - 1], 1});
            else
                cubes.insert({pow(i, 3), 1});
        }
        for (auto it : cubes)
        {
            if (squares.find(it.first) != squares.end())
            {
                count--;
            }
        }
        cout << count << "\n";
    }
}