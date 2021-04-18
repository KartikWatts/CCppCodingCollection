#include <bits/stdc++.h>
using namespace std;
#define MAXN 55
#define NMAX 55

vector<pair<int, int>> tempVisitedNodes;
int length;

bool checkPattern(char c, char Graph[][NMAX], int N, int M, bool **visited, int rep, int x, int y)
{
    char nextC = c;
    int xArr[] = {0, 0, 1, 1, 1, -1, -1, -1};
    int yArr[] = {1, -1, 0, 1, -1, 0, 1, -1};

    for (int i = 0; i < 8; i++)
    {
        if (x + xArr[i] >= 0 && x + xArr[i] < N && y + yArr[i] >= 0 && y + yArr[i] < M)
        {
            if (Graph[x + xArr[i]][y + yArr[i]] == nextC && visited[x + xArr[i]][y + yArr[i]] == false)
            {
                visited[x + xArr[i]][y + yArr[i]] = true;
                length++;
                tempVisitedNodes.push_back({x + xArr[i], y + yArr[i]});
                if (checkPattern(nextC, Graph, N, M, visited, rep, x + xArr[i], y + yArr[i]))
                {
                    return true;
                }
            }
        }
    }
    return true;
}

int solve2(char board[][NMAX], int N, int M)
{
    int maxLenght = 0;
    bool **visited = new bool *[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = new bool[M];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == '1')
            {
                tempVisitedNodes.clear();
                length = 1;
                visited[i][j] = true;
                if (checkPattern(board[i][j], board, N, M, visited, 0, i, j))
                {
                    if (length > maxLenght)
                    {
                        maxLenght = length;
                    }
                }
                for (auto it : tempVisitedNodes)
                {
                    visited[it.first][it.second] = true;
                }
            }
        }
    }
    return maxLenght;
}

int solve(int n, char cake[NMAX][NMAX])
{
    return solve2(cake, n, n);
}

int main()
{
    int N, M, i;
    char board[MAXN][MAXN];
    cin >> N;
    for (i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    cout << solve(N, board) << endl;
}