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

void buildTree(int *a, int start, int end, int *tree, int treeNode)
{
    if (start == end)
    {
        tree[treeNode] = a[start];
        return;
    }

    int mid = (start + end) / 2;

    buildTree(a, start, mid, tree, 2 * treeNode);
    buildTree(a, mid + 1, end, tree, 2 * treeNode + 1);

    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

void updateTree(int *a, int start, int end, int *tree, int treeNode, int idx, int value)
{
    if (start == end)
    {
        a[idx] = value;
        tree[treeNode] = value;
        return;
    }

    int mid = (start + end) / 2;
    if (idx > mid)
    {
        updateTree(a, mid + 1, end, tree, 2 * treeNode + 1, idx, value);
    }
    else
    {
        updateTree(a, start, mid, tree, 2 * treeNode, idx, value);
    }

    tree[treeNode] = tree[2 * treeNode] + tree[2 * treeNode + 1];
}

int queryTree(int start, int end, int *tree, int treeNode, int left, int right)
{
    if (start > right || end < left)
    {
        return 0;
    }
    else if (start >= left && end <= right)
    {
        return tree[treeNode];
    }
    else
    {
        int mid = (start + end) / 2;
        int ans1 = queryTree(start, mid, tree, 2 * treeNode, left, right);
        int ans2 = queryTree(mid + 1, end, tree, 2 * treeNode + 1, left, right);
        return ans1 + ans2;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int tree[4 * n];

    buildTree(a, 0, n - 1, tree, 1);

    int index, newVal;
    cin >> index;
    cin >> newVal;
    updateTree(a, 0, n - 1, tree, 1, index, newVal);

    for (int i = 1; i < 2 * n; i++)
    {
        cout << tree[i] << "\n";
    }
    int left, right;
    cin >> left >> right;
    cout << queryTree(0, n - 1, tree, 1, left, right);

    return 0;
}