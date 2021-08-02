#include <bits/stdc++.h>
using namespace std;

string str;
void dfs(vector<vector<int>> &grid, int r, int c, vector<vector<bool>> &vis)
{
    if (r < 0 || c < 0 || r == grid.size() || c == grid[0].size() || grid[r][c] == '0' || vis[r][c] == true)
    {
        str += "z";
        return;
    }
    vis[r][c] = true;
    str += "t";
    dfs(grid, r - 1, c, vis);
    str += "r";
    dfs(grid, r, c + 1, vis);
    str += "d";
    dfs(grid, r + 1, c, vis);
    str += "l";
    dfs(grid, r, c - 1, vis);
}

int countDisIslands(vector<vector<int>> grid)
{
    int m = grid.size(), n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    unordered_set<string> s;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vis[i][j] && grid[i][j] == '1')
            {
                str = "";
                dfs(grid, i, j, vis);
                s.insert(str);
            }
        }
    }
    return s.size();
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
            char ch;
            cin >> ch;
            grid[i][j] = (int)(ch);
        }
    }

    cout << countDisIslands(grid);
    return 0;
}