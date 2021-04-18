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

int numDim = pow(10, 2);
int dayDim = pow(10, 6);
int mod = pow(10, 9) + 7;

int mat1[100][1000000];
int mat2[100][1000000];
int mat3[100][1000000];

void initiate()
{
    //HANDLE FIRST MATRIX: 0 TO 100
    for (int i = 0; i < dayDim; i++)
    {
        mat1[0][i] = 1;
    }
    for (int i = 0; i < numDim; i++)
    {
        mat1[i][0] = i + 1;
    }
    for (int tempIndex = 1; tempIndex < numDim; tempIndex++)
    {
        for (int i = 1; i < dayDim; i++)
        {
            mat1[tempIndex][i] = ((mat1[tempIndex - 1][i] % mod) + (mat1[tempIndex][i - 1] % mod)) % mod;
        }
    }

    // cout << "First Matrix Processed Successfully\n";
    //HANDLE SECOND MATRIX: 100 TO 10000
    // for (int i = 0; i < numDim; i++)
    // {
    //     mat2[i][0] = i + 1;
    // }
    // for (int i = 1; i < dayDim; i++)
    // {
    //     mat2[0][i] = ((mat1[1000000 - 1][i] % mod) + (mat2[0][i - 1] % mod)) % mod;
    // }
    // for (int tempIndex = 1; tempIndex < numDim; tempIndex++)
    // {
    //     for (int i = 1; i < dayDim; i++)
    //     {
    //         mat2[tempIndex][i] = ((mat2[tempIndex - 1][i] % mod) + (mat2[tempIndex][i - 1] % mod)) % mod;
    //     }
    // }

    // cout << "Second Matrix Processed Successfully\n";
    //HANDLE THIRD MATRIX: 10000 TO 1000000
    // for (int i = 0; i < numDim; i++)
    // {
    //     mat3[i][0] = i + 1;
    // }
    // for (int i = 1; i < dayDim; i++)
    // {
    //     mat3[0][i] = ((mat2[1000000 - 1][i] % mod) + (mat3[0][i - 1] % mod)) % mod;
    // }
    // for (int tempIndex = 1; tempIndex < numDim; tempIndex++)
    // {
    //     for (int i = 1; i < dayDim; i++)
    //     {
    //         mat3[tempIndex][i] = ((mat3[tempIndex - 1][i] % mod) + (mat3[tempIndex][i - 1] % mod)) % mod;
    //     }
    // }

    // cout << "Third Matrix Processed Successfully\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    // cout << "Started Initiation Process..\n";
    initiate();
    // cout << "Finished Initiation Process..\n";
    while (t--)
    {
        int n, k, m;
        cin >> n >> k >> m;
        int range = n - k + 1;
        if (range < 100)
            cout << mat1[range - 1][m - 1] << "\n";
        else
            cout << "-1\n";
    }

    return 0;
}