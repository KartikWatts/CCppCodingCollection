#include <iostream>

using namespace std;

int main()
{
    int t, i, a[5], p, limit = 120, totalHours;
    cin >> t;
    while (t--)
    {
        totalHours = 0;
        for (i = 0; i < 5; i++)
        {
            cin >> a[i];
        }
        cin >> p;
        for (i = 0; i < 5; i++)
        {
            totalHours += (a[i] * p);
        }
        if (totalHours > limit)
        {
            cout << "Yes";
        }
        else
        {
            cout << "No";
        }
        cout << endl;
    }
}