#include <iostream>

typedef long long ll;
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll coins = 0, rest = 0;
        ll s, n;
        cin >> s >> n;
        if (s < n)
        {
            if (s == 1 || s % 2 == 0)
                cout << "1" << endl;
            else
            {
                cout << "2" << endl;
            }

            continue;
        }

        rest = s % n;
        coins += s / n;

        if (rest != 0)
        {

            if (rest % 2 == 0 || rest == 1)
            {
                coins++;
            }
            else
            {
                coins += 2;
            }
        }

        cout << coins << endl;
    }
}