#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long r, g, b, w;
        cin >> r >> g >> b >> w;
        int oddRGB = 0;
        if (r % 2 != 0)
        {
            oddRGB++;
        }
        if (g % 2 != 0)
        {
            oddRGB++;
        }
        if (b % 2 != 0)
        {
            oddRGB++;
        }

        if (oddRGB == 0)
        {
            cout << "Yes\n";
            continue;
        }
        else if (oddRGB == 1 && w % 2 == 0)
        {
            cout << "Yes\n";
            continue;
        }
        else if (oddRGB == 2 && w % 2 != 0)
        {
            if (r > 0 && g > 0 && b > 0)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }
        else if (oddRGB == 3 && w % 2 == 0)
        {
            if (r > 0 && g > 0 && b > 0)
                cout << "Yes\n";
            else
                cout << "No\n";
            continue;
        }
        else
        {
            cout << "No\n";
        }
    }
}