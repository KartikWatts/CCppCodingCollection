#include <iostream>

typedef long long ll;
using namespace std;

int getNumSum(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        int chef = 0, morty = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i] >> b[i];
            int tempA = getNumSum(a[i]);
            int tempB = getNumSum(b[i]);
            // cout << tempA << "\t" << tempB << endl;
            if (tempA > tempB)
            {
                chef++;
            }
            else if (tempB > tempA)
            {
                morty++;
            }
            else
            {
                chef++;
                morty++;
            }
        }
        if (chef > morty)
        {
            cout << "0 " << chef << "\n";
        }
        else if (morty > chef)
        {
            cout << "1 " << morty << "\n";
        }
        else
        {
            cout << "2 " << chef << "\n";
        }
    }
}