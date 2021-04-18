#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Restaurant
{
    long long l, r;
};

struct Customer
{
    long long a, t;
};

bool sortRestaurant(Restaurant r1, Restaurant r2)
{
    // if (r1.l == 4 && r2.l == 4)
    if (r1.l != r2.l)
    {
        return r1.l < r2.l;
    }
    if (r1.r != r2.r)
    {
        return r1.r < r2.r;
    }
    return r1.l == r2.r;
}

bool sortCustomer(Customer c1, Customer c2)
{
    return c1.a <= c2.a;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        Restaurant R[n];
        Customer C[m];
        long long Res[m];
        map<long long, long long> result;
        for (int i = 0; i < n; i++)
        {
            cin >> R[i].l >> R[i].r;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> C[i].a;
            Res[i] = C[i].a;
            C[i].t = -1;
        }
        sort(R, R + n, sortRestaurant);
        sort(C, C + m, sortCustomer);
        int processed = 0;
        int customer = 0;
        while (processed < n && customer < m)
        {
            long long temp = C[customer].a;
            if (C[customer].a < R[processed].l)
            {
                C[customer].t = R[processed].l - C[customer].a;
                result.insert(pair<long long, long long>(C[customer].a, C[customer].t));
                customer++;
                while (C[customer].a == temp)
                    customer++;
            }
            else if (C[customer].a >= R[processed].r)
            {
                processed++;
            }
            else if (C[customer].a >= R[processed].l && C[customer].a < R[processed].r)
            {
                C[customer].t++;
                result.insert(pair<long long, long long>(C[customer].a, C[customer].t));
                customer++;
                while (C[customer].a == temp)
                    customer++;
            }
        }
        if (processed == n && customer != m)
        {
            C[customer].t = -1;
            result.insert(pair<long long, long long>(C[customer].a, C[customer].t));
        }
        for (int i = customer + 1; i < m; i++)
        {
            if (result.find(C[customer].a) == result.end())
            {
                result.insert(pair<long long, long long>(C[customer].a, -1));
            }
        }
        for (int i = 0; i < m; i++)
        {
            cout << result[Res[i]] << endl;
        }
    }
}