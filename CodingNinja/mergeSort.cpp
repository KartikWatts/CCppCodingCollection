#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

long long result = 0;

void merge(int s, int m, int e, int a[])
{
    int i, j, k;
    int n1 = m - s + 1, n2 = e - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
    {

        L[i] = a[s + i];
        // cout << L[i] << endl;
    }
    for (j = 0; j < n2; j++)
    {

        R[j] = a[m + 1 + j];
        // cout << R[j] << endl;
    }
    i = 0, j = 0, k = s;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            result = result + (n1 - i);
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[j] = R[i];
        j++;
        k++;
    }
}

void divide(int start, int end, int a[])
{
    if (start < end)
    {
        // cout << "Dividing for Start: " << start << " End: " << end;
        int mid = start + (end - start) / 2;
        divide(start, mid, a);
        divide(mid + 1, end, a);
        merge(start, mid, end, a);
    }
}

long long solve(int A[], int n)
{
    // Write your code here.
    divide(0, n - 1, A);
    return result;
}

int main()
{
    int n, A[MAXN];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    cout << solve(A, n) << endl;
}