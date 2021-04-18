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
#include <utility>
#include <limits.h>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

using namespace std;

#define ScanInt(t) scanf("%d", &t)
#define ScanLongInt(t) scanf("%ld", &t)
#define ScanLongLongInt(t) scanf("%lld", &t)
#define ScanUnsignedLongLong(t) scanf("%llu", &t)
#define ScanChar(t) scanf("%c", &t)
#define ScanString(t) scanf("%s", t)
#define ScanFloat(t) scanf("%f", &t)
#define ScanDouble(t) scanf("%lf", &t)
#define ScanStringSpace(t) getline(cin, t)

#define numberOfDigits(t) floor(log10(t)) + 1
#define issPowerOf2(t) (t && (!(t & (t - 1))))

typedef long long int ll;
typedef unsigned long long int ull;

template <typename T>
bool inline ifEven(T x)
{
    if (x & 1)
        return false;
    else
        return true;
}

template <typename T>
T inline multiplyBy2(T x)
{
    return x << 1;
}

template <typename T>
T inline divideBy2(T x)
{
    return x >> 1;
}

template <typename T>
T inline mostSignificantDigit(T x)
{
    double k = log10(x);
    k = k - floor(k);
    int res = pow(10, k);
    return res;
}

/****** Template of Fast I/O Methods *********/
template <typename T>
inline void writeInt(T x)
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

void readInt(int &number)
{
    bool negative = false;
    register int c;

    number = 0;

    c = getchar();
    if (c == '-')
    {
        negative = true;

        c = getchar();
    }

    for (; (c > 47 && c < 58); c = getchar())
        number = number * 10 + c - 48;

    if (negative)
        number *= -1;
}

struct kthSubArr
{
    ull mul;
    ull kRoot;
};

struct lazyProp
{
    ull set;
    ull update;
};

void build_tree(int *arr, kthSubArr *tree, int start, int end, int treenode)
{
    if (start == end)
    {
        tree[treenode].mul = arr[start - 1];
        return;
    }
    int mid = (start + end) / 2;
    build_tree(arr, tree, start, mid, 2 * treenode);
    build_tree(arr, tree, mid + 1, end, 2 * treenode + 1);
    tree[treenode].mul = tree[2 * treenode].mul * tree[2 * treenode + 1].mul;
}

void lazyUpdate(kthSubArr *tree, lazyProp *lazy, int qType, int low, int high, int startR, int endR, int currPos, ull value)
{
    if (low > high)
    {
        return;
    }
    if (lazy[currPos].set != 1)
    {
        ull x = lazy[currPos].set;
        tree[currPos].mul = pow(x, high - low + 1);
        if (low != high)
        {
            lazy[2 * currPos].update = 1;
            lazy[2 * currPos + 1].update = 1;
            lazy[2 * currPos].set = x;
            lazy[2 * currPos + 1].set = x;
        }
        lazy[currPos].set = 1;
    }
    if (lazy[currPos].update != 1)
    {
        ull x = lazy[currPos].update;
        tree[currPos].mul *= pow(x, high - low + 1);
        if (low != high)
        {
            lazy[2 * currPos].update *= x;
            lazy[2 * currPos + 1].update *= x;
        }
        lazy[currPos].update = 1;
    }

    if (low > endR || high < startR)
    {
        return;
    }
    if (low >= startR && high <= endR)
    {
        if (qType == 2)
        {
            tree[currPos].mul *= pow(value, high - low + 1);
            if (low != high)
            {
                lazy[2 * currPos].update *= value;
                lazy[2 * currPos + 1].update *= value;
            }
        }
        else
        {
            tree[currPos].mul = pow(value, high - low + 1);
            if (low != high)
            {
                lazy[2 * currPos].update = 1;
                lazy[2 * currPos + 1].update = 1;
                lazy[2 * currPos].set = value;
                lazy[2 * currPos + 1].set = value;
            }
        }
        return;
    }

    int mid = (low + high) / 2;
    lazyUpdate(tree, lazy, qType, low, mid, startR, endR, 2 * currPos, value);
    lazyUpdate(tree, lazy, qType, mid + 1, high, startR, endR, 2 * currPos + 1, value);
    tree[currPos].mul = tree[2 * currPos].mul * tree[2 * currPos + 1].mul;
}

