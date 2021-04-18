#include <bits/stdc++.h>
using namespace std;

int num_codes(int *input, int size)
{
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
        if ((input[i - 1] == 0) && ((input[i - 2] > 2) || (input[i - 2] == 0)))
        {
            // cout << input[i - 1] << "\t" << input[i - 2] << "\tRunning this condition\n";
            return 0;
        }
        output[i] = output[i - 1];
        if (input[i - 1] != 0 && input[i - 2] != 0 && (input[i - 2] * 10 + input[i - 1]) <= 26)
        {
            output[i] += output[i - 2];
        }
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
