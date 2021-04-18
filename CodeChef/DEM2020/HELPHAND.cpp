#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        // int lcmNum = 1;
        // for (int i = 2; i <= n; i++)
        // {
        //     lcmNum = lcm(lcmNum, i);
        // }
        // cout << lcmNum;

        if (n == 1)
        {
            cout << 0;
        }
        if (n == 2)
        {
            cout << 1;
        }
        if (n == 3)
        {
            cout << 2;
        }
        else
        {
            int a[n + 1];
            a[1] = 0;
            a[2] = 1;
            a[3] = 2;
            int a[4] = a[1] + a[2] + a[3];
            for (int i = 5; i <= n; i++)
            {
            }
        }
    }
}