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

struct node
{
    int maxSum;
    int sum;
    int bestPrefixSum;
    int bestSuffixSum;
};

void buildTree(int *a, int start, int end, node *tree, int treeNode)
{
    if (start == end)
    {
        tree[treeNode].maxSum = a[start];
        tree[treeNode].sum = a[start];
        tree[treeNode].bestPrefixSum = a[start];
        tree[treeNode].bestSuffixSum = a[start];
        return;
    }

    int mid = (start + end) / 2;

    buildTree(a, start, mid, tree, 2 * treeNode);
    buildTree(a, mid + 1, end, tree, 2 * treeNode + 1);

    node left = tree[2 * treeNode];
    node right = tree[2 * treeNode + 1];

    tree[treeNode].maxSum = max(max(left.maxSum, right.maxSum), max(max(left.bestSuffixSum + right.sum, left.sum + right.bestPrefixSum), left.bestSuffixSum + right.bestPrefixSum));

    tree[treeNode].sum = left.sum + right.sum;

    tree[treeNode].bestPrefixSum = max(left.bestPrefixSum, left.sum + right.bestPrefixSum);

    tree[treeNode].bestSuffixSum = max(right.bestSuffixSum, left.bestSuffixSum + right.sum);

    return;
}

void updateTree(int *a, int start, int end, node *tree, int treeNode, int idx, int value)
{
    if (start == end)
    {
        tree[treeNode].maxSum = value;
        tree[treeNode].sum = value;
        tree[treeNode].bestPrefixSum = value;
        tree[treeNode].bestSuffixSum = value;
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

    node left = tree[2 * treeNode];
    node right = tree[2 * treeNode + 1];

    tree[treeNode].maxSum = max(max(left.maxSum, right.maxSum), max(max(left.bestSuffixSum + right.sum, left.sum + right.bestPrefixSum), left.bestSuffixSum + right.bestPrefixSum));

    tree[treeNode].sum = left.sum + right.sum;

    tree[treeNode].bestPrefixSum = max(left.bestPrefixSum, left.sum + right.bestPrefixSum);

    tree[treeNode].bestSuffixSum = max(right.bestSuffixSum, left.bestSuffixSum + right.sum);
}

node queryTree(int start, int end, node *tree, int treeNode, int left, int right)
{
    // cout << "Looking from " << start << " to " << end << "\n";
    if (start > right || end < left)
    {
        // cout << "Out of Range\n";
        node res;
        res.maxSum = 0;
        res.sum = 0;
        res.bestPrefixSum = 0;
        res.bestSuffixSum = 0;
        return res;
    }
    else if (start >= left && end <= right)
    {
        // cout << "Within Perfect Range\n";
        node res;
        res = tree[treeNode];
        return res;
    }
    else
    {
        // cout << "Left and Right Nodes\n";
        int mid = (start + end) / 2;
        node leftNode;
        node rightNode;
        leftNode = queryTree(start, mid, tree, 2 * treeNode, left, right);
        rightNode = queryTree(mid + 1, end, tree, 2 * treeNode + 1, left, right);

        node res;

        res.maxSum = max(max(leftNode.maxSum, rightNode.maxSum), max(max(leftNode.bestSuffixSum + rightNode.sum, leftNode.sum + rightNode.bestPrefixSum), leftNode.bestSuffixSum + rightNode.bestPrefixSum));

        res.sum = leftNode.sum + rightNode.sum;

        res.bestPrefixSum = max(leftNode.bestPrefixSum, leftNode.sum + rightNode.bestPrefixSum);

        res.bestSuffixSum = max(rightNode.bestSuffixSum, leftNode.bestSuffixSum + rightNode.sum);
        // cout << "Max found at: " << res.maxNum << "\t"
        //      << "SMax found at: " << res.sMaxNum << "\n";
        return res;
    }
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    node tree[3 * n];

    buildTree(a, 0, n - 1, tree, 1);

    // for (int i = 1; i < 2 * n; i++)
    // {
    //     cout << tree[i].maxSum << "\t";
    // }

    int q;
    cin >> q;
    while (q--)
    {
        int left, right;
        cin >> left >> right;
        node res;
        res = queryTree(0, n - 1, tree, 1, left - 1, right - 1);
        cout << res.maxSum << "\n";
    }

    return 0;
}