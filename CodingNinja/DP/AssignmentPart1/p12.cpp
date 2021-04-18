#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>

#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sqr(x) ((x) * (x))
#define forn(i, a, n) for (int i = a; i < (int)n; i++)
#define dforn(i, a, n) for (int i = n - 1; i >= a; i--)

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    vector<vector<int>> matr(n, vector<int>(m));
    forn(i, 0, n)
        forn(j, 0, m)
            scanf("%d", &matr[i][j]);

    vector<vector<int>> ans(n, vector<int>(m));
    forn(i, 0, m)
        ans[0][i] = 0;

    forn(i, 1, n)
        forn(j, 0, m)
    {
        if (matr[i][j] >= matr[i - 1][j])
            ans[i][j] = ans[i - 1][j];
        else
            ans[i][j] = i;
    }
    int k;
    scanf("%d", &k);

    while (k--)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        bool f = false;
        forn(i, 0, m) if (ans[r - 1][i] <= l - 1)
        {
            f = true;
            break;
        }

        if (f)
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}