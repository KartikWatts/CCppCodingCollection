#include <iostream>

using namespace std;

long long res = 0;
long long N;

void getValue(long long n)
{
    // cout << "n: " << n << "\t";
    if (n == 1)
    {
        return;
    }
    if (n == 0 || n == 2 || n == 4 || n == 5 || n > 9000000000)
    {
        res = -1;
        return;
    }
    if (n % 6 == 0)
    {
        res++;
        getValue(n / 6);
    }
    else
    {
        res++;
        getValue(n * 2);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        res = 0;
        long long n;
        cin >> n;
        N = n;
        getValue(n);
        cout << res << endl;
    }
}