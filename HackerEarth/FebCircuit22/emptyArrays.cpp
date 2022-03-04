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

int main()
{
    int n;
    cin >> n;
    MPII a;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        a.insert({temp, i});
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    int rotation = 0, elements_processed = 0;
    for (int i = 0; i < n; i++)
    {
        int num = b[i];
        int original_index = a.find(num)->second;
        cout << "\nWorking on: " << b[i] << "\toriginal index: " << original_index << endl;
        cout << "Rotation: " << rotation << "\tElements Processed: " << elements_processed << endl;
        int current_index;
        if (original_index >= (rotation))
        {
            current_index = original_index - rotation - elements_processed;
        }
        else
        {
            current_index = (n - elements_processed + original_index - rotation) % (n - elements_processed);
        }
        cout << "Current Index: " << current_index << "\n\n";
        rotation += current_index;
        elements_processed++;
    }

    cout << rotation + n;

    return 0;
}

/*
    1 3 2 5 6
    2 5 6 3 1

    rotation=0;
    el_p=0;

    Look for 2 [i=0]
    init_index= 2
    curr_index= init_index- rotation= 2-0;
    rotation= curr_index - el_p = 2- 0- 0= 2;
    el_p++;

    Look for 5 [i=1]
    init_index= 3
    curr_index= 3- 2= 1
    rotation= 1 - 1=0;
    el_p++;

    Look for 6
    init_index= 4
    curr_index= 4- 2= 2
    rotation= 2 - 2=0;
    el_p++;

    Look for 3
    init_index= 1
    curr_index= 1 - 2 = -1;
    rotation= (length -1) - 3=4-3=1;
    el_p++;

    Look for 1
    init_index= 0
    curr_index= 0 - 3 = -3;
    rotation= (length -3) - 4 = ;
    el_p++;



*/