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

struct TrieNode
{
    char word;
    int weight;
    vector<TrieNode *> nextWords;
};

void insertNode(string s, int w, TrieNode *head)
{
    TrieNode *currNode = head;
    for (int i = 0; i < s.length(); i++)
    {
        // cout << "Inserting '" << s[i] << "'\n";
        bool inserted = false;
        vector<TrieNode *> currVectors = currNode->nextWords;
        for (auto it : currVectors)
        {
            // cout << it->word;
            if (it->word == s[i])
            {
                if (w > it->weight)
                {
                    it->weight = w;
                }
                inserted = true;
                currNode = it;
                break;
            }
        }
        if (inserted == false)
        {
            TrieNode *newNode = new TrieNode;
            newNode->word = s[i], newNode->weight = w;
            currNode->nextWords.emplace_back(newNode);
            currNode = newNode;
        }
    }
}

void showNodes(TrieNode *node)
{
    TrieNode *currNode = node;
    vector<TrieNode *> currVectors = currNode->nextWords;
    for (auto it : currVectors)
    {
        cout << it->word << " " << it->weight << "\n";
        showNodes(it);
    }
}

int searchWord(string t, TrieNode *head)
{
    TrieNode *currNode = head;
    int weight = -1;
    for (int i = 0; i < t.length(); i++)
    {
        bool found = false;
        vector<TrieNode *> currVectors = currNode->nextWords;
        for (auto it : currVectors)
        {
            // cout << it->word;
            if (it->word == t[i])
            {
                currNode = it;
                weight = it->weight;
                found = true;
                break;
            }
        }
        if (found == false)
        {
            return -1;
        }
    }
    return weight;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    TrieNode *head = new TrieNode;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int w;
        cin >> w;
        insertNode(s, w, head);
    }
    // showNodes(head);
    for (int i = 0; i < q; i++)
    {
        string t;
        cin >> t;
        cout << searchWord(t, head) << "\n";
    }

    return 0;
}