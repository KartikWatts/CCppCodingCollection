#include <iostream>

using namespace std;

typedef unsigned long long int uint64;

void findWins(uint64 n, uint64 &count)
{
    if (n % 2 != 0)
    {
        count += n / 2;
    }
    else
    {
        while (n != 1)
        {
            if (n % 2 != 0)
            {
                findWins(n, count);
                break;
            }
            n = n / 2;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        uint64 ts, js, count = 0;
        cin >> ts;
        findWins(ts, count);
        cout << count << endl;
    }
}