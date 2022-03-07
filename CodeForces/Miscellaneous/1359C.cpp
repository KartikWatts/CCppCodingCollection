#include <iostream>

using namespace std;

int main()
{
    int test, h, c, t;
    cin >> test;
    while (test--)
    {
        int cups = 0;
        cin >> h >> c >> t;
        double curTemp = double(h);
        double minDiff = abs(double(t) - curTemp);
        bool hot = true;
        int hotT = curTemp;
        int coldT = 0;
        cups++;
        while (minDiff > 0)
        {
            if (hot == true)
            {
                curTemp = double(curTemp) + (double((double(c) - double(curTemp))) / double(cups + 1));
                cout << curTemp << "\t";
                hot = false;
                if (coldT > curTemp)
                {
                    break;
                }
                else
                {
                    coldT = curTemp;
                    minDiff = abs(double(t) - curTemp);
                    cups++;
                }
            }
            else if (hot == false)
            {
                curTemp = double(curTemp) + (double((double(h) - double(curTemp))) / double(cups + 1));
                cout << curTemp << "\t";
                hot = true;
                if (hotT < curTemp)
                {
                    break;
                }
                else
                {
                    hotT = curTemp;
                    minDiff = abs(double(t) - curTemp);
                    cups++;
                }
            }
        }
        cout << cups << endl;
    }
}