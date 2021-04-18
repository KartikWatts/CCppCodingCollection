#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<int> largestDivisibleSubset(vector<int> &a)
{
    vector<int> result;
    set<int> temp;
    if (a.size() == 0)
    {
        return result;
    }
    if (a.size() == 1)
    {
        result.push_back(a[0]);
        return result;
    }

    for (int j = 0; j < a.size() - 1; j++)
    {
        for (int i = j + 1; i < a.size(); i++)
        {
            cout << "Current Super elements: " << a[j] << " " << a[i] << endl;
            // cout << "a[i] % a[i+1] = " << a[i] % a[i + 1] << endl;
            // cout << "a[i+1] % a[i] = " << a[i + 1] % a[i] << endl;
            if ((a[i] % a[j] == 0 || a[i] < a[j]) && (a[j] % a[i] == 0 || a[j] < a[i]))
            {
                // cout << "Condition Satisfied for " << a[i] << " and " << a[j] << endl;
                for (int k = j; k < i; k++)
                {
                    if ((a[i] % a[k] == 0 || a[i] < a[k]) && (a[k] % a[i] == 0 || a[k] < a[i]))
                    {
                        cout << "Current elements: " << a[i] << " " << a[k] << endl;
                        temp.insert(a[i]);
                        temp.insert(a[k]);
                        // cout << temp.size();
                        if (temp.size() > result.size())
                        {
                            result.clear();
                            copy(temp.begin(), temp.end(), back_inserter(result));
                        }
                    }
                    else
                    {
                        temp.clear();
                    }
                }
            }
            else
            {
                temp.clear();
            }
        }
    }

    if (result.size() == 0)
    {
        result.push_back(a[0]);
    }

    return result;
}

int main()
{
    vector<int> v = {1, 2, 3}, result;
    result = largestDivisibleSubset(v);
    for (auto x : result)
        cout << x << "\t";
}