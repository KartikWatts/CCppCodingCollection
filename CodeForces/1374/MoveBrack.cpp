#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int openB = 0, closeB = 0;
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                openB++;
            }
            if (s[i] == ')')
            {
                closeB++;
            }
            if (closeB > openB)
            {
                closeB--;
                res++;
            }
        }
        cout << res << endl;
    }
}