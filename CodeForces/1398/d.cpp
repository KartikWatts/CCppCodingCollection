#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    int r, g, b;
    cin >> r >> g >> b;
    vector<int> red, gr, blue;
    for (int i = 0; i < r; i++)
    {
        int num;
        cin >> num;
        red.push_back(num);
    }
    for (int i = 0; i < g; i++)
    {
        int num;
        cin >> num;
        gr.push_back(num);
    }
    for (int i = 0; i < b; i++)
    {
        int num;
        cin >> num;
        blue.push_back(num);
    }
    cout << red.size();
    if (red.size() > 1)
        sort(red.begin(), red.end(), greater<int>());
    if (blue.size() > 1)
        sort(blue.begin(), blue.end(), greater<int>());
    if (gr.size() > 1)
        sort(gr.begin(), gr.end(), greater<int>());
    cout << "Working until";
    unsigned long long ans = 0;
    while ((!blue.empty() && !gr.empty()) || (!red.empty() && !gr.empty()) || (!blue.empty() && !red.empty()))
    {
        cout << "Red first: " << red.front() << "\t";
        cout << "Green first: " << gr.front() << "\t";
        cout << "Blue first: " << blue.front() << "\t";
        int num1, num2;
        if (red.empty() && !blue.empty() && !gr.empty())
        {
            num1 = blue.front();
            num2 = gr.front();
            blue.erase(blue.begin());
            gr.erase(gr.begin());
        }
        else if (blue.empty() && !red.empty() && !gr.empty())
        {
            num1 = red.front();
            num2 = gr.front();
            red.erase(red.begin());
            gr.erase(gr.begin());
        }
        else if (gr.empty() && !red.empty() && !blue.empty())
        {
            num1 = red.front();
            num2 = blue.front();
            blue.erase(blue.begin());
            red.erase(red.begin());
        }
        else
        {
            num1 = max(red.front(), max(blue.front(), gr.front()));
            if (num1 == red.front())
            {
                red.erase(red.begin());
            }
            else if (num1 == gr.front())
            {
                gr.erase(gr.begin());
            }
            else
            {
                blue.erase(blue.begin());
            }

            num2 = max(red.front(), max(blue.front(), gr.front()));
            if (num1 == red.front())
            {
                red.erase(red.begin());
            }
            else if (num1 == gr.front())
            {
                gr.erase(gr.begin());
            }
            else
            {
                blue.erase(blue.begin());
            }
        }
        cout << "\nNum1 Chosen: " << num1 << "\tNum2 Chosen: " << num2 << endl;
        ans += ((unsigned long long)num1 * (unsigned long long)num2);
    }
    cout << ans;
}