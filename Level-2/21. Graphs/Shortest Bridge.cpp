#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &grid, int r, int c, queue<pair<int, int>> &q)
{
    if (r < 0 || c < 0 || r == grid.size() || c == grid[0].size() || grid[r][c] == 0 || grid[r][c] == -1)
    {
        return;
    }
    // vis[r][c]=true;
    grid[r][c] = -1;
    q.push({r, c});
    dfs(grid, r - 1, c, q);
    dfs(grid, r, c + 1, q);
    dfs(grid, r + 1, c, q);
    dfs(grid, r, c - 1, q);
}

int shortestBridge(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    queue<pair<int, int>> q;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                dfs(grid, i, j, q);
                flag = 0;
                break;
            }
        }

        if (flag == 0)
        {
            break;
        }
    }

    // cout << q.size() << endl;

    int lev = 0;
    vector<vector<int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    while (!q.empty())
    {
        int size = q.size();

        while (size--)
        {
            pair<int, int> p = q.front();
            q.pop();

            int ri = p.first, rj = p.second;

            for (int k = 0; k < 4; k++)
            {
                int r = ri + dir[k][0];
                int c = rj + dir[k][1];

                if (r >= 0 && r < n && c >= 0 && c < n && grid[r][c] != -1)
                {

                    if (grid[r][c] == 1)
                    {
                        return lev;
                    }
                    else
                    {
                        grid[r][c] = -1;
                        q.push({r, c});
                    }
                }
            }
        }

        lev++;
    }

    return lev;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << shortestBridge(grid) << endl;
    return 0;
}
