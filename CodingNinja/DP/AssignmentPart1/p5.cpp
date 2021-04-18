// (MAY HAVE TIME COMPLEXITY EXCEED)
#include <iostream>

using namespace std;

int getMin(int *score, int n)
{
    int *res = new int[n];
    int *incArr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
    }
    res[0] = 1;
    incArr[0] = 1;
    int maxArr = score[0], sizeArr = 0;

    for (int i = 1; i < n; i++)
    {
        // cout << "score[" << i - 1 << "] was: " << score[i - 1] << "\tscore[" << i << "] is: " << score[i] << endl;
        if (score[i] < score[i - 1])
        {
            res[i] = 1;
            sizeArr++;
            incArr[sizeArr] = res[i];
            if (res[i - 1] == 1)
            {
                for (int j = 0; j < sizeArr; j++)
                {
                    incArr[j]++;
                    res[i - (j + 1)]++;
                }
            }
        }
        else
        {
            if (score[i] != score[i - 1])
                res[i] = res[i - 1] + 1;
            else
            {
                res[i] = 1;
            }
            sizeArr = 0;
            maxArr = score[i];
            incArr[sizeArr] = res[i];
        }
        // cout << "res[" << i << "]: " << res[i] << endl;
    }
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        result += res[i];
    }

    delete[] res, incArr;
    return result;
}

int main()
{
    int n;
    cin >> n;
    int *score = new int[n];

    cout << getMin(score, n);

    delete[] score;
}