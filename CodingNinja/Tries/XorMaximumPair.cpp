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
};

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
}

int findMaxXorPair(trieNode *head, int *arr, int n)
{
    int max_xor = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int value = arr[i];
        trieNode *curr = head;
        int curr_xor = 0;
        for (int j = 31; j >= 0; j--)
        {
            int b = (value >> j) & 1;
            if (b == 0)
            {
                if (curr->right)
                {
                    curr_xor += pow(2, j);
                    curr = curr->right;
                }
                else
                {
                    curr = curr->left;
                }
            }
            else
            {
                if (curr->left)
                {
                    curr_xor += pow(2, j);
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                }
            }
        }
        max_xor = max(curr_xor, max_xor);
    }
    return max_xor;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[6] = {8, 1, 2, 15, 10, 5};
    trieNode *head = new trieNode();
    for (int i = 0; i < 6; i++)
    {
        insert(arr[i], head);
    }
    cout << findMaxXorPair(head, arr, 6);

    return 0;
}