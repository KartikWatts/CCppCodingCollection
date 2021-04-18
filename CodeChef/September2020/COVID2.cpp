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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int v[n];
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int maxInfected = 0, minInfected = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            bool infectedAth[n];
            float position[n], positionDiff[n][n];
            for (int j = 0; j < n; j++)
            {
                position[j] = j;
                infectedAth[j] = false;
            }
            for (int k = 0; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    positionDiff[k][l] = position[k] - position[l];
                }
            }

            int infected = 1;
            infectedAth[i] = true;
            float time = 0;

            while (time < 6)
            {
                // cout << "For Time: " << time << "\n";
                // for (int j = 0; j < n; j++)
                // {
                //     cout << "Athlethe: " << j << "\tPosition: " << position[j] << endl;
                // }
                // cout << "Infected Athlethes so far:\t";
                // for (int j = 0; j < n; j++)
                // {
                //     if (infectedAth[j] == true)
                //     {
                //         cout << j << " ";
                //     }
                // }
                // cout << endl;

                for (int j = 0; j < n; j++)
                {
                    position[j] += v[j] * 0.01;
                }
                for (int j = 0; j < n; j++)
                {
                    bool changed = false;
                    if (infectedAth[j] == true)
                    {
                        for (int k = 0; k < n; k++)
                        {
                            if (infectedAth[k] == false)
                            {
                                if (positionDiff[j][k] <= 0 && position[j] >= position[k])
                                {
                                    infectedAth[k] = true;
                                    infected++;
                                    changed = true;
                                }
                                if (positionDiff[j][k] >= 0 && position[j] <= position[k])
                                {
                                    infectedAth[k] = true;
                                    infected++;
                                    changed = true;
                                }
                            }
                            positionDiff[j][k] = position[j] - position[k];
                        }
                    }
                    else
                    {
                        for (int k = 0; k < n; k++)
                        {
                            positionDiff[j][k] = position[j] - position[k];
                        }
                    }
                }
                time = time + 0.01;
            }

            // while (time < 20)
            // {
            //     for (int j = 0; j < n; j++)
            //     {
            //         position[j] += v[j] * 0.01;
            //     }
            //     for (int j = 0; j < n; j++)
            //     {
            //         bool changed = false;
            //         if (infectedAth[j] == true)
            //         {
            //             for (int k = 0; k < n; k++)
            //             {
            //                 if (infectedAth[k] == false)
            //                 {
            //                     if (positionDiff[j][k] <= 0 && position[j] >= position[k])
            //                     {
            //                         infectedAth[k] = true;
            //                         infected++;
            //                         changed = true;
            //                     }
            //                     if (positionDiff[j][k] >= 0 && position[j] <= position[k])
            //                     {
            //                         infectedAth[k] = true;
            //                         infected++;
            //                         changed = true;
            //                     }
            //                 }
            //                 positionDiff[j][k] = position[j] - position[k];
            //             }
            //         }
            //         else
            //         {
            //             for (int k = 0; k < n; k++)
            //             {
            //                 positionDiff[j][k] = position[j] - position[k];
            //             }
            //         }
            //     }
            //     time = time + 0.01;
            // }

            maxInfected = max(infected, maxInfected);
            minInfected = min(infected, minInfected);
        }

        cout << minInfected << " " << maxInfected << "\n";
    }

    return 0;
}