#include <iostream>
#include <vector>

using namespace std;

long long getValue(long long a[], int k, int n)
{
    long long res = 0;
    for (int i = 0; i < n; i++)
    {

        res += k & a[i];
    }
    return res;
}

long long snoob(long long x)
{

    long long rightOne;
    long long nextHigherOneBit;
    long long rightOnesPattern;

    long long next = 0;

    if (x)
    {

        rightOne = x & -(signed)x;

        nextHigherOneBit = x + rightOne;

        rightOnesPattern = x ^ nextHigherOneBit;

        rightOnesPattern = (rightOnesPattern) / rightOne;

        rightOnesPattern >>= 2;

        next = nextHigherOneBit | rightOnesPattern;
    }

    return next;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        long long a[n], maxN = -1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > maxN)
            {
                maxN = a[i];
            }
        }
        long long maxNum = -1, res = -1;
        if (k == 1)
        {
            while (k <= 100000)
            {
                long long v = getValue(a, k, n);
                // cout << "k = " << k << " res: " << v << endl;
                if (v > maxNum)
                {
                    maxNum = v;
                    res = k;
                }
                k = snoob(k);
            }
        }
        if (k == 2)
        {
            k = 3;
            while (k <= 100000)
            {
                long long v = getValue(a, k, n);
                // cout << "k = " << k << " res: " << v << endl;
                if (v > maxNum)
                {
                    maxNum = v;
                    res = k;
                }
                k = snoob(k);
            }
        }
        if (res == -1)
        {
            res = maxN;
        }
        cout << res << endl;
    }
}