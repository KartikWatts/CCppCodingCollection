#include <iostream>

using namespace std;

int editDistance(string s1, string s2)
{
    string st1, st2;
    int m, n;
    if (s1.length() >= s2.length())
    {
        st1 = s1;
        st2 = s2;
    }
    else
    {
        st1 = s2;
        st2 = s1;
    }
    m = st1.length();
    n = st2.length();
    for (int i = 0; i < m; i++)
    {
        if (st1[i] == st2[i])
        {
            continue;
        }
        if (st1[i + 1] == st2[i])
        {
            st1 = st1.substr(0, i) + st1.substr(i + 1, m - i);
                }
    }
}

int main()
{
    string s, t;
    cin >> s >> t;
    cout << editDistance(s, t);
}