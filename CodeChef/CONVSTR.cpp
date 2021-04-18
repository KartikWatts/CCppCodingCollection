#include <iostream>
#include <string.h>

using namespace std;

void convertString(char a[], char b[], int n, int ps[])
{
    while (strcmp(a, b) == 0)
    {

        char max = '@';
        char maxTobeConverted = '@';
        int maxIndex = -1;

        for (int i = 0; i < n; i++)
        {
            if (int(a[i] < b[i]))
            {
                cout << "-1\n";
            }
        }

        bool isAllprocessed = true;
        for (int i = 0; i < n; i++)
        {
            if (ps[i] == 0)
            {
                isAllprocessed = false;
            }
        }
        if (isAllprocessed == true)
        {
            cout << "-1\n";
        }

        for (int i = 0; i < n; i++)
        {

            if (a[i] > max && ps[i] != 0)
            {
                max = a[i];
                maxTobeConverted = b[i];
            }
        }
        ps[maxIndex] = 1;
        bool possible = false;
        int selectedIndex[n];
        int sId = 0;
        if (a[maxIndex] != b[maxIndex])
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] == b[maxIndex])
                {
                    possible = true;
                }
            }
            if (possible == true)
            {
                for (int i = 0; i < n; i++)
                {
                    if (b[i] == b[maxIndex])
                    {
                        selectedIndex[sId] = i;
                        ps[i] = 1;
                    }
                }
                cout << sId;
                for (int i = 0; i < sId; i++)
                {
                    cout << " " << selectedIndex[i];
                }
            }
            else
            {
                cout << "-1\n";
            }
        }
    }
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        char a[n], b[n];
        cin >> a;
        cin >> b;
        cout << a << "\t" << b;
        int pStringArr[n];
        for (int i = 0; i < n; i++)
        {
            pStringArr[i] = 0;
        }
        convertString(a, b, n, pStringArr);
        // if (strcmp(a, b) == 0)
        // {
        //     cout << endl
        //          << "equal";
        // }
    }
}