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

int maxLength = 0;
MPII processed;

int getPathLength(VVI a, int n, int m, int si, int sj, int length)
{

    bool isProcessed = false;
    cout << "Length recieved: " << length << endl;
    cout << "si: " << si << "\tsj: " << sj << endl;
    FOREACH(it, processed)
    {
        cout << "Map items: " << it->first << "\t" << it->second << endl;
        if (it->first == si && it->second == sj)
        {
            cout << "Processed" << endl;
            isProcessed = true;
        }
    }

    cout << "Is Processed: " << isProcessed << endl;
    if (isProcessed == false && length <= 10)
    {
        cout << si << "\t" << sj << "\t" << a[si][sj] << endl;
        processed.insert(PII(si, sj));
        if (a[si][sj] == 1)
        {
            length++;
            cout << "LENGTH: " << length << endl;
            if (length > maxLength)
            {
                maxLength = length;
                cout << "MAX LENGTH: " << maxLength << endl;
            }
            if (si - 1 >= 0)
            {
                FOREACH(it, processed)
                {
                    if (it->first == si - 1 && it->second == sj)
                    {
                        cout << "Processed" << endl;
                        isProcessed = true;
                    }
                }
                if (isProcessed == false)
                    getPathLength(a, n, m, si - 1, sj, length);
            }
            if (si + 1 < n)
            {
                FOREACH(it, processed)
                {
                    if (it->first == si + 1 && it->second == sj)
                    {
                        cout << "Processed" << endl;
                        isProcessed = true;
                    }
                }
                if (isProcessed == false)
                    getPathLength(a, n, m, si + 1, sj, length);
            }
            if (sj - 1 >= 0)
            {
                FOREACH(it, processed)
                {
                    if (it->first == si && it->second == sj - 1)
                    {
                        cout << "Processed" << endl;
                        isProcessed = true;
                    }
                }
                if (isProcessed == false)
                    getPathLength(a, n, m, si, sj - 1, length);
            }
            if (sj + 1 < m)
            {
                FOREACH(it, processed)
                {
                    if (it->first == si && it->second == sj + 1)
                    {
                        cout << "Processed" << endl;
                        isProcessed = true;
                    }
                }
                if (isProcessed == false)
                    getPathLength(a, n, m, si, sj + 1, length);
            }
        }
    }
    return maxLength;
}

int main()
{
    int n, m, si, sj;
    SCD(n);
    SCD(m);
    VVI a(n);
    REP(i, n)
    {
        a[i] = VI(m);
        REP(j, m)
        {
            SCD(a[i][j]);
        }
    }

    REP(i, n)
    {
        REP(j, m)
        {
            processed.clear();
            cout << endl
                 << "Recursion for Point (" << i << ", " << j << " started" << endl;
            getPathLength(a, n, m, i, j, 0);
        }
    }

    cout << maxLength;
    return 0;
}