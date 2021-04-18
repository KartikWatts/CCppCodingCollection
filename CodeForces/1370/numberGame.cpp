#include <iostream>
#include <vector>
#include <string.h>

#define F "FastestFinger"
#define A "Ashishgup"
typedef long long ll;
using namespace std;

string checkWin(ll n, string s)
{
    // cout << "Current Player: " << s << endl;
    // cout << "Number: " << n << endl;

    if (n == 1)
    {
        if (s == A)
            return F;
        else
            return A;
    }
    else if (n == 2)
    {
        return s;
    }
    else if (n % 2 != 0)
    {
        return s;
    }

    vector<ll> div;
    bool currentIsWinning = false;
    for (int i = n; i > 1; i--)
        if ((n % i == 0) && (i % 2 != 0))
            div.push_back(i);
    // cout << "Divisors of " << n << " are : ";
    // for (auto it : div)
    //     cout << it << "\t";
    // cout << endl;

    for (auto it : div)
    {
        cout << it << endl;
        if (s == A)
        {
            string temp = checkWin(n / it, F);
            if (temp == A)
            {
                currentIsWinning = true;
                break;
            }
        }
        else
        {
            string temp = checkWin(n / it, A);
            if (temp == F)
            {
                currentIsWinning = true;
                break;
            }
        }
    }
    if (currentIsWinning == true)
    {
        return s;
    }
    else
    {
        if (s == A)
        {
            return F;
        }
        else
        {
            return A;
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        if (n == 1)
        {
            cout << F << endl;
            continue;
        }
        else if (n == 2)
        {
            cout << A << endl;
            continue;
        }
        else if (n % 2 != 0)
        {
            cout << A << endl;
            continue;
        }
        else
        {
            string temp = checkWin(n, A);
            cout << temp << endl;
            continue;
        }
    }
}