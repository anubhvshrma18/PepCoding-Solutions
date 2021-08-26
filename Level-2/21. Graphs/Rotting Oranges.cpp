#include <bits/stdc++.h>
using namespace std;

int countIslands(vector<vector<int>> grid)
{
    int fo = 0, m = grid.size(), n = grid[0].size();
    queue<pair<int, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
            {
                grid[i][j] = 0;
                q.push({i, j});
            }
            else if (grid[i][j] == 1)
            {
                fo++;
            }
        }
    }
    int level = 0;
    if (fo == 0)
    {
        return 0;
    }
    while (!q.empty())
    {
        int size = q.size();
        if (fo == 0)
        {
            return level - 1;
        }
        while (size--)
        {
            // remove
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first, j = p.second;

            if (grid[i][j] == 2)
            {
                continue;
            }

            if (grid[i][j] == 1)
            {
                fo--;
            }
            //mark
            grid[i][j] = 2;
            //add neighbour

            if (i - 1 >= 0 && grid[i - 1][j] == 1)
            {
                q.push({i - 1, j});
            }

            if (j - 1 >= 0 && grid[i][j - 1] == 1)
            {
                q.push({i, j - 1});
            }

            if (j + 1 < n && grid[i][j + 1] == 1)
            {
                q.push({i, j + 1});
            }

            if (i + 1 < m && grid[i + 1][j] == 1)
            {
                q.push({i + 1, j});
            }
        }
        level++;
    }
    return (fo == 0) ? level - 1 : -1;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    cout << countIslands(grid);
    return 0;
}