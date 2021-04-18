#include <iostream>
#include <string.h>

typedef unsigned long long ull;
using namespace std;

int main()
{
    ull k, lk = 0, tk = 0;
    scanf("%llu", &k);
    int totalStr = 1;
    string result = "codeforce", temp;
    // printf("%s", result.c_str());
    cout << result;
    if (k <= 10000)
    {
        for (int i = 0; i < k; i++)
        {
            temp += 's';
        }
    }
    if (k > 10000)
    {
        tk = k / 10000;
        lk = k % 10000;
        totalStr = tk;
    }
    if (tk > 0)
    {
        for (int i = 0; i < 10000; i++)
        {
            temp += 's';
        }
    }
    for (int i = 0; i < totalStr; i++)
    {
        // printf("%s", temp.c_str());
        cout << temp;
    }
    if (lk > 0)
    {
        for (int i = 0; i < lk; i++)
        {
            printf("%c", 's');
        }
    }
}