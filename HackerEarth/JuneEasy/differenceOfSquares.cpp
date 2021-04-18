#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long l, r, i, count = 0, j;
        cin >> l >> r;
        for (i = l; i <= r; i++)
        {
            if (i % 4 == 2)
            {
                break;
            }
            else
            {
                count++;
            }
        }
        long long diff = (r - i) / 4;
        if (r >= i)
            count += r - i - diff;
        cout << count << endl;
    }

    return 0;
}