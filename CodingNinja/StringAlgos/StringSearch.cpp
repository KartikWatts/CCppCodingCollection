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

int *kmp(char pat[])
{
    int len = strlen(pat);
    int *output = new int[len];
    output[0] = 0;
    int i = 1, j = 0;
    while (i < len)
    {
        // cout << "On index " << i << "with j= " << j << "\t";
        if (pat[i] == pat[j])
        {
            j++;
            output[i] = j;
            i++;
        }
        else
        {
            if (j != 0)
            {
                j = output[j - 1];
            }
            else
            {
                output[i] = 0;
                i++;
            }
        }
    }
    return output;
}

int findString(char s[], char t[])
{
    int patLen = strlen(t);
    int strLen = strlen(s);
    int *patMatch = kmp(t);

    int i = 0, j = 0;
    while (j < patLen && i < strLen)
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = patMatch[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    if (j == patLen)
        return i - j;

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    char s[1000], t[1000];
    cin.getline(s, 1000);
    cin.getline(t, 1000);
    // cout << s << " " << t;
    cout << findString(s, t);

    return 0;
}