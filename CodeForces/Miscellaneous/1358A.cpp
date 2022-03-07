#include <iostream>

using namespace std;

int getLamps(int num)
{
    if (num % 2 == 0)
    {
        return (num / 2) * num;
    }
    else
    {
        return (num / 2) * (num - 1) + num;
    }
}

int main()
{
    int t, n, m, lamps;
    cin >> t;
    while (t--)
    {
        lamps = 0;
        cin >> n >> m;
        int minCut = 0;
        while (n != m)
        {
            if ((n == 1 && m == 2) || (n == 2 && m == 1))
            {
                lamps += 1;
                break;
            }
            minCut = min(n, m);
            lamps += getLamps(minCut);
            if (n > m)
            {
                n -= minCut;
            }
            else
            {
                m -= minCut;
            }
        }
        if (n == m)
        {
            lamps += getLamps(n);
        }
        cout << lamps << endl;
    }
    return 0;
}