#include "bits/stdc++.h"
using namespace std;

int ans = INT_MIN;

void dfs(vector<vector<int>> &mat, int sr, int sc, int *area)
{
    if (sr < 0 || sc < 0 || sr == mat.size() || sc == mat[0].size() || mat[sr][sc] == 0)
    {
        return;
    }
    *area = (*area) + mat[sr][sc];
    mat[sr][sc] = 0;
    dfs(mat, sr - 1, sc, area);
    dfs(mat, sr, sc + 1, area);
    dfs(mat, sr + 1, sc, area);
    dfs(mat, sr, sc - 1, area);
}

void goldmine(vector<vector<int>> &mat, int m, int n)
{
    //vector<vector<bool>> vis(n,vector<bool>(m,false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != 0)
            {
                int area = 0;
                dfs(mat, i, j, &area);
                ans = max(ans, area);
            }
        }
    }
    cout << ans << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> mat(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }

    goldmine(mat, m, n);
}