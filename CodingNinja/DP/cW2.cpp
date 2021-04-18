#include <bits/stdc++.h>
using namespace std;

int num_codes(int *input, int size)
{
    int mod = pow(10, 9) + 7;
    int *output = new int[size + 1];
    output[0] = 1;
    output[1] = 1;

    // for (int i = 0; i < size; i++)
    // {
    //     cout << input[i];
    // }
    // cout << endl;

    for (int i = 2; i <= size; i++)
    {
        output[i] = 0;
        if (input[i - 1] > 0)
            output[i] += output[i - 1] % mod;

        if ((input[i - 1] <= 6 && input[i - 2] == 2) || (input[i - 2] == 1))
            output[i] += output[i - 2] % mod;
    }
    int ans = output[size];
    delete[] output;
    return ans;
}

int main()
{
    while (1)
    {
        string str;
        cin >> str;
        if (str == "0")
        {
            break;
        }
        int n = str.size();
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = str[i] - '0';
        }

        cout << num_codes(a, n) << endl;
        // for (int i = 0; i < n; i++)
        // {
        //     cout << a[i];
        // }
        // cout << endl;

        delete[] a;
    }
    return 0;
}
