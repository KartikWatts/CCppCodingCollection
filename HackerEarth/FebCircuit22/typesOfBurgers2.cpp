/**
 *    Coded by : lucky_21
 *               --------Lokesh Singh
 **/

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define vi vector<int>
#define all(x) x.begin(), x.end()
#define fix fixed << setprecision(10)
#define rep(i, a, b) for (int i = int(a); i <= int(b); i++)
#define repb(i, b, a) for (int i = int(b); i >= int(a); i--)
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0)

typedef double db;
typedef long long ll;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;

void solve()
{
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vi vx(x), vy(y), vz(z);
    for (int &i : vx)
        cin >> i;
    for (int &i : vy)
        cin >> i;
    for (int &i : vz)
        cin >> i;
    sort(all(vx));
    sort(all(vy));
    sort(all(vz));
    vi v;
    rep(i, 0, x - 1) rep(j, 0, y - 1) v.pb(vx[i] + vy[j]);
    sort(all(v), greater<int>());
    vector<ll> ans;
    rep(i, 0, min(k, int(v.size())) - 1) rep(j, 0, z - 1) ans.pb(1ll * v[i] + vz[j]);
    sort(all(ans), greater<ll>());
    ll sum = 0;
    rep(i, 0, k - 1) sum += ans[i];
    cout << sum << '\n';
}

signed main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}