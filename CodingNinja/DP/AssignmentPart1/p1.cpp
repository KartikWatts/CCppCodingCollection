#include <iostream>

using namespace std;

int getMaxMoney(int a[], int n)
{
    long *maxLoot = new long[n];
    long loot = 0, res = 0;
    maxLoot[n - 1] = a[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if ((i + 2) < (n))
        {
            loot = a[i] + maxLoot[i + 2];
        }
        else
        {
            loot = a[i];
        }
        // cout << "Loot at i: " << i << " for value: " << a[i] << " is " << loot << endl;
        res = max(res, loot);
        maxLoot[i] = res;
        // cout << "MaxLoot so far: " << res << endl;
    }
    delete[] maxLoot;
    return res;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << getMaxMoney(a, n);
    delete[] a;
    return 0;
}