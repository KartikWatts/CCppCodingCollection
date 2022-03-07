#include <iostream>

using namespace std;

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int a[n];
        int r5 = 0, r10 = 0, r15 = 0;
        bool possible = true;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 5)
            {
                r5++;
            }
            if (a[i] == 10)
            {
                if (r5 <= 0)
                {
                    possible = false;
                }
                else
                {
                    r5--;
                    r10++;
                }
            }
            if (a[i] == 15)
            {
                if (r5 <= 1 && r10 <= 0)
                {
                    possible = false;
                }
                else
                {
                    if (r10 >= 1)
                    {
                        r10--;
                    }
                    else if (r5 >= 2)
                    {
                        r5 = r5 - 2;
                    }
                    r15++;
                }
            }
        }
        if (possible)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
}