#include <bits/stdc++.h>
using namespace std;
#define MAXN 102

char getNextChar(char c, int rep)
{
    switch (c)
    {
    case 'C':
        return 'O';
        break;
    case 'O':
        return 'D';
        break;
    case 'D':
        return 'I';
        break;
    case 'I':
        return 'N';
        break;
    case 'N':
        if (rep == 0)
        {
            return 'G';
        }
        if (rep == 1)
        {
            return 'I';
        }
        if (rep == 2)
        {
            return 'J';
        }
        break;
    case 'G':
        return 'N';
        break;
    case 'J':
        return 'A';
        break;
    default:
        return 'C';
        break;
    }
    return 'X';
}

bool checkPattern(char c, char Graph[][MAXN], int N, int M, bool **visited, int rep, int x, int y)
{
    char nextC = getNextChar(c, rep);
    if (c == 'N')
    {
        rep++;
    }
    if (nextC == 'C')
    {
        return true;
    }
    int xArr[] = {0, 0, 1, 1, 1, -1, -1, -1};
    int yArr[] = {1, -1, 0, 1, -1, 0, 1, -1};

    for (int i = 0; i < 8; i++)
    {
        if (x + xArr[i] >= 0 && x + xArr[i] < N && y + yArr[i] >= 0 && y + yArr[i] < M)
        {
            if (Graph[x + xArr[i]][y + yArr[i]] == nextC && visited[x + xArr[i]][y + yArr[i]] == false)
            {
                // cout << "Found '" << nextC << "' at " << x + xArr[i] << " " << y + yArr[i] << endl;
                visited[x + xArr[i]][y + yArr[i]] = true;
                if (checkPattern(nextC, Graph, N, M, visited, rep, x + xArr[i], y + yArr[i]))
                {
                    return true;
                }
            }
        }
    }
    return false;
}

int solve(char Graph[][MAXN], int N, int M)
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
            if (Graph[i][j] == 'C')
            {
                // cout << "\n\nFound 'C' at " << i << " " << j << endl;
                visited[i][j] = true;
                if (checkPattern('C', Graph, N, M, visited, 0, i, j))
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    int N, M, i;
    char Graph[MAXN][MAXN];
    cin >> N >> M;
    for (i = 0; i < N; i++)
    {
        cin >> Graph[i];
    }
    cout << solve(Graph, N, M) << endl;
}
