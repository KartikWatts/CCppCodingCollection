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

void decToBinary(int n)
{
    // array to store binary number
    int binaryNum[32];

    // counter for binary array
    int i = 0;
    while (n > 0)
    {

        // storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i; j < 10; j++)
    {
        binaryNum[j] = 0;
    }

    // printing binary array in reverse order
    for (int j = 9; j >= 0; j--)
        cout << binaryNum[j];
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);

    // int t;
    // cin >> t;
    // while (t--)
    // {
    int a[10] = {13, 12, 15, 11, 23, 43, 23, 45, 245, 56};
    int n = 10;
    cout << "Numbers are: ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
        decToBinary(a[i]);
        cout << "\t";
    }
    cout << endl;

    for (int i = 0; i <= 20; i++)
    {
        cout << "Xor with " << i << " ";
        decToBinary(i);
        cout << " gives: ";
        int res = 0;
        for (int j = 0; j < n; j++)
        {
            res += a[j] ^ i;
        }
        cout << res << " ";
        decToBinary(res);
        cout << endl;
    }
    cout << "Actual Xor of numbers: ";
    int myXor = 0;
    for (int i = 0; i < 4; i++)
    {
        myXor = myXor ^ a[i];
    }
    cout << myXor << " ";
    decToBinary(myXor);
    cout << endl;
    // }

    return 0;
}