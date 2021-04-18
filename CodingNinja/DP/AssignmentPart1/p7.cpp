#include <iostream>
#include <math.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    double **d;
    d = new double *[n];
    double x[n], y[n], f[n], h[n];

    for (int i = 0; i < n; i++)
    {
        d[i] = new double[i];
        cin >> x[i] >> y[i] >> f[i];
        h[i] = INT_MIN;
        // cout << "Distances for point at index " << i << ": " << x[i] << ", " << y[i] << endl;
        for (int j = 0; j < i; j++)
        {
            d[i][j] = sqrt(pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2));
            // cout << "w.r.t index " << j << ": " << x[j] << ", " << y[j] << ":\t" << d[i][j] << endl;
        }
    }

    h[0] = f[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            double temp = f[i] + h[j] - d[i][j];
            if (temp > h[i])
            {
                h[i] = temp;
            }
        }
    }
    // cout << "Maximum Possible Happiness at points:\n";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "Index: " << i << " Point :(" << x[i] << ", " << y[i] << ")\tHappiness: " << h[i] << endl;
    // }
    cout << fixed << setprecision(6) << h[n - 1];
}