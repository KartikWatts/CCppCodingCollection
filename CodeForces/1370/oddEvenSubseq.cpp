#include <iostream>
#include <vector>

typedef long long ll;
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a, t;
    ll maxo = 0, maxe = 0;
    ll ino = 1, ine = 1;
    for (ll i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.push_back(temp);
        if (i % 2 == 0)
        {
            if (a[i] > maxe)
            {
                maxe = a[i];
                ine = i;
            }
        }
        else
        {
            if (a[i] > maxo)
            {
                maxo = a[i];
                ino = i;
            }
        }
    }
    while (k--)
    {
        int itr = 0;
        while (itr < n)
        {
            int pmaxo = maxo, pmaxe = maxe;
            t.clear();
            t = a;
            t.erase(t.begin() + itr);
            if (ine >= itr && ine != n - 1)
            {
                maxo = a[ine];
                ino = ine;
            }
            if (ino >= itr && ino != n - 1)
            {
                maxe = a[ino];
                ine = ino;
            }
            if ((maxo < pmaxo && maxo <= pmaxe) || (maxe < pmaxe && maxe <= pmaxo))
            {
                break;
            }
            itr++;
        }
    }
    if (maxo <= maxe)
    {
        cout << maxo;
    }
    else
    {
        cout << maxe;
    }
}