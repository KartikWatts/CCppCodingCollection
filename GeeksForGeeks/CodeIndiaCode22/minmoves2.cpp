/*

Code written with love by Kartik Arora

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define read(type) readInt<type>()
#define FastIO ios_base::sync_with_stdio(0), cin.tie(0)
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VII;
typedef vector<VI> VVI;
typedef map<int, int> MPII;
typedef set<int> SETI;
typedef multiset<int> MSETI;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

/****** Template of some basic operations *****/
template <typename T, typename U>
inline void amin(T &x, U y)
{
    if (y < x)
        x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y)
{
    if (x < y)
        x = y;
}
/**********************************************/

/****** Template of Fast I/O Methods *********/
template <typename T>
inline void write(T x)
{
    int i = 20;
    char buf[21];
    // buf[10] = 0;
    buf[20] = '\n';

    do
    {
        buf[--i] = x % 10 + '0';
        x /= 10;
    } while (x);
    do
    {
        putchar(buf[i]);
    } while (buf[i++] != '\n');
}

template <typename T>
inline T readInt()
{
    T n = 0, s = 1;
    char p = getchar();
    if (p == '-')
        s = -1;
    while ((p < '0' || p > '9') && p != EOF && p != '-')
        p = getchar();
    if (p == '-')
        s = -1, p = getchar();
    while (p >= '0' && p <= '9')
    {
        n = (n << 3) + (n << 1) + (p - '0');
        p = getchar();
    }

    return n * s;
}

uint64 powers[64];
uint64 powerSet[64][64];

void fillPowers()
{
    uint64 x = 1;
    for (int i = 0; i < 64; i++)
    {
        powers[i] = x;
        x = x << 1;
    }
}

void fillPowerSet()
{
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            if (i != j)
            {
                powerSet[i][j] = powers[i] + powers[j];
            }
            else
            {
                powerSet[i][j] = powers[i];
            }
        }
    }
}

vector<bool> getSetBits(uint64 num)
{
    vector<bool> setBits;
    int i = 0;
    while (num)
    {
        setBits.emplace_back(num & 1);
        num = num >> 1;
        i++;
    }

    for (int j = i; j < 64; j++)
    {
        setBits.emplace_back(false);
    }

    return setBits;
}

void solve()
{
    uint64 a, b;
    cin >> a >> b;
    if (b <= a)
    {
        cout << a - b << "\n";
    }
    else
    {
        uint64 diff = b - a;
        uint64 minDiff = diff;
        // cout << "Diff: " << diff << endl;
        vector<bool> aSetBits = getSetBits(a);
        for (int i = 0; i < 64; i++)
        {
            bool bit = aSetBits[i];
            if (!bit)
            {
                // cout << "Working on bit: " << i << endl;
                // cout << "Looking for Powers of: " << powerSet[i][i] << endl;
                for (int j = 0; j < 64; j++)
                {
                    if (!aSetBits[j])
                    {
                        // cout << "Current Power Value: " << powerSet[i][j] << endl;
                        if (powerSet[i][j] > diff)
                        {
                            // cout << "NewDiff: " << (powerSet[i][j] - diff) << endl;
                            if (powerSet[i][j] - diff < minDiff)
                            {
                                minDiff = powerSet[i][j] - diff;
                                // cout << "MINDIFF UPDATED: " << minDiff << endl;
                            }
                        }
                        else
                        {
                            // cout << "NewDiff: " << (diff - powerSet[i][j]) << endl;
                            if (diff - powerSet[i][j] < minDiff)
                            {
                                minDiff = diff - powerSet[i][j];
                                // cout << "MINDIFF UPDATED: " << minDiff << endl;
                            }
                        }
                    }
                }
            }
        }
        cout << minDiff + 1 << "\n";
    }
}

int main()
{
    FastIO;

    int t;
    cin >> t;
    fillPowers();
    fillPowerSet();

    while (t--)
    {
        solve();
    }
    return 0;
}