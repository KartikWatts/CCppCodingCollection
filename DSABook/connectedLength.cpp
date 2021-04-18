#include <iostream>

using namespace std;
#define len 5

//SOME PROBLEM CURRENTLY, NEED TO BE FIGURED OUT

int getSpread(int a[][len], int x, int y, bool processed[][len])
{
    int length = 0;
    if (x >= len || x < 0 || y < 0 || y >= len)
    {
        return length;
    }

    if (a[x][y] == 1 && processed[x][y] == false)
    {
        length++;
    }
    processed[x][y] = true;

    //REQUIRED A LOOP HERE INSTEAD.......

    length += getSpread(a, x + 1, y, processed);
    length += getSpread(a, x - 1, y, processed);
    length += getSpread(a, x, y + 1, processed);
    length += getSpread(a, x, y - 1, processed);
}

int main()
{
    int a[len][len] = {{1, 1, 0, 0, 0}, {0, 1, 1, 0, 0}, {0, 0, 1, 0, 1}, {1, 0, 0, 0, 1}, {0, 1, 0, 1, 1}};
    bool processed[len][len];
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            cout << a[i][j] << " ";
            processed[i][j] = false;
        }
        cout << endl;
    }
    int max = 0;
    int length = getSpread(a, 0, 0, processed);
    if (length > max)
    {
        max = length;
    }
}