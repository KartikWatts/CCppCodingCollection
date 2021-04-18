#include <iostream>

using namespace std;

void backTrack(int x, int y, int n, int maze[][20], int path[][20])
{
    // cout << "Currently at position (" << x << ", " << y << ")\n";
    // cout << "Global Points: (" << gX << ", " << gY << ")\n";
    if (maze[x][y] == 1)
    {
        if (x == n - 1 && y == n - 1)
        {
            path[x][y] = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    cout << path[i][j] << " ";
                }
            }
            cout << endl;
            path[x][y] = 0;
            return;
        }
        if (x >= n || x < 0 || y >= n || y < 0 || maze[x][y] == 0 || path[x][y] == 1)
        {
            return;
        }
        path[x][y] = 1;
        // cout << "Looking for position (" << x - 1 << ", " << y << ")\t Value: " << maze[x - 1][y] << endl;
        backTrack(x - 1, y, n, maze, path);
        // cout << "Looking for position (" << x + 1 << ", " << y << ")\t Value: " << maze[x + 1][y] << endl;
        backTrack(x + 1, y, n, maze, path);
        // cout << "Looking for position (" << x << ", " << y - 1 << ")\t Value: " << maze[x][y - 1] << endl;
        backTrack(x, y - 1, n, maze, path);
        // cout << "Looking for position (" << x << ", " << y + 1 << ")\t Value: " << maze[x][y + 1] << endl;
        backTrack(x, y + 1, n, maze, path);

        if (path[x][y] == 1)
            path[x][y] = 0;
    }
}

void ratInAMaze(int maze[][20], int n)
{
    int path[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            path[i][j] = 0;
        }
    }

    backTrack(0, 0, n, maze, path);
}

int main()
{
    int n;
    cin >> n;
    int p[20][20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> p[i][j];
        }
    }
    ratInAMaze(p, n);
}