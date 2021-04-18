#include <iostream>
#include <vector>
#include <map>

typedef unsigned long long ull;
typedef unsigned long long uint_t;

using namespace std;

bool decToBinary(int n, int setLimit)
{
    int binaryNum[32];
    int num = n;
    int i = 0;
    long long bitset = 0;
    while (n > 0)
    {
        binaryNum[i] = n % 2;
        if (n % 2 == 1)
        {
            bitset++;
        }
        n = n / 2;
        i++;
    }

    if (bitset == setLimit)
    {
        return true;
    }
    return false;
}

uint_t snoob(uint_t x)
{

    uint_t rightOne;
    uint_t nextHigherOneBit;
    uint_t rightOnesPattern;

    uint_t next = 0;

    if (x)
    {

        rightOne = x & -(signed)x;

        nextHigherOneBit = x + rightOne;

        rightOnesPattern = x ^ nextHigherOneBit;

        rightOnesPattern = (rightOnesPattern) / rightOne;

        rightOnesPattern >>= 2;

        next = nextHigherOneBit | rightOnesPattern;
    }

    return next;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, l;
        cin >> n >> l;
        vector<long> v;
        ull maxE = 0;
        for (int i = 0; i < n; i++)
        {
            ull temp;
            cin >> temp;
            v.push_back(temp);
            maxE = max(maxE, temp);
        }
        ull num = 0;
        for (long long i = 0; i <= 1000000000; i++)
        {
            if (decToBinary(i, l))
            {
                num = i;
                break;
            };
        }
        int maxSum = 0;
        map<int, vector<ull>> m;
        while (num <= 1000000000)
        {
            ull sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum = sum + (v[i] & num);
            }
            if (sum >= maxSum)
            {
                maxSum = sum;
                m[maxSum].push_back(num);
            }
            num = snoob(num);
            // if (num <= maxE)
            //     cout << "Next higher number with same number of set bits is " << num << endl;
        }
        // cout << "Max sum for these bits num: ";
        // for (auto it : m[maxSum])
        // {
        //     cout << it << " ";
        // }
        // cout << "Final Answer: " << endl;
        cout << m[maxSum].size() << endl;
    }
}