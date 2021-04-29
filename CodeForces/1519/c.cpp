/*

Code is written with love by Kartik Arora

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

struct University
{
    vector<int> skill;
    vector<uint64> sum;
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        University U[n];
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            int s;
            cin >> s;
            U[a[i]].skill.emplace_back(s);
        }

        int maxSize = 0;
        for (int i = 0; i < n; i++)
        {
            if (U[i].skill.size() > maxSize)
            {
                maxSize = U[i].skill.size();
            }
            sort(U[i].skill.begin(), U[i].skill.end(), greater<int>());
        }

        for (int i = 0; i < n; i++)
        {
            uint64 skillSum = 0;
            for (int j = 0; j < U[i].skill.size(); j++)
            {
                skillSum = (uint64)U[i].skill[j] + skillSum;
                U[i].sum.push_back(skillSum);
            }
        }

        cout << "Max Size: " << maxSize << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "University " << i << ":\t";
            for (int j = 0; j < U[i].skill.size(); j++)
            {
                cout << U[i].skill[j] << " ";
            }
            cout << endl;

            cout << "Skill Sum " << i << ":\t";
            for (int j = 0; j < U[i].skill.size(); j++)
            {
                cout << U[i].sum[j] << " ";
            }
            cout << endl;
        }

        int teamSize = 1;
        while (teamSize <= maxSize)
        {
            uint64 total = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = teamSize; j < U[i].skill.size(); j += teamSize)
                {
                    total = total + (uint64)U[i].sum[j];
                    if (j - teamSize != 0)
                    {
                        total = total - (uint64)U[i].sum[j - teamSize];
                    }
                }
            }
            cout << total << " ";
            teamSize++;
        }

        for (int i = maxSize; i < n; i++)
        {
            cout << "0 ";
        }

        cout << "\n";
    }

    return 0;
}