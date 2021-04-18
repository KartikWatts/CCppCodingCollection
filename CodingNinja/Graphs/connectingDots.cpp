#include <bits/stdc++.h>
using namespace std;
#define MAXN 51

vector<pair<int, int>> tempVisitedNodes;
int length;

bool checkPattern(char c, char Graph[][MAXN], int N, int M, bool **visited, int rep, int x, int y, int startX, int startY)
{
    char nextC = c;
    int xArr[] = {0, 0, 1, 1, 1, -1, -1, -1};
    int yArr[] = {1, -1, 0, 1, -1, 0, 1, -1};

    for (int i = 0; i < 8; i++)
    {
        if (x + xArr[i] >= 0 && x + xArr[i] < N && y + yArr[i] >= 0 && y + yArr[i] < M)
        {
            if (x + xArr[i] == startX && y + yArr[i] == startY && length >= 4)
            {
                return true;
            }
            if (Graph[x + xArr[i]][y + yArr[i]] == nextC && visited[x + xArr[i]][y + yArr[i]] == false)
            {
                visited[x + xArr[i]][y + yArr[i]] = true;
                length++;
                tempVisitedNodes.push_back({x + xArr[i], y + yArr[i]});
                if (checkPattern(nextC, Graph, N, M, visited, rep, x + xArr[i], y + yArr[i], startX, startY))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int solve(char board[][MAXN], int N, int M)
{
    bool **visited = new bool *[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = new bool[M];
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            tempVisitedNodes.clear();
            length = 0;
            int startX = i, startY = j;
            visited[i][j] = true;
            if (checkPattern(board[i][j], board, N, M, visited, 0, i, j, startX, startY))
            {
                return 1;
            }
            for (auto it : tempVisitedNodes)
            {
                visited[it.first][it.second] = true;
            }
        }
    }
    return 0;
}

int main()
{
    int N, M, i;
    char board[MAXN][MAXN];
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        cin >> board[i];
    }
    cout << solve(board, N, M) << endl;
}