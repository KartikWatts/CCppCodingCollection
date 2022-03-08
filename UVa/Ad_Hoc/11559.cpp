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

struct Hotel
{
    int price;
    vector<int> beds;
};

bool compareHotelPrice(Hotel a, Hotel b)
{
    return a.price < b.price;
}

void solve(int n, int b, int h, int w)
{
    Hotel hotel[h];

    for (int i = 0; i < h; i++)
    {
        int p;
        scanf("%d", &p);
        hotel[i].price = p;
        for (int j = 0; j < w; j++)
        {
            int beds;
            scanf("%d", &beds);
            hotel[i].beds.push_back(beds);
        }
    }
    sort(hotel, hotel + h, compareHotelPrice);
    int cost = INT32_MAX;
    for (int i = 0; i < w; i++)
    {
        int people = n;
        // cout << "Week " << i + 1 << endl;
        for (int j = 0; j < h; j++)
        {
            // cout << "Looking for Hotel with price: " << hotel[j].price << endl;
            // cout << "Beds Available: " << hotel[j].beds[i] << endl;

            // cout << "People Left: " << people << endl;
            if (people <= hotel[j].beds[i])
            {
                // cout << "All People Done\n";
                if (people * hotel[j].price < cost)
                    cost = people * hotel[j].price;
                people = 0;
            }

            // cout << "Cost: " << cost << endl;
            if (people == 0)
                break;
        }
    }
    // cout << "BUDGET: " << b << endl;
    if (cost >= b)
        cout << "stay home\n";
    else
        cout << cost << "\n";
}

int main()
{
    // FastIO;
    int n, b, h, w;
    while (scanf("%d %d %d %d", &n, &b, &h, &w) == 4)
    {
        solve(n, b, h, w);
        // cout << "\n";
    }
    return 0;
}