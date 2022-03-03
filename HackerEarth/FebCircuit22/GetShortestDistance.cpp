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

// 4 3 0 0 0
// *..*
// .#..
// ###^
// .#.^

vector<pair<int, int>> get_valid_neighbours(bool **vis, pair<int, int> cell, int n)
{

    int x = cell.first, y = cell.second;
    vector<pair<int, int>> neighbours_list;
    if (x - 1 >= 0 && !vis[x - 1][y])
        neighbours_list.emplace_back(make_pair(x - 1, y));
    if (x + 1 < n && !vis[x + 1][y])
        neighbours_list.emplace_back(make_pair(x + 1, y));
    if (y - 1 >= 0 && !vis[x][y - 1])
        neighbours_list.emplace_back(make_pair(x, y - 1));
    if (y + 1 < n && !vis[x][y + 1])
        neighbours_list.emplace_back(make_pair(x, y + 1));

    return neighbours_list;
}

int find_shortest_distance(bool **vis, pair<int, int> s, pair<int, int> d, int n)
{
    int distance = 1;
    pair<int, int> node = s;
    queue<pair<int, int>> que, next_neighbours_list;
    que.push(s);
    while (que.size() != 0)
    {
        // cout << "Current Node: " << que.front().first << ", " << que.front().second << endl;
        vis[que.front().first][que.front().second] = true;

        vector<pair<int, int>> neighbours_list = get_valid_neighbours(vis, que.front(), n);
        // cout << "Current Distance: " << distance << endl;
        for (auto neighbour : neighbours_list)
        {
            // cout << "Neighbour Node: " << neighbour.first << ", " << neighbour.second << endl;

            if (neighbour == d)
            {
                // cout << "Found here\n";
                return distance;
            }
            next_neighbours_list.push(neighbour);
        }
        que.pop();
        if (que.empty())
        {
            que = next_neighbours_list;
            next_neighbours_list = {};
            distance++;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    char **a = new char *[n];
    bool **vis = new bool *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new char[n];
        vis[i] = new bool[n];
    }

    pair<int, int> s, d;
    int temp1, temp2;
    cin >> temp1 >> temp2;
    s = make_pair(temp1, temp2);
    cin >> temp1 >> temp2;
    d = make_pair(temp1, temp2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            vis[i][j] = false;
            if (a[i][j] == '#')
                vis[i][j] = true;
        }
    }

    cout << find_shortest_distance(vis, s, d, n);

    for (int i = 0; i < n; i++)
    {
        delete[] a[i];
        delete[] vis[i];
    }
    delete[] a;
    delete[] vis;

    return 0;
}