ull query(int s, int e, int l, int r, int i, kthSubArr *tree, lazyProp *lazyTree)
{
    if (s > e)
        return 1;
    if (lazyTree[i].set != 1)
    {
        ull x = lazyTree[i].set;
        tree[i].mul = pow(x, e - s + 1);
        if (s != e)
        {
            lazyTree[2 * i].update = 1;
            lazyTree[2 * i + 1].update = 1;
            lazyTree[2 * i].set = x;
            lazyTree[2 * i + 1].set = x;
        }
        lazyTree[i].set = 1;
    }

    if (lazyTree[i].update != 1)
    {
        ull x = lazyTree[i].update;
        tree[i].mul *= pow(x, e - s + 1);
        if (s != e)
        {
            lazyTree[2 * i].update *= x;
            lazyTree[2 * i + 1].update *= x;
        }
        lazyTree[i].update = 1;
    }
    if (e < l || s > r)
    {
        return 1;
    }
    if (s >= l && e <= r)
    {
        return tree[i].mul;
    }
    int mid = (s + e) / 2;
    ull a1 = query(s, mid, l, r, 2 * i, tree, lazyTree);
    ull a2 = query(mid + 1, e, l, r, 2 * i + 1, tree, lazyTree);
    return a1 * a2;
}

double kthRoot(ull A, int N)
{
    // intially guessing a random number between
    // 0 and 9
    double xPre = rand() % 10;

    //  smaller eps, denotes more accuracy
    double eps = 1e-3;

    // initializing difference between two
    // roots by INT_MAX
    double delX = INT_MAX;

    //  xK denotes current value of x
    double xK;

    //  loop untill we reach desired accuracy
    while (delX > eps)
    {
        //  calculating current value from previous
        // value by newton's method
        xK = ((N - 1.0) * xPre +
              (double)A / pow(xPre, N - 1)) /
             (double)N;
        delX = abs(xK - xPre);
        xPre = xK;
    }

    return xK;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, q;
    cin >> n >> k >> q;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    kthSubArr *arrTree = new kthSubArr[4 * n];
    lazyProp *lazyTree = new lazyProp[4 * n];

    build_tree(arr, arrTree, 1, n, 1);

    // for (int i = 1; i <= 2 * n; i++)
    // {
    //     cout << arrTree[i].mul << " ";
    // }
    // cout << "\n";

    for (int i = 0; i < 4 * n; i++)
    {
        lazyTree[i].set = 1;
        lazyTree[i].update = 1;
    }

    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int left, right;
            cin >> left >> right;
            // left--, right--;
            ull num = query(1, n, left, right, 1, arrTree, lazyTree);
            // cout << num << endl;
            float kthRootValue = kthRoot(num, k);
            if (fmod(kthRootValue, 1) == 0)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
        else if (type == 2 || type == 3)
        {
            int left, right;
            cin >> left >> right;
            ull value;
            if (type == 2)
            {
                ull multiplier, powerMul;
                cin >> multiplier >> powerMul;
                value = pow(multiplier, powerMul);
            }
            else
            {
                cin >> value;
            }
            lazyUpdate(arrTree, lazyTree, type, 1, n, left, right, 1, value);
        }
        // cout << "New Array: ";
        // for (int i = 1; i <= 2 * n; i++)
        // {
        //     cout << arrTree[i].mul << " ";
        // }
        // cout << "\n";
    }

    delete[] arr;
    delete[] arrTree;
    delete[] lazyTree;

    return 0;
}