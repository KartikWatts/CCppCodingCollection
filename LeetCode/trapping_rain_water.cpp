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

int trap(vector<int> &height)
{
    int n = height.size();
    int total_water = 0, temp_water = 0;
    int left_block = 0, right_block = n - 1;
    int curr_block = 0;
    for (int i = 1; i < n; i++)
    {
        if (height[i] < height[curr_block])
        {
            left_block = curr_block;
            break;
        }
        curr_block = i;
    }

    curr_block = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (height[i] < height[curr_block])
        {
            right_block = curr_block;
            break;
        }
        curr_block = i;
    }

    int max_h = height[left_block], max_in = left_block;

    // cout << "Left Block: " << left_block << endl;
    // cout << "Right Block: " << right_block << endl;

    // cout << "Moving Left to right\n";
    if (height[left_block] != height[right_block])
    {
        for (int i = left_block + 1; i <= right_block; i++)
        {
            // cout << "Curr Block: " << i << endl;
            // cout << "Max Height: " << max_h << "\tCurr Height: " << height[i] << endl;
            if (height[i] < max_h)
            {
                temp_water += max_h - height[i];
                // cout << "Collected Temp Water: " << temp_water << endl;
            }
            else if (height[i] >= max_h)
            {
                // temp_water += (i - max_in + 1) * (height[i] - max_h);
                total_water += temp_water;
                temp_water = 0;
                // cout << "Collected Total Water: " << total_water << endl;
                max_h = height[i];
            }
        }
    }

    max_h = height[right_block], max_in = right_block;
    // cout << "Moving right to leftt\n";
    temp_water = 0;
    for (int i = right_block - 1; i >= left_block; i--)
    {
        // cout << "Curr Block: " << i << endl;
        // cout << "Max Height: " << max_h << "\tCurr Height: " << height[i] << endl;
        if (height[i] < max_h)
        {
            temp_water += max_h - height[i];
            // cout << "Collected Temp Water: " << temp_water << endl;
        }
        else if (height[i] >= max_h)
        {
            // temp_water += (i - max_in + 1) * (height[i] - max_h);
            total_water += temp_water;
            temp_water = 0;
            // cout << "Collected Total Water: " << total_water << endl;
            max_h = height[i];
        }
    }

    return total_water;
}

int main()
{
    int n;
    cin >> n;
    vector<int> height;
    for (int i = 0; i < n; i++)
    {
        int h;
        cin >> h;
        height.emplace_back(h);
    }

    cout << trap(height);

    return 0;
}