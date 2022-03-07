#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int t, n, m, k, points;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> k;
        int cardsPerPlayer = n / k;
        if (m <= cardsPerPlayer)
        {
            points = m;
        }
        else
        {
            m = m - cardsPerPlayer;
            double ncards = double(m) / double(k - 1);
            m = ceil(ncards);
            points = cardsPerPlayer - m;
        }
        cout << points << endl;
    }
}