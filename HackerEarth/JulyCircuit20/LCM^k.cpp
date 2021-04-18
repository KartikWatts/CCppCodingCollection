#include <bits/stdc++.h>
#define F first
#define S second
#define MAX 10000003
using namespace std;

typedef long long ll;

int prime[MAX];

int power(int a, int n, int m)
{
    if (n == 0)
        return 1;
    int p = power(a, n / 2, m) % m;
    p = (p * p) % m;
    if (n & 1)
        p = (p * a) % m;
    return p;
}

void PrimeFactorsWithSieve()
{
    prime[0] = prime[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
        if (prime[i] == 0)
        {
            for (int j = i * 2; j < MAX; j += i)
            {
                if (prime[j] == 0)
                {
                    prime[j] = i;
                }
            }
            prime[i] = i;
        }
    }
}

ll lcmModuloM(const int *ar, int n, int m, unordered_map<int, int> max_map)
{

    for (int i = 0; i < n; i++)
    {
        int num = ar[i];
        unordered_map<int, int> temp;

        while (num > 1)
        {
            int factor = prime[num];
            temp[factor]++;
            num /= factor;
        }

        for (auto it : temp)
        {
            max_map[it.first] = max(max_map[it.first], it.second);
        }
    }

    ll ans = 1;

    for (auto it : max_map)
    {
        ans = (ans * power(it.F, it.S, m)) % m;
    }

    return ans;
}

// Driver code
int main()
{
    PrimeFactorsWithSieve();
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int arr[n];
        unordered_map<int, int> max_map;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (n == 1 && m == 1 && k == 1)
        {
            cout << "0\n";
            continue;
        }
        int lcm = lcmModuloM(arr, n, m, max_map);
        // cout << lcm << endl;
        int result = lcm;
        for (int i = 0; i < k - 1; i++)
        {
            result = (result % m * lcm % m) % m;
        }

        // for (int i = 0; i < k - 1; i++)
        // {
        //     result = (lcm * lcm) % m;
        // }
        cout << result << endl;
    }

    return 0;
}