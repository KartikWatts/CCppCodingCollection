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

class trieNode
{
public:
    trieNode *left;
    trieNode *right;
    int leafNodes;
};

int calculateLeafNodes(trieNode *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else if (node->left == NULL && node->right == NULL)
    {
        node->leafNodes = 1;
        return 1;
    }
    else
    {
        int leftNodes = calculateLeafNodes(node->left);
        int rightNodes = calculateLeafNodes(node->right);
        node->leafNodes = leftNodes + rightNodes;
        return (node->leafNodes);
    }
}

void insert(int n, trieNode *head)
{
    trieNode *curr = head;
    for (int i = 31; i >= 0; i--)
    {
        int b = (n >> i) & 1;
        if (b == 0)
        {
            if (!curr->left)
            {
                curr->left = new trieNode();
            }
            curr = curr->left;
        }
        else
        {
            if (!curr->right)
            {
                curr->right = new trieNode();
            }
            curr = curr->right;
        }
    }
    calculateLeafNodes(head);
}

void showLeafNodes(trieNode *node)
{
    if (node)
    {
        cout << node->leafNodes << "\t";
    }
    if (node->left)
    {
        showLeafNodes(node->left);
    }
    if (node->right)
    {
        showLeafNodes(node->right);
    }
}

void countTotalXor(trieNode *head, int n, int k, int &maxRes)
{
    trieNode *curr = head;
    for (int j = 31; j >= 0; j--)
    {
        int b = (n >> j) & 1;
        int kb = (k >> j) & 1;
        if (b == 0 && kb == 1)
        {
            if (curr->left)
            {
                maxRes += curr->left->leafNodes;
            }
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                break;
            }
        }
        if (b == 0 && kb == 0)
        {
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                break;
            }
        }
        if (b == 1 && kb == 1)
        {
            if (curr->right)
            {
                maxRes += curr->right->leafNodes;
            }
            if (curr->left)
            {
                curr = curr->left;
            }
            else
            {
                break;
            }
        }
        if (b == 1 && kb == 0)
        {
            if (curr->right)
            {
                curr = curr->right;
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n;
        cin >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int maxRes = 0;
        int xore = 0;
        for (int i = 0; i < n; i++)
        {
            trieNode *head = new trieNode();
            xore = xore ^ arr[i];
            insert(xore, head);
            countTotalXor(head, xore, k, maxRes);
        }

        // cout << "Show leaf nodes for all\n";
        // showLeafNodes(head);
        cout << maxRes << "\n";
    }
    return 0;
}