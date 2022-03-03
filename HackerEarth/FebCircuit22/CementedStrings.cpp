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

struct Buckets
{
    int left, right, updation;
    struct Buckets *left_child, *right_child;

    Buckets(int left_val, int right_val)
    {
        left = left_val, right = right_val, updation = 0;
        left_child = NULL, right_child = NULL;
    }
};

void insert_into_bucket(Buckets *bucket, int left, int right)
{
    // cout << "left: " << left << "\tright: " << right << endl;
    if ((left + right) / 2 + 1 <= right)
    {
        bucket->left_child = new Buckets(left, (left + right) / 2);
        bucket->right_child = new Buckets((left + right) / 2 + 1, right);
    }
    if (left < right)
    {
        insert_into_bucket(bucket->left_child, left, (left + right) / 2);
        insert_into_bucket(bucket->right_child, (left + right) / 2 + 1, right);
    }
}

void update_bucket(Buckets *bucket, int index)
{
    // cout << "left: " << bucket->left << "\tright: " << bucket->right << "\tindex: " << index << endl;
    if (index > bucket->right)
    {
        return;
    }
    else if (index < bucket->right)
    {
        bucket->updation--;
        if (bucket->left_child)
            update_bucket(bucket->left_child, index);
        if (bucket->right_child)
            update_bucket(bucket->right_child, index);
    }
}

void print_bucket(Buckets *bucket)
{
    cout << "left: " << bucket->left << "\tright: " << bucket->right << "\tupdation: " << bucket->updation << endl;
    if (bucket->left_child)
    {
        print_bucket(bucket->left_child);
    }
    if (bucket->left_child)
    {
        print_bucket(bucket->right_child);
    }
}

int get_val(Buckets *bucket, int index)
{
    // cout << "left: " << bucket->left << "\tright: " << bucket->right << "\tindex: " << index << endl;

    if (bucket->left == index && bucket->right == index)
    {
        return 1 + index + bucket->updation;
    }
    if (index >= bucket->left && index <= bucket->right)
    {
        int left_val = get_val(bucket->left_child, index);
        int right_val = get_val(bucket->right_child, index);
        if (left_val != -1)
            return left_val;
        if (right_val != -1)
            return right_val;
    }
    return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<int> buckets_arr[26];
        for (int i = 0; i < n; i++)
        {
            buckets_arr[int(s[i]) - int('a')].emplace_back(i);
        }

        int total_cost = 0;

        struct Buckets *root = new Buckets(0, n - 1);
        insert_into_bucket(root, 0, n - 1);

        for (int i = 0; i < 26; i++)
        {
            if (buckets_arr[i].size() > 0)
            {
                for (auto b : buckets_arr[i])
                {
                    update_bucket(root, b);
                    total_cost += get_val(root, b);
                }
            }
        }

        cout << total_cost << "\n";

        // update_bucket(root, 1);
        // cout << get_val(root, 1) << endl;

        // update_bucket(root, 0);
        // cout << get_val(root, 0) << endl;

        // update_bucket(root, 3);
        // cout << get_val(root, 3) << endl;
        // update_bucket(root, 2);
        // cout << get_val(root, 2) << endl;
        // update_bucket(root, 4);
        // cout << get_val(root, 4) << endl;
        // print_bucket(root);
    }

    return 0;
}