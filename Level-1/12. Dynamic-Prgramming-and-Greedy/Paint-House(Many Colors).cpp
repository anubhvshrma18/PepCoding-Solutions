#include <bits/stdc++.h>
using namespace std;

int minCost(vector<vector<int>> &arr, int n, int c)
{
    int dp[n][c];
    for (int j = 0; j < c; j++)
    {
        dp[0][j] = arr[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < c; j++)
        {
            int mn = INT_MAX;
            for (int k = 0; k < c; k++)
            {
                if (k != j)
                {
                    int ans = dp[i - 1][k];
                    mn = min(ans, mn);
                }
            }
            dp[i][j] = mn + arr[i][j];
        }
    }
    int mincost = INT_MAX;
    for (int j = 0; j < c; j++)
    {
        int ans = dp[n - 1][j];
        mincost = min(mincost, ans);
    }
    return mincost;
}

int main(int argc, char **argv)
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> costs(n, vector<int>(k));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            cin >> costs[i][j];
        }
    }

    cout << minCost(costs, n, k) << endl;
